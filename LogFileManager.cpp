#include "LogFileManager.h"

LogFileManager::LogFileManager(string filePath)
    : filePath{filePath}, streamInUse{false}
{
    stream.open(filePath, ios_base::in | ios_base::out | ios_base::app);

}

fstream &LogFileManager::awaitPermissionToAccess()
{
    QMutexLocker locker{&lock};
    while(streamInUse)
        waitingList.wait(&lock);
    streamInUse = true;
    return stream;
}

void LogFileManager::moveOn()
{
    QMutexLocker locker{&lock};
    streamInUse = false;
    waitingList.wakeOne();
}

LogFileManager::~LogFileManager()
{
    stream.close();
}
