#include "ProcessorThread.h"

ProcessorThread::ProcessorThread(ProcessThresholds *thresholds, WarningSignaller *signaller, StartStopper *startStopper, CurrentRecord *currentRecord) : thresholds(thresholds),
    signaller(signaller),
    startStopper(startStopper),
    currentRecord(currentRecord)
{}

void ProcessorThread::run(){
    while(true){
        startStopper->awaitPermissionToStart();

        float* bounds = thresholds->getThresholds();
        float* currentValues = currentRecord->getReadings();

        bool tempWarning{(currentValues[0] < bounds[0]) || (currentValues[0] > bounds[3])};
        bool distWarning{(currentValues[1] < bounds[1]) || (currentValues[1] > bounds[4])};
        bool smokeWarning{(currentValues[2] < bounds[2]) || (currentValues[2] > bounds[5])};

        signaller->triggerWarnings(tempWarning,distWarning,smokeWarning);

        delete [] bounds;
        delete [] currentValues;
    }
}
