#ifndef LOGGERTHREAD_H
#define LOGGERTHREAD_H

#include <QThread>
#include <CurrentRecord.h>
#include <StartStopper.h>
#include <LogFileManager.h>

class LoggerThread : public QThread
{
private:
    CurrentRecord* currentRecord;
    StartStopper* startStopper;
    LogFileManager* fileManager;
public:
    LoggerThread(CurrentRecord *currentRecord, StartStopper *startStopper, LogFileManager *fileManager);
    void run();

};

#endif // LOGGERTHREAD_H
