#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitizer.cpp"
#include "digitizer_configuration.h"
#include "trigger_configuration.h"
#include "about.h"
#include <QtCore/QCoreApplication>
#include <QTimer>
#include <QEventLoop>
#include <algorithm>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->widget_SignalPlot->setInteraction(QCP::iRangeDrag, true);
    ui->widget_SignalPlot->setInteraction(QCP::iRangeZoom, true);

    ui->widget_HistogramPlot->setInteraction(QCP::iRangeDrag, true);
    ui->widget_HistogramPlot->setInteraction(QCP::iRangeZoom, true);


    ret = CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_USB, 0, 0, 0, &handle);
    if(ret == CAEN_DGTZ_Success)
    {
         ui->label_boardStatusAns->setText(QString::fromStdString("Board connected"));

        ret = CAEN_DGTZ_SetChannelEnableMask(handle,255);

        thread = new QThread();
        daqthread = new daqThread();

        thread2 = new QThread();
        daqthread2 = new daqThread();
        daqthread2->moveToThread(thread2);

        connect(daqthread2, SIGNAL(dataSheets()), this, SLOT(makeSignalPlot()));
        connect(daqthread2, SIGNAL(dataSheets()), this, SLOT(makeHistogramPlot()));
        connect(daqthread2, SIGNAL(acquisitionRequested()), thread2, SLOT(start()));
        connect(thread2, SIGNAL(started()), daqthread2, SLOT(startAcquisition()));
        connect(daqthread2, SIGNAL(acquisitionFinished()), thread2, SLOT(quit()), Qt::DirectConnection);

        acqset = new Digitizer_Configuration();
        trigset = new Trigger_Configuration();

        daqthread->moveToThread(thread);

        connect(daqthread, SIGNAL(dataSheets()), this, SLOT(makeSignalPlot()));
        connect(daqthread, SIGNAL(dataSheets()), this, SLOT(makeHistogramPlot()));
        connect(daqthread, SIGNAL(acquisitionRequested()), thread, SLOT(start()));
        connect(thread, SIGNAL(started()), daqthread, SLOT(startAcquisition()));
        connect(daqthread, SIGNAL(acquisitionFinished()), thread, SLOT(quit()), Qt::DirectConnection);

        // Connect set caen acquisition and trigger with OK button
     //   connect(acqset, SIGNAL(setDigiSettings()), this, SLOT(SetAcquisitionSettings()));
     //   connect(trigset, SIGNAL(setTrigSettings()), this, SLOT(SetTriggerSettings()));


    //    Digitizer_Congiguration();
        int returnGDC = 0;
        returnGDC = Get_Digitizer_Configuration();
        if(returnGDC != 0){
            ui->textBrowser_AppLogs->append("\nCant't get Digitizer configuration. Error code:   " + QString::number(returnGDC));
    //        ui->textBrowser_AppLogs->append(QString::number(returnGDC));
        }

        int returnGTC = 0;
        returnGTC = Get_Trigger_Configuration();
        if(returnGTC != 0){
            ui->textBrowser_AppLogs->append("\nCant't get Trigger configuration. Error code:   " + QString::number(returnGTC));
    //        ui->textBrowser_AppLogs->append(QString::number(returnGTC));
        }

    //    SignalLegend();
    }
    else
        ui->textBrowser_AppLogs->append("\nCant't comumnicate with digitizer board. Error code:   " + QString::number(ret));
}

MainWindow::~MainWindow()
{
    delete ui;

    daqthread->stopAcquisition();
    thread->wait();

    delete thread;
    delete daqthread;
}


//============ PLOTING DATA =================


static int ChannelsToPlotSignal[8] = {0,0,0,0,0,0,0,0};

static int ChannelsToPlotHistogram[8] = {0,0,0,0,0,0,0,0};



// ==== CONECTIONS ======

//QObject::connect(this, actionDigitizer_configuration_triggered(), Digitizer_Configuration, doubleSpinBox_PostTriggSize_valueChanged);

void MainWindow::SetAcquisitionSettings()
{
    Set_Digitizer_Configuration();
}

void MainWindow::SetTriggerSettings()
{
    Set_Trigger_Configuration();
}




//====================================================================================
// =================== BUTTONS =======================
//====================================================================================



void MainWindow::on_pushButton_Start_clicked()
{

//    ret = CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_USB, 0, 0, 0, &handle);
    if(ret != CAEN_DGTZ_Success)
    {
    ui->textBrowser_AppLogs->append("\nCan't open digitizer");

    }

    else
    {  //odkomentuj!
   //     Digitizer_Congiguration();
   //     timer->start(czas);
        ret = CAEN_DGTZ_SetChannelEnableMask(handle,255);

        ui->pushButton_Calibrate->setDisabled(true);
        ui->pushButton_Start->setDisabled(true);

        ui->textBrowser_AppLogs->append("\nDevice configuration has been started\n");
//        Set_Digitizer_Configuration();
//        Set_Trigger_Configuration();
        ui->textBrowser_AppLogs->append("\nDevice has been configured\n");

    //    Get_Digitizer_Configuration();
  //      Get_Trigger_Configuration();

        ui->textBrowser_AppLogs->append("\nStarting acquisition \n");

        ofstream file;
        if(fileFormat==1){
            file.open (filepath.toStdString()+".dat", ios_base::app);
        }
        if(fileFormat==0){
            file.open (filepath.toStdString()+".root", ios_base::app);
        }

        ui->label_boardStatusAns->setText(QString::fromStdString("Acquisition started"));

        daqthread->stopAcquisition();
        thread->wait();
        daqthread->startAcquisition(file);

        ui->textBrowser_AppLogs->append("\nAcquisition has been completed \n");

    }
}

void MainWindow::on_pushButton_Stop_clicked()
{
//    ret = CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_USB, 0, 0, 0, &handle);
    if(ret != CAEN_DGTZ_Success)
    {
      ui->textBrowser_AppLogs->append("\nCan't open digitizer");

//      ui->pushButton_Calibrate->setDisabled(false);
      ui->pushButton_Start->setDisabled(false);

    }
    else
    {
   //   timer->stop();
      ret = CAEN_DGTZ_SWStopAcquisition(handle);
      daqthread->stopAcquisition();
      //ret = CAEN_DGTZ_Reset(handle);


//      &file.close();

      ui->pushButton_Calibrate->setDisabled(false);
      ui->pushButton_Start->setDisabled(false);

//      ret = CAEN_DGTZ_FreeEvent(handle, (void**)&Evt);
//      ret = CAEN_DGTZ_FreeReadoutBuffer(&buffer);
//      ret = CAEN_DGTZ_CloseDigitizer(handle);

      ui->label_boardStatusAns->setText(QString::fromStdString("Acquisition finished"));
    }
}


void MainWindow::on_pushButton_GetInfo_clicked()
{
//    ret = CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_USB, 0, 0, 0, &handle);
    ret = CAEN_DGTZ_GetInfo(handle, &BoardInfo);
    if(ret != CAEN_DGTZ_Success)
    {
        ui->textBrowser_AppLogs->append("\nCant't comumnicate with digitizer board. Error code:   " + QString::number(ret));
    }
    else
    {
        ui->textBrowser_AppLogs->append("\nConnected to CAEN Digitizer Model " + QString::fromStdString(BoardInfo.ModelName) + " recognized as board " + QString::number(handle));
        ui->textBrowser_AppLogs->append("   \nBoard information: \n");
        PostTriggSize = percent;
        ui->textBrowser_AppLogs->append("       Channels " + QString::number(BoardInfo.Channels));
        ui->textBrowser_AppLogs->append("       Form Factor " + QString::number(BoardInfo.FormFactor));
        ui->textBrowser_AppLogs->append("       Family Code " + QString::number(BoardInfo.FamilyCode));
        ui->textBrowser_AppLogs->append("       ROC FPGA Release is " + QString::fromStdString(BoardInfo.ROC_FirmwareRel));
        ui->textBrowser_AppLogs->append("       AMC FPGA Release is " + QString::fromStdString(BoardInfo.AMC_FirmwareRel));
        ui->textBrowser_AppLogs->append("       Serial number " + QString::number(BoardInfo.SerialNumber));
        ui->textBrowser_AppLogs->append("       PCB Revision " + QString::number(BoardInfo.PCB_Revision));
        ui->textBrowser_AppLogs->append("       ADC Nbits " + QString::number(BoardInfo.ADC_NBits));
        ui->textBrowser_AppLogs->append("       Comm handle " + QString::number(BoardInfo.CommHandle));
        ui->textBrowser_AppLogs->append("       VMEH handle " + QString::number(BoardInfo.VMEHandle));
        ui->textBrowser_AppLogs->append("       License " + QString::fromStdString(BoardInfo.License));
    }
}



void MainWindow::on_pushButton_Clear_clicked()
{
    ui->textBrowser_AppLogs->clear();
}


void MainWindow::on_pushButton_Calibrate_clicked()
{
//    ret = CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_USB, 0, 0, 0, &handle);
    if(ret != CAEN_DGTZ_Success)
    {
      ui->textBrowser_AppLogs->append("\nProblem with digitizer. Error code:   " + QString::number(ret));
      //ui->textBrowser_AppLogs->append("Calibration error " + QString::fromStdString(ret));
    }
    else
    {
        ui->textBrowser_AppLogs->append("\nStarting calibration... \n");
        Calibration();
//        Calibrate_DC_Offset(handle,0,dc_file,&DCoffset);
        ui->textBrowser_AppLogs->append("Calibration finished \n");
    }
}

void MainWindow::on_pushButton_Reset_clicked()
{
//    ret = CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_USB, 0, 0, 0, &handle);
    if(ret != CAEN_DGTZ_Success)
    {
      ui->textBrowser_AppLogs->append("\nProblem with digitizer. Error code:   " + QString::number(ret));

    }
    else
    {
        Reset();

        ui->textBrowser_AppLogs->append("\nReset the Digitizer. All internal registers and states are restored to default values.\n");
    }
}


void MainWindow::on_pushButton_readTemp_clicked()
{
    uint32_t temp;
    int tempTab[8] = {0,0,0,0,0,0,0,0};
    ret = CAEN_DGTZ_ReadTemperature(handle, 0, &temp);
    if(ret == 0){
        for(int ch=0; ch<8; ch++){
            ret = CAEN_DGTZ_ReadTemperature(handle, ch, &temp);
            tempTab[ch] = (int)temp;
        }
        ui->label_temperatureAns->setText(QString::number(tempTab[0]) + "," + QString::number(tempTab[1]) + "," + QString::number(tempTab[2]) + "," + QString::number(tempTab[3]) + "," + QString::number(tempTab[4]) + "," + QString::number(tempTab[5]) + "," + QString::number(tempTab[6]) + "," + QString::number(tempTab[7]));
    }
    else
        ui->textBrowser_AppLogs->append("\nProblem with digitizer. Error code:   " + QString::number(ret));
}


void MainWindow::on_pushButton_calibrateDCO_clicked()
{
    if(ret != CAEN_DGTZ_Success)
    {
        ui->textBrowser_AppLogs->append("\nCan't open digitizer");
    }
    else
        Calibrate_DC_Offset(handle,0,dc_file,&DCoffset);
}

void MainWindow::on_pushButton_restart_clicked()
{
    ret = CAEN_DGTZ_FreeEvent(handle, (void**)&Evt);
    ret = CAEN_DGTZ_FreeReadoutBuffer(&buffer);
    ret = CAEN_DGTZ_CloseDigitizer(handle);
    ret = CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_USB, 0, 0, 0, &handle);
}




//====================================================================================
//================ FILE    =======================
//====================================================================================


void MainWindow::on_actionExit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionSave_As_triggered()
{
    SaveFile saveFile;

    saveFile.setModal(true);
    saveFile.exec();
}


void MainWindow::on_actionDigitizer_configuration_triggered()
{

    int returnGDC = 0;
    returnGDC = Get_Digitizer_Configuration();
    if(returnGDC != 0){
        ui->textBrowser_AppLogs->append("\nCant't get Digitizer configuration. Error code:   " + QString::number(returnGDC));
//        ui->textBrowser_AppLogs->append(QString::number(returnGDC));
    }

    Digitizer_Configuration DigConfig;

    DigConfig.setModal(true);
    DigConfig.exec();


    int returnSDC = 0;
    returnSDC = Set_Digitizer_Configuration();
    if(returnSDC != 0){
        ui->textBrowser_AppLogs->append("\nCant't get Digitizer configuration. Error code:   " + QString::number(returnSDC));
//        ui->textBrowser_AppLogs->append(QString::number(returnSDC));
    }

}

void MainWindow::on_actionTrigger_configuration_triggered()
{


    Trigger_Configuration TriggConfig;

    int returnGTC = 0;
    returnGTC = Get_Trigger_Configuration();
    if(returnGTC != 0){
        ui->textBrowser_AppLogs->append("\nCant't get Trigger configuration. Error code:");
        ui->textBrowser_AppLogs->append(QString::number(returnGTC));
    }

    TriggConfig.setModal(true);
    TriggConfig.exec();


    int returnSTC = 0;
    returnSTC = Set_Trigger_Configuration();
    if(returnSTC != 0){
        ui->textBrowser_AppLogs->append("\nCant't get Trigger configuration. Error code:");
        ui->textBrowser_AppLogs->append(QString::number(returnSTC));
    }

}


void MainWindow::on_actionAbout_triggered()
{

    About about;

    about.setModal(true);
    about.exec();
}




//====================================================================================
//====================================================================================



//====================================================================================
//================ SIGNAL PLOT ============================
//====================================================================================


void MainWindow::SignalLegend()
{
    ui->widget_SignalPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    ui->widget_SignalPlot->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
   ui->widget_SignalPlot->legend->setFont(legendFont);
    ui->widget_SignalPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    ui->widget_SignalPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
}

void MainWindow::makeSignalPlot()
{
    // Channel 0
    if(ChannelsToPlotSignal[0] == 1)
    {
        ui->widget_SignalPlot->addGraph();
        ui->widget_SignalPlot->graph(0)->setData(xaqh_ch0, yaqh_ch0);
        ui->widget_SignalPlot->graph(0)->setPen(QPen(QColor(255, 0, 0)));
        ui->widget_SignalPlot->graph(0)->setName("Channel 0");
    }

    // Channel 1
    if(ChannelsToPlotSignal[1] == 1)
    {
        ui->widget_SignalPlot->addGraph();
        ui->widget_SignalPlot->graph(1)->setData(xaqh_ch1, yaqh_ch1);
        ui->widget_SignalPlot->graph(1)->setPen(QPen(QColor(0, 0, 255)));
        ui->widget_SignalPlot->graph(1)->setName("Channel 1");
    }

    // Channel 2
    if(ChannelsToPlotSignal[2] == 1)
    {
        ui->widget_SignalPlot->addGraph();
        ui->widget_SignalPlot->graph(2)->setData(xaqh_ch2, yaqh_ch2);
        ui->widget_SignalPlot->graph(2)->setPen(QPen(QColor(0, 255, 0)));
        ui->widget_SignalPlot->graph(1)->setName("Channel 2");
    }

    // Channel 3
    if(ChannelsToPlotSignal[3] == 1)
    {
        ui->widget_SignalPlot->addGraph();
        ui->widget_SignalPlot->graph(3)->setData(xaqh_ch3, yaqh_ch3);
        ui->widget_SignalPlot->graph(3)->setPen(QPen(QColor(255, 155, 0)));
        ui->widget_SignalPlot->graph(1)->setName("Channel 3");
    }

    // Channel 4
    if(ChannelsToPlotSignal[4] == 1)
    {
        ui->widget_SignalPlot->addGraph();
        ui->widget_SignalPlot->graph(4)->setData(xaqh_ch4, yaqh_ch4);
        ui->widget_SignalPlot->graph(4)->setPen(QPen(QColor(255, 0, 255)));
        ui->widget_SignalPlot->graph(1)->setName("Channel 4");
    }

    // Channel 5
    if(ChannelsToPlotSignal[5] == 1)
    {
        ui->widget_SignalPlot->addGraph();
        ui->widget_SignalPlot->graph(5)->setData(xaqh_ch5, yaqh_ch5);
        ui->widget_SignalPlot->graph(5)->setPen(QPen(QColor(130, 0, 255)));
        ui->widget_SignalPlot->graph(1)->setName("Channel 5");
    }

    // Channel 6
    if(ChannelsToPlotSignal[6] == 1)
    {
        ui->widget_SignalPlot->addGraph();
        ui->widget_SignalPlot->graph(6)->setData(xaqh_ch6, yaqh_ch6);
        ui->widget_SignalPlot->graph(6)->setPen(QPen(QColor(255, 208, 0)));
        ui->widget_SignalPlot->graph(1)->setName("Channel 6");
    }

    // Channel 7
    if(ChannelsToPlotSignal[7] == 1)
    {
        ui->widget_SignalPlot->addGraph();
        ui->widget_SignalPlot->graph(7)->setData(xaqh_ch7, yaqh_ch7);
        ui->widget_SignalPlot->graph(7)->setPen(QPen(QColor(0, 0, 255)));
        ui->widget_SignalPlot->graph(1)->setName("Channel 7");
    }

    // give the axes some labels:
    ui->widget_SignalPlot->xAxis->setLabel("");
    ui->widget_SignalPlot->yAxis->setLabel("ADC counts");

//    ui->widget_SignalPlot->xAxis->setRange(min_x, max_x);
//    ui->widget_SignalPlot->yAxis->setRange(min_y, max_y);

    ui->widget_SignalPlot->setInteraction(QCP::iRangeDrag, true);
    ui->widget_SignalPlot->setInteraction(QCP::iRangeZoom, true);

    ui->widget_SignalPlot->replot();
}


//====================================================================================
// ============= SIGNAL TAB ===============
//====================================================================================


void MainWindow::on_pushButton_ClearPlot_clicked()
{
    //Clear Signal Plot

    ui->widget_SignalPlot->graph(0)->data()->clear();
    ui->widget_SignalPlot->graph(1)->data()->clear();
    ui->widget_SignalPlot->graph(2)->data()->clear();
    ui->widget_SignalPlot->graph(3)->data()->clear();
    ui->widget_SignalPlot->graph(4)->data()->clear();
    ui->widget_SignalPlot->graph(5)->data()->clear();
    ui->widget_SignalPlot->graph(6)->data()->clear();
    ui->widget_SignalPlot->graph(7)->data()->clear();
    ui->widget_SignalPlot->replot();
}



void MainWindow::on_checkBox_SignalChannel0_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotSignal[0] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotSignal[0] = 0;
        ui->widget_SignalPlot->graph(0)->data()->clear();
    }
}

void MainWindow::on_checkBox_SignalChannel1_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotSignal[1] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotSignal[1] = 0;
        ui->widget_SignalPlot->graph(1)->data()->clear();
    }
}

void MainWindow::on_checkBox_SignalChannel2_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotSignal[2] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotSignal[2] = 0;
        ui->widget_SignalPlot->graph(2)->data()->clear();
    }
}

void MainWindow::on_checkBox_SignalChannel3_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotSignal[3] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotSignal[3] = 0;
        ui->widget_SignalPlot->graph(3)->data()->clear();
    }
}

void MainWindow::on_checkBox_SignalChannel4_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotSignal[4] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotSignal[4] = 0;
        ui->widget_SignalPlot->graph(4)->data()->clear();
    }
}

void MainWindow::on_checkBox_SignalChannel5_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotSignal[5] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotSignal[5] = 0;
        ui->widget_SignalPlot->graph(5)->data()->clear();
    }
}

void MainWindow::on_checkBox_SignalChannel6_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotSignal[6] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotSignal[6] = 0;
        ui->widget_SignalPlot->graph(6)->data()->clear();
    }
}

void MainWindow::on_checkBox_SignalChannel7_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotSignal[7] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotSignal[7] = 0;
        ui->widget_SignalPlot->graph(7)->data()->clear();
    }
}



void MainWindow::on_pushButton_autoscale_clicked()
{
    qSort(yaqh_ch0.begin(), yaqh_ch0.end());
    min_x = xaqh_ch0.first();
    max_x = xaqh_ch0.last();

    qSort(yaqh_ch0.begin(), yaqh_ch0.end());
    min_y = yaqh_ch0.first();
    max_y = yaqh_ch0.last();
    cout << "min_y " << min_y << endl;
    // set axes ranges, so we see all data:
    ui->widget_SignalPlot->xAxis->setRange(min_x, max_x);
    ui->widget_SignalPlot->yAxis->setRange(min_y, max_y);

//    ui->widget_SignalPlot->xAxis->setRange(-1, 1);
//    ui->widget_SignalPlot->yAxis->setRange(-1, 1);

}



//====================================================================================




//====================================================================================
// =================== HISTOGRAM PLOT ========================
//====================================================================================

double min_x_range = 0;
double max_x_range = 0;
double min_y_range = 0;
double max_y_range = 2;


void MainWindow::makeHistogramPlot()
{
    int www;
    qSort(yaqh_ch0.begin(), yaqh_ch0.end());
    double min_y_ch0 = yaqh_ch0.first();
    double max_y_ch0 = yaqh_ch0.last();
    yaqh_ch0_hist[max_y_ch0-min_y_ch0] += 1;
    for(int i=0; i<x_range; i++){
        www = (int)max_y_ch0-(int)yaqh_ch0[i];
        yaqh_ch0_hist[max_y_ch0-yaqh_ch0[i]] += 1;
    }
//    cout << "min_y_ch0 " << min_y_ch0 << endl;

    qSort(yaqh_ch1.begin(), yaqh_ch1.end());
    double max_y_ch1 = yaqh_ch1.last();
    yaqh_ch1_hist[max_y_ch1] += 1;

    qSort(yaqh_ch2.begin(), yaqh_ch2.end());
    double max_y_ch2 = yaqh_ch2.last();
    yaqh_ch2_hist[max_y_ch2] += 1;

    qSort(yaqh_ch3.begin(), yaqh_ch3.end());
    double max_y_ch3 = yaqh_ch3.last();
    yaqh_ch3_hist[max_y_ch3] += 1;

    qSort(yaqh_ch4.begin(), yaqh_ch4.end());
    double max_y_ch4 = yaqh_ch4.last();
    yaqh_ch4_hist[max_y_ch4] += 1;

    qSort(yaqh_ch5.begin(), yaqh_ch5.end());
    double max_y_ch5 = yaqh_ch5.last();
    yaqh_ch5_hist[max_y_ch5] += 1;

    qSort(yaqh_ch6.begin(), yaqh_ch6.end());
    double max_y_ch6 = yaqh_ch6.last();
    yaqh_ch6_hist[max_y_ch6] += 1;

    qSort(yaqh_ch7.begin(), yaqh_ch7.end());
    double max_y_ch7 = yaqh_ch7.last();
    yaqh_ch7_hist[max_y_ch7] += 1;

    for(int i=0; i<60000; i++)
    {
        xaqh_ch0_hist[i] = i;
        xaqh_ch1_hist[i] = i;
        xaqh_ch2_hist[i] = i;
        xaqh_ch3_hist[i] = i;
        xaqh_ch4_hist[i] = i;
        xaqh_ch5_hist[i] = i;
        xaqh_ch6_hist[i] = i;
        xaqh_ch7_hist[i] = i;
    }



    // Channel 0
    if(ChannelsToPlotHistogram[0] == 1)
    {
        ui->widget_HistogramPlot->addGraph();
        ui->widget_HistogramPlot->graph(0)->setData(xaqh_ch0_hist, yaqh_ch0_hist);
        ui->widget_HistogramPlot->graph(0)->setLineStyle(QCPGraph::lsStepCenter);
        ui->widget_HistogramPlot->graph(0)->setPen(QPen(QColor(255, 0, 0)));
        ui->widget_HistogramPlot->graph(0)->setName("Channel 0");
    }

    // Channel 1
    if(ChannelsToPlotHistogram[1] == 1)
    {
        ui->widget_HistogramPlot->addGraph();
        ui->widget_HistogramPlot->graph(1)->setData(xaqh_ch1_hist, yaqh_ch1_hist);
        ui->widget_HistogramPlot->graph(1)->setLineStyle(QCPGraph::lsLine);
        ui->widget_HistogramPlot->graph(1)->setPen(QPen(QColor(0, 0, 255)));
        ui->widget_HistogramPlot->graph(1)->setName("Channel 1");
    }

    // Channel 2
    if(ChannelsToPlotHistogram[2] == 1)
    {
        ui->widget_HistogramPlot->addGraph();
        ui->widget_HistogramPlot->graph(2)->setData(xaqh_ch2_hist, yaqh_ch2_hist);
        ui->widget_HistogramPlot->graph(2)->setLineStyle(QCPGraph::lsLine);
        ui->widget_HistogramPlot->graph(2)->setPen(QPen(QColor(0, 255, 0)));
        ui->widget_HistogramPlot->graph(2)->setName("Channel 2");
    }

    // Channel 3
    if(ChannelsToPlotHistogram[3] == 1)
    {
        ui->widget_HistogramPlot->addGraph();
        ui->widget_HistogramPlot->graph(3)->setData(xaqh_ch3_hist, yaqh_ch3_hist);
        ui->widget_HistogramPlot->graph(3)->setLineStyle(QCPGraph::lsLine);
        ui->widget_HistogramPlot->graph(3)->setPen(QPen(QColor(255, 155, 0)));
        ui->widget_HistogramPlot->graph(3)->setName("Channel 3");
    }

    // Channel 4
    if(ChannelsToPlotHistogram[4] == 1)
    {
        ui->widget_HistogramPlot->addGraph();
        ui->widget_HistogramPlot->graph(4)->setData(xaqh_ch4_hist, yaqh_ch4_hist);
        ui->widget_HistogramPlot->graph(4)->setPen(QPen(QColor(255, 0, 255)));
        ui->widget_HistogramPlot->graph(4)->setName("Channel 4");
    }

    // Channel 5
    if(ChannelsToPlotHistogram[5] == 1)
    {
        ui->widget_HistogramPlot->addGraph();
        ui->widget_HistogramPlot->graph(5)->setData(xaqh_ch5_hist, yaqh_ch5_hist);
        ui->widget_HistogramPlot->graph(5)->setPen(QPen(QColor(130, 0, 255)));
        ui->widget_HistogramPlot->graph(5)->setName("Channel 5");
    }

    // Channel 6
    if(ChannelsToPlotHistogram[6] == 1)
    {
        ui->widget_HistogramPlot->addGraph();
        ui->widget_HistogramPlot->graph(6)->setData(xaqh_ch6_hist, yaqh_ch6_hist);
        ui->widget_HistogramPlot->graph(6)->setPen(QPen(QColor(255, 208, 0)));
        ui->widget_HistogramPlot->graph(6)->setName("Channel 6");
    }

    // Channel 7
    if(ChannelsToPlotHistogram[7] == 1)
    {
        ui->widget_HistogramPlot->addGraph();
        ui->widget_HistogramPlot->graph(7)->setData(xaqh_ch7_hist, yaqh_ch7_hist);
        ui->widget_HistogramPlot->graph(7)->setPen(QPen(QColor(0, 0, 255)));
        ui->widget_HistogramPlot->graph(7)->setName("Channel 7");
    }

    for(int i=0; i<60000; i++)
    {
        if(yaqh_ch0_hist[i] <= 0)
        {
            continue;
        }
        else
        {
            min_x_range = i;
            break;
        }
    }

    for(int i=59999; i>=0; i--)
    {
        if(yaqh_ch0_hist[i] <= 0)
        {
            continue;
        }
        else
        {
            max_x_range = i;
            break;
        }
    }

//    qSort(yaqh_ch0_hist.begin(), yaqh_ch0_hist.end());
//    max_y_range = yaqh_ch0_hist.last();
//    cout << "max_y_range " << max_y_range << endl;
    if(yaqh_ch0_hist[max_y_ch0-min_y_ch0] > max_y_range-1)
    {
        max_y_range = yaqh_ch0_hist[max_y_ch0-min_y_ch0] + 2;
    }

    ui->widget_HistogramPlot->xAxis->setLabel("x");
    ui->widget_HistogramPlot->yAxis->setLabel("Number of counts");


    if(LogScale == false){

        // set axes ranges, so we see all data:
        ui->widget_HistogramPlot->yAxis->setScaleType(QCPAxis::stLinear);
        ui->widget_HistogramPlot->xAxis->setRange(min_x_range, max_x_range);
        ui->widget_HistogramPlot->yAxis->setRange(min_y_range, max_y_range);
    //    ui->widget_HistogramPlot->xAxis->setRange(9300, 9350);
    //    ui->widget_HistogramPlot->yAxis->setRange(min_y_range, 50);
        ui->widget_HistogramPlot->replot();
    }
    if(LogScale == true){
        ui->widget_HistogramPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
        QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);
        ui->widget_HistogramPlot->yAxis->setTicker(logTicker);
        ui->widget_HistogramPlot->yAxis->setNumberFormat("eb");
        ui->widget_HistogramPlot->yAxis->setRange(1e-2, 1e10);
        ui->widget_HistogramPlot->replot();
    }
}


// ====== HISTOGRAM TAB ======

void MainWindow::on_pushButton_clicked()
{
    //Clear Histogram Plot
    ui->widget_HistogramPlot->graph(0)->data()->clear();
    ui->widget_HistogramPlot->replot();
}


void MainWindow::on_checkBox_HistogramChannel0_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotHistogram[0] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotHistogram[0] = 0;
        ui->widget_HistogramPlot->graph(0)->data()->clear();
    }
}

void MainWindow::on_checkBox_HistogramChannel1_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotHistogram[1] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotHistogram[1] = 0;
        ui->widget_HistogramPlot->graph(1)->data()->clear();
    }
}

void MainWindow::on_checkBox_HistogramChannel2_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotHistogram[2] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotHistogram[2] = 0;
        ui->widget_HistogramPlot->graph(2)->data()->clear();
    }
}

void MainWindow::on_checkBox_HistogramChannel3_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotHistogram[3] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotHistogram[3] = 0;
        ui->widget_HistogramPlot->graph(3)->data()->clear();
    }
}

void MainWindow::on_checkBox_HistogramChannel4_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotHistogram[4] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotHistogram[4] = 0;
        ui->widget_HistogramPlot->graph(4)->data()->clear();
    }
}

void MainWindow::on_checkBox_HistogramChannel5_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotHistogram[5] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotHistogram[5] = 0;
        ui->widget_HistogramPlot->graph(5)->data()->clear();
    }
}

void MainWindow::on_checkBox_HistogramChannel6_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotHistogram[6] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotHistogram[6] = 0;
        ui->widget_HistogramPlot->graph(6)->data()->clear();
    }
}

void MainWindow::on_checkBox_HistogramChannel7_clicked(bool checked)
{
    if(checked==true)
    {
        ChannelsToPlotHistogram[7] = 1;
    }
    if(checked==false)
    {
        ChannelsToPlotHistogram[7] = 0;
        ui->widget_HistogramPlot->graph(7)->data()->clear();
    }
}


void MainWindow::on_checkBox_logaritmicScale_clicked(bool checked)
{
    if(checked == true){
        LogScale = true;
    }
    else if(checked == false){
        LogScale = false;
    }
}


//====================================================================================




// ======= THREAD ===========

daqThread::daqThread()
{

}

void daqThread::requestAcquisition()
{
    inputMutex.lock();
    haltFlag = false;
    inputMutex.unlock();

    emit acquisitionRequested();
}

void daqThread::startAcquisition(ofstream& file)
{
    haltFlag = false;

    while(true)
    {
        if(haltFlag==true){
            haltFlag = false;
            break;
        }

        inputMutex.lock();

        Data_Accquisition(file);

        QEventLoop loop;
        QTimer::singleShot(0, &loop, SLOT(quit()));
        loop.exec();

        emit dataSheets();

        inputMutex.unlock();
    }

    emit acquisitionFinished();
}

void daqThread::stopAcquisition()
{
    this->haltFlag = true;
}


//====================================================================================



void MainWindow::on_timeEdit_timeChanged(const QTime &time)
{
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(on_pushButton_Stop_clicked()));
    czas = QTime(0, 0, 0).secsTo(time);
}
