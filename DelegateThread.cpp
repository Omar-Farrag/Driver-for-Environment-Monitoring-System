#include "DelegateThread.h"

GUIDelegateThread::GUIDelegateThread(MainWindow* window, StartStopper *startStopper, CurrentRecord *currentRecord)
    : window{window},startStopper{startStopper},currentRecord{currentRecord}
{}

void GUIDelegateThread::run(){
    startStopper->awaitPermissionToStart();

    float* values = currentRecord->getReadings();
    window->updateCurrentReadings(values[0],values[1],values[2]);

    delete[] values;

}
