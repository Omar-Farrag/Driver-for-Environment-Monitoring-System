#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <StartStopper.h>
#include <CurrentRecord.h>
#include <ProcessThresholds.h>
#include <LogFileManager.h>
#include <GUIDelegateThread.h>
#include <ui_mainwindow.h>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(StartStopper *startStopper, CurrentRecord *currentRecord, ProcessThresholds *thresholds, LogFileManager *fileManager,GUIDelegateThread* valueRetriever,QWidget *parent = nullptr);
    void wait();
    ~MainWindow();


private slots:
    void on_startBtn_clicked();
    void on_stopBtn_clicked();
    void on_submitThresholdsBtn_clicked();
    void on_plotTempBtn_clicked();
    void on_plotDistBtn_clicked();
    void on_plotSmokeBtn_clicked();
    void updateCurrentReadings(float currentTemp,float currentDistance,float currentSmoke);
    void updateWarningDisplay(bool tempWarning, bool distWarning, bool smokeWarning);

private:
    Ui::MainWindow *ui;
    StartStopper* startStopper;
    CurrentRecord* currentRecord;
    ProcessThresholds* thresholds;
    LogFileManager* fileManager;
    GUIDelegateThread* delegate;

};
#endif // MAINWINDOW_H
