#include "CurrentRecord.h"
#include<iostream>
CurrentRecord::CurrentRecord()
    : tempReading{10},distReading{10},smokeReading{10}
{}

void CurrentRecord::updateReadings(float newTempReading, float newDistReading, float newSmokeReading)
{
    QMutexLocker locker{&lock};
    tempReading = (newTempReading == -1 ? tempReading : newTempReading);
    distReading = (newDistReading == -1 ? distReading : newDistReading);
    smokeReading = (newSmokeReading == -1 ? smokeReading : newSmokeReading);
//    std::cout<<tempReading<<","<<distReading<<","<<smokeReading<<std::endl;
}

//Delete pointer when called
float *CurrentRecord::getReadings()
{
    QMutexLocker locker{&lock};
    return new float[]{tempReading,distReading,smokeReading};
}
