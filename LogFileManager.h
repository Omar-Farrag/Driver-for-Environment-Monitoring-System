#ifndef LOGFILEMANAGER_H
#define LOGFILEMANAGER_H

#include <string>
#include <fstream>
#include <QMutex>
#include <QWaitCondition>

using namespace std;
class LogFileManager
{
private:
    string filePath;
    fstream stream;
    bool streamInUse;
    QMutex lock;
    QWaitCondition waitingList;
public:
    LogFileManager(string filePath);
    fstream& awaitPermissionToAccess();
    void moveOn();
    ~LogFileManager();
};

#endif // LOGFILEMANAGER_H
