#ifndef WARNINGSIGNALLER_H
#define WARNINGSIGNALLER_H

#include <QSemaphore>
#include <qmutex.h>



class WarningSignaller
{
private:
    bool tempWarning, distWarning, smokeWarning;
    QMutex lock;
    QSemaphore beacon;
public:
    WarningSignaller();
    void triggerWarnings(bool newTempState,bool newDistState, bool newSmokeState);
    bool* getWarnings();
};

#endif // WARNINGSIGNALLER_H
