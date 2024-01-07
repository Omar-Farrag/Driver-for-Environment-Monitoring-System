#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(StartStopper *startStopper, CurrentRecord *currentRecord, ProcessThresholds *thresholds, LogFileManager *fileManager, GUIDelegateThread* delegate,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      startStopper(startStopper),
      currentRecord(currentRecord),
      thresholds(thresholds),
      fileManager(fileManager),
      delegate{delegate}
{
    ui->setupUi(this);
    ui->currentDistTxt->setOverwriteMode(true);
    ui->currentTempTxt->setOverwriteMode(true);
    ui->currentSmokeTxt->setOverwriteMode(true);

    connect(delegate, SIGNAL(updateValuesSignal(float, float, float)),
            this, SLOT(updateCurrentReadings(float, float, float)),
            Qt::QueuedConnection);

    connect(delegate, SIGNAL(warningSignal(bool,bool,bool)),
            this, SLOT(updateWarningDisplay(bool,bool,bool)),
            Qt::QueuedConnection);

    delegate->start();

}
void MainWindow::updateWarningDisplay(bool tempWarning, bool distWarning, bool smokeWarning){
    QPalette blackPalette;
    blackPalette.setColor(QPalette::WindowText, Qt::black);

    QPalette redPalette;
    redPalette.setColor(QPalette::WindowText, Qt::red);

    ui->tempLabel->setPalette(tempWarning ? redPalette : blackPalette);
    ui->distLabel->setPalette(distWarning ? redPalette : blackPalette);
    ui->smokeLabel->setPalette(smokeWarning ? redPalette : blackPalette);
}
void MainWindow::updateCurrentReadings(float currentTemp,float currentDistance,float currentSmoke){
    ui->currentTempTxt->setText(QString::number(currentTemp));
    ui->currentDistTxt->setText(QString::number(currentDistance));
    ui->currentSmokeTxt->setText(QString::number(currentSmoke));
}
void MainWindow::wait(){
    delegate->wait();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
    startStopper->permitStart();
}


void MainWindow::on_stopBtn_clicked()
{
    startStopper->forceStop();
}


void MainWindow::on_submitThresholdsBtn_clicked()
{
    string minTempStr = ui->minTempTxt->toPlainText().toStdString();
    string maxTempStr = ui->maxTempTxt->toPlainText().toStdString();
    string minDistStr = ui->minDistTxt->toPlainText().toStdString();
    string maxDistStr = ui->maxDistTxt->toPlainText().toStdString();
    string minSmokeStr = ui->minSmokeTxt->toPlainText().toStdString();
    string maxSmokeStr = ui->maxSmokeTxt->toPlainText().toStdString();

    float* currentThresholds = thresholds->getThresholds();

    currentThresholds[0] = !minTempStr.empty() ? stof(minTempStr) : currentThresholds[0];
    currentThresholds[1] = !minDistStr.empty() ? stof(minDistStr) : currentThresholds[1];
    currentThresholds[2] = !minSmokeStr.empty() ? stof(minSmokeStr) : currentThresholds[2];
    currentThresholds[3] = !maxTempStr.empty() ? stof(maxTempStr) : currentThresholds[3];
    currentThresholds[4] = !maxDistStr.empty() ? stof(maxDistStr) : currentThresholds[4];
    currentThresholds[5] = !maxSmokeStr.empty() ? stof(maxSmokeStr) : currentThresholds[5];

    thresholds->updateThresholds(currentThresholds);

}


void MainWindow::on_plotTempBtn_clicked()
{
   fileManager->awaitPermissionToAccess();
   string command = "gnuplot -persist  -c plotScript.gp log.csv 1 2 'Temperature (C)' 'Temperature VS Time'";
   FILE* f=  popen(command.c_str(),"w");
   pclose(f);
   fileManager->moveOn();
}


void MainWindow::on_plotDistBtn_clicked()
{
    fileManager->awaitPermissionToAccess();
    string command = "gnuplot -persist  -c plotScript.gp log.csv 1 3 'Distance (cm)' 'Distance VS Time'";
    FILE* f=  popen(command.c_str(),"w");
    pclose(f);
    fileManager->moveOn();
}


void MainWindow::on_plotSmokeBtn_clicked()
{
    fileManager->awaitPermissionToAccess();
    string command = "gnuplot -persist  -c plotScript.gp log.csv 1 4 'Smoke (ppm)' 'Smoke VS Time'";
    FILE* f=  popen(command.c_str(),"w");
    pclose(f);
    fileManager->moveOn();
}



