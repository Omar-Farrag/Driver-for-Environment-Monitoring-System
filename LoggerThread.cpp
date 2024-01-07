#include "LoggerThread.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <iomanip>
LoggerThread::LoggerThread(CurrentRecord *currentRecord, StartStopper *startStopper, LogFileManager *fileManager) : currentRecord(currentRecord),
    startStopper(startStopper),
    fileManager(fileManager)
{}

void LoggerThread::run(){
    int numReadings = 0;
    usleep(500000);
    while(true){
        startStopper->awaitPermissionToStart();

        float *readings = currentRecord->getReadings();
        fstream& stream = fileManager->awaitPermissionToAccess();

        // Obtain current time in "%Y-%m-%d %H:%M:%S"
        auto currentTimePoint = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);
        std::tm* timeInfo = std::localtime(&currentTime);
        _Put_time<char> timestamp = std::put_time(timeInfo, "%Y-%m-%d %H:%M:%S");

        stream.clear();
        stream << timestamp<<","<<readings[0]<<","<<readings[1]<<","<<readings[2]<<"\n";
        numReadings = numReadings%20 + 1;
        if(numReadings == 20)
            stream.flush();

        fileManager->moveOn();

        usleep(100000);
//        stop = true;
        delete[] readings;
    }
}
