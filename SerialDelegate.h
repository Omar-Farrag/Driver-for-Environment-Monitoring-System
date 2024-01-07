#ifndef SERIALDELEGATE_H
#define SERIALDELEGATE_H

#include<fstream>
#include<StartStopper.h>
#include<CurrentRecord.h>
#include<WarningSignaller.h>
#include<QThread>
#include<fstream>

using namespace std;


class SerialDelegate : public QThread
{
private:
    string filePath;
    fstream stream;
    StartStopper*startStopper;
    CurrentRecord *currentRecord;
    WarningSignaller *signaller;
public:
    SerialDelegate(const string &filePath, StartStopper *startStopper, CurrentRecord *currentRecord, WarningSignaller *signaller);
    void run();
};

#endif // SERIALDELEGATE_H
