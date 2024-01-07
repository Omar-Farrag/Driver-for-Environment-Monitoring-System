#ifndef CURRENTRECORD_H
#define CURRENTRECORD_H

#include <QMutex>
#include <QObject>

class CurrentRecord
{
private:
    float tempReading, distReading, smokeReading;
    QMutex lock;
public:
    CurrentRecord();
    void updateReadings(float tempReading,float distReading,float smokeReading);
    float* getReadings();

};

#endif // CURRENTRECORD_H
