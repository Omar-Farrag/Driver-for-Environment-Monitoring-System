#include "ProcessThresholds.h"
#include<iostream>
ProcessThresholds::ProcessThresholds()
    : minTemp{-150},minDist{-150}, minSmoke{-150},
      maxTemp{150},maxDist{150},maxSmoke{150}
{}

void ProcessThresholds::updateThresholds(float *newThresholds)
{
    QMutexLocker locker{&lock};
    minTemp = newThresholds[0];
    minDist = newThresholds[1];
    minSmoke = newThresholds[2];
    maxTemp = newThresholds[3];
    maxDist = newThresholds[4];
    maxSmoke = newThresholds[5];
}

//Remember to delete pointer when called
float *ProcessThresholds::getThresholds()
{
    QMutexLocker locker{&lock};
    return new float[]{minTemp,minDist,minSmoke,maxTemp,maxDist,maxSmoke};
}
