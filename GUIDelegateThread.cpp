#include "GUIDelegateThread.h"
#include <mainwindow.h>
#include <unistd.h>

GUIDelegateThread::GUIDelegateThread(StartStopper *startStopper, CurrentRecord *currentRecord, WarningSignaller *signaller)
    :startStopper{startStopper},currentRecord{currentRecord}, signaller{signaller}
{

}
void GUIDelegateThread::setParentWindow(MainWindow* window){
    this->window = window;
}
void GUIDelegateThread::run()
{
    while(true){

    startStopper->awaitPermissionToStart();

    float* values = currentRecord->getReadings();
    emit updateValuesSignal(values[0],values[1],values[2]);

    bool* warnings = signaller->getWarnings();
    if(warnings[0] == true)
        emit warningSignal(warnings[1],warnings[2],warnings[3]);



    usleep(50000);
    delete[] values;
    delete[] warnings;
   }
}
