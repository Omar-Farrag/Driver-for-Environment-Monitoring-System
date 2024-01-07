#ifndef STARTSTOPPER_H
#define STARTSTOPPER_H

#include <QMutex>
#include <QWaitCondition>



class StartStopper
{
private:
    QMutex lock;
    bool block;
    QWaitCondition waitingList;
public:
    StartStopper();
    void awaitPermissionToStart();
    void permitStart();
    void forceStop();
};

#endif // STARTSTOPPER_H
