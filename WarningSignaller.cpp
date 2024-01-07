#include "WarningSignaller.h"
#include <iostream>
WarningSignaller::WarningSignaller() : tempWarning{false},distWarning{false},smokeWarning{false}
{}

void WarningSignaller::triggerWarnings(bool newTempState,bool newDistState, bool newSmokeState)
{
    QMutexLocker locker{&lock};

    bool oldTempState = tempWarning;
    bool oldDistState = distWarning;
    bool oldSmokeState = smokeWarning;


    tempWarning = newTempState;
    distWarning = newDistState;
    smokeWarning = newSmokeState;

    if(oldTempState != newTempState
            || oldDistState != newDistState
            || oldSmokeState != newSmokeState){

        beacon.release();
    }
}


// remember to delete pointer whenever called
bool* WarningSignaller::getWarnings()
{
    QMutexLocker locker{&lock};
    //updates[0] indicates whether there are updates are not
    bool* updates = new bool[4]{false,tempWarning,distWarning,smokeWarning};
    if(beacon.tryAcquire()){
        updates[0] = true;
//        std::cout<<"There is Warning"<<std::endl;
    }
    return updates;
}
