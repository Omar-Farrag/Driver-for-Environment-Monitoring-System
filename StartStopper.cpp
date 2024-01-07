#include "StartStopper.h"

StartStopper::StartStopper() : block{false}
{}

void StartStopper::awaitPermissionToStart()
{
    QMutexLocker locker{&lock};
    while(block)
        waitingList.wait(&lock);
}

void StartStopper::permitStart()
{
    QMutexLocker locker{&lock};
    block = false;
    waitingList.wakeAll();
}

void StartStopper::forceStop()
{
    QMutexLocker locker{&lock};
    block = true;
}
