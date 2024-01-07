#ifndef DELEGATETHREAD_H
#define DELEGATETHREAD_H

#include<QThread>
#include<mainwindow.h>

class GUIDelegateThread : public QThread
{
private:
    MainWindow* window;
    StartStopper *startStopper;
    CurrentRecord *currentRecord;
public:
    GUIDelegateThread(MainWindow* window, StartStopper *startStopper, CurrentRecord *currentRecord);
    void run();
};

#endif // DELEGATETHREAD_H
