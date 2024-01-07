#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <CurrentRecord.h>
#include<LogFileManager.h>
#include<ProcessThresholds.h>
#include<StartStopper.h>
#include<WarningSignaller.h>
#include<SerialDelegate.h>
#include<LoggerThread.h>
#include<ProcessorThread.h>
#include <chrono>
#include <iomanip>


int main(int argc, char *argv[])
{
    // Shared Resources
    CurrentRecord record;
    LogFileManager fileManager{"log.csv"};
    ProcessThresholds thresholds;
    StartStopper startStopper;
    WarningSignaller signaller;

    // Threads
    SerialDelegate serialDelegate{"/dev/ttyACM0",&startStopper,&record,&signaller};
    LoggerThread logger{&record,&startStopper,&fileManager};
    ProcessorThread processor{&thresholds,&signaller,&startStopper,&record};
    GUIDelegateThread delegate{&startStopper,&record,&signaller};

    // GUI Window
    QApplication a(argc, argv);
    MainWindow w{&startStopper,&record,&thresholds,&fileManager,&delegate,nullptr};

    delegate.setParentWindow(&w);
    w.show();


    // Thread Startup
    serialDelegate.start();
    logger.start();
    processor.start();

    /*
    // Waiting for Threads
    serialDelegate.wait();
    logger.wait();
    processor.wait();
//    w.wait();
    */
    return a.exec();
}
