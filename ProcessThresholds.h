#ifndef PROCESSTHRESHOLDS_H
#define PROCESSTHRESHOLDS_H

#include <QMutex>



class ProcessThresholds
{
private:
    float minTemp,minDist,minSmoke;
    float maxTemp,maxDist,maxSmoke;
    QMutex lock;
public:
    ProcessThresholds();
    void updateThresholds(float* newThresholds);
    float* getThresholds();
};

#endif // PROCESSTHRESHOLDS_H
