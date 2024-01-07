#ifndef PROCESSORTHREAD_H
#define PROCESSORTHREAD_H

#include <ProcessThresholds.h>
#include <WarningSignaller.h>
#include <StartStopper.h>
#include <CurrentRecord.h>
#include <QThread>

class ProcessorThread : public QThread
{
private:
    ProcessThresholds* thresholds;
    WarningSignaller* signaller;
    StartStopper* startStopper;
    CurrentRecord* currentRecord;
public:
    ProcessorThread(ProcessThresholds *thresholds, WarningSignaller *signaller, StartStopper *startStopper, CurrentRecord *currentRecord);
    void run();
};

#endif // PROCESSORTHREAD_H
