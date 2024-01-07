#ifndef GUIDELEGATETHREAD_H
#define GUIDELEGATETHREAD_H

#include <StartStopper.h>
#include <CurrentRecord.h>
#include <WarningSignaller.h>

class MainWindow;
#include <QThread>

class GUIDelegateThread : public QThread
{
    Q_OBJECT
private:
    MainWindow* window;
    StartStopper *startStopper;
    CurrentRecord *currentRecord;
    WarningSignaller *signaller;
public:
    GUIDelegateThread(StartStopper *startStopper, CurrentRecord *currentRecord, WarningSignaller* signaller);
    void setParentWindow(MainWindow* window);
    void run();

signals:
    void updateValuesSignal(float currentTemp, float currentDistance, float currentSmoke);
    void warningSignal(bool tempWarning, bool distWarning, bool smokeWarning);
};

#endif // GUIDELEGATETHREAD_H
