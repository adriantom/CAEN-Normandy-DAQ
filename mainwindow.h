#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

#include "daqthread.h"
#include <iostream>

#include "digitizer_configuration.h"
#include "trigger_configuration.h"
//#include "digitizer.cpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //std::ofstream myfile;
//    daqThread *dt;

public slots:
    void makeSignalPlot();

    void makeHistogramPlot();

    void SetAcquisitionSettings();

    void SetTriggerSettings();

private slots:

    void on_pushButton_Start_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_GetInfo_clicked();

    void on_pushButton_Clear_clicked();

    void on_actionExit_triggered();

    void on_pushButton_Calibrate_clicked();

    void on_pushButton_Reset_clicked();

    void on_actionDigitizer_configuration_triggered();

    void on_actionTrigger_configuration_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_clicked();

    void SignalLegend();

    void on_checkBox_SignalChannel0_clicked(bool checked);

    void on_checkBox_SignalChannel1_clicked(bool checked);

    void on_checkBox_SignalChannel2_clicked(bool checked);

    void on_checkBox_SignalChannel3_clicked(bool checked);

    void on_checkBox_SignalChannel4_clicked(bool checked);

    void on_checkBox_SignalChannel5_clicked(bool checked);

    void on_checkBox_SignalChannel6_clicked(bool checked);

    void on_checkBox_SignalChannel7_clicked(bool checked);

    void on_checkBox_HistogramChannel0_clicked(bool checked);

    void on_checkBox_HistogramChannel1_clicked(bool checked);

    void on_checkBox_HistogramChannel2_clicked(bool checked);

    void on_checkBox_HistogramChannel3_clicked(bool checked);

    void on_checkBox_HistogramChannel4_clicked(bool checked);

    void on_checkBox_HistogramChannel5_clicked(bool checked);

    void on_checkBox_HistogramChannel6_clicked(bool checked);

    void on_checkBox_HistogramChannel7_clicked(bool checked);

    void on_pushButton_ClearPlot_clicked();

    void on_pushButton_readTemp_clicked();

    void on_pushButton_calibrateDCO_clicked();

    void on_pushButton_restart_clicked();

    void on_pushButton_autoscale_clicked();

    void on_actionSave_As_triggered();

    void on_checkBox_logaritmicScale_clicked(bool checked);

    void on_timeEdit_timeChanged(const QTime &time);

public slots:

//    void makeHistogramPlot();


private:
    Ui::MainWindow *ui;

    QThread *thread;

    daqThread *daqthread;

    QThread *thread2;

    daqThread *daqthread2;

    Digitizer_Configuration *acqset;

    Trigger_Configuration *trigset;

    QTimer *timer;

    int czas;

};

#endif // MAINWINDOW_H
