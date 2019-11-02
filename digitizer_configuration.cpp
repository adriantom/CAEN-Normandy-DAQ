#include "digitizer_configuration.h"
#include "ui_digitizer_configuration.h"
//#include "ui_mainwindow.h"
//#include "mainwindow.h"
//#include "mainwindow.cpp"
#include <iostream>
#include <algorithm>
/*
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
DigitizerConfigurationVariables
TriggerConfigurationVariables
DigitizerVaribles
#endif //MAINWINDOW_H

#pragma once
*/



#include "digitizervariables.h"
#pragma once
using namespace std;
/*
#ifndef DIGITIZERVARIABLES_H
#define DIGITIZERVARIABLES_H
uint32_t ChannelEnableMask [8] = {0,0,0,0,0,0,0,0};
#endif
*/


static int PostTriggSize = 0;
static int AcquisitionMode = 0;
static int DESM = 0;
static int DecimationFactor = 0;

static int RecordLength [8] = {0,0,0,0,0,0,0,0};
static uint32_t ChannelEnableMask [8] = {1,1,1,1,1,1,1,1};
//double ChannelDCOffset [9] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
static int ChannelDCOffset [8] = {0,0,0,0,0,0,0,0};



// TEMPORARY SETTINGS VARIABLES

static int PostTriggSize_temp = 0;
static int AcquisitionMode_temp = 0;
static int DESM_temp = 0;
static int DecimationFactor_temp = 0;

static int channel_index = 0;
static int channel_index_old = channel_index;

//int AC_temp [8] = {0,1,2,3,4,5,6,7};

static bool ChannelMask = false;

static int RecordLength_temp [8] = {0,0,0,0,0,0,0,0};
static uint32_t ChannelEnableMask_temp [8] = {1,1,1,1,1,1,1,1};
//double ChannelDCOffset_temp [9] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
static int ChannelDCOffset_temp [8] = {0,0,0,0,0,0,0,0};
//============================================================

Digitizer_Configuration::Digitizer_Configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Digitizer_Configuration)
{
    ui->setupUi(this);
    //SAVED CONFIG LOADING
    ui->spinBox_PostTriggSize->setValue(PostTriggSize);
    ui->comboBox_AcquisitionMode->setCurrentIndex(AcquisitionMode);
    ui->comboBox_DESM->setCurrentIndex(DESM);
    ui->comboBox_DecimationFactor->setCurrentIndex(DecimationFactor);

    ui->checkBox_EveryChannel->setChecked(ChannelMask);

    ui->comboBox_Channels->setCurrentIndex(channel_index);
    ui->spinBox_RecordLength->setValue(RecordLength[channel_index]);
    ui->comboBox_ChannelEnableMask->setCurrentIndex(ChannelEnableMask[channel_index]);
    ui->spinBox_ChannelDCOffset->setValue(ChannelDCOffset[channel_index]);

    ui->comboBox_Channels->setDisabled(ChannelMask);

    ui->pushButton_DigConfig_Save->setDisabled(true);
    ui->pushButton_DigConfig_Load->setDisabled(true);

    ui->comboBox_DESM->setDisabled(true);
    ui->comboBox_DecimationFactor->setDisabled(true);

}

Digitizer_Configuration::~Digitizer_Configuration()
{
    delete ui;
}

void Digitizer_Configuration::on_pushButton_DigConfig_Cancel_clicked()
{
    QWidget::close();
}

void Digitizer_Configuration::on_pushButton_DigConfig_OK_clicked()
{
    PostTriggSize = PostTriggSize_temp;
    AcquisitionMode = AcquisitionMode_temp;
    DESM = DESM_temp;
    DecimationFactor = DecimationFactor_temp;
    copy(begin(RecordLength_temp), end(RecordLength_temp), RecordLength);
    copy(begin(ChannelEnableMask_temp), end(ChannelEnableMask_temp), ChannelEnableMask);
    copy(begin(ChannelDCOffset_temp), end(ChannelDCOffset_temp), ChannelDCOffset);

    emit setDigiSettings();

    QWidget::close();
}

void Digitizer_Configuration::on_spinBox_PostTriggSize_valueChanged(int arg1)
{
    PostTriggSize_temp=arg1;
}

void Digitizer_Configuration::on_comboBox_AcquisitionMode_currentIndexChanged(int index)
{
    AcquisitionMode_temp=index;
}

void Digitizer_Configuration::on_comboBox_DESM_currentIndexChanged(int index)
{
    DESM_temp = index;
}

void Digitizer_Configuration::on_comboBox_DecimationFactor_currentIndexChanged(int index)
{
    DecimationFactor_temp = index;
}

//=====================================
//          SETTINGS FOR CHANNELS
//=====================================

void Digitizer_Configuration::on_comboBox_Channels_currentIndexChanged(int index)
{
    channel_index = index;
    ui->spinBox_RecordLength->setValue(RecordLength_temp[channel_index]);
    ui->comboBox_ChannelEnableMask->setCurrentIndex(ChannelEnableMask_temp[channel_index]);
    ui->spinBox_ChannelDCOffset->setValue(ChannelDCOffset_temp[channel_index]);
}

void Digitizer_Configuration::on_spinBox_RecordLength_valueChanged(int arg1)
{
    if(ChannelMask == true){
        for(int i=0;i<8;i++){
            RecordLength_temp[i] = arg1;
        }
    }
    else{
    RecordLength_temp[channel_index] = arg1;
    }
}

void Digitizer_Configuration::on_comboBox_ChannelEnableMask_currentIndexChanged(int index)
{
    if(ChannelMask == true){
        for(int i=0;i<8;i++){
            ChannelEnableMask_temp[i] = index;
        }
    }
    else{
    ChannelEnableMask_temp[channel_index] = index;
    }
}

void Digitizer_Configuration::on_spinBox_ChannelDCOffset_valueChanged(int arg1)
{
    if(ChannelMask == true){
        for(int i=0;i<8;i++){
            ChannelDCOffset_temp[i] = arg1;
        }
    }
    else{
    ChannelDCOffset_temp[channel_index] = arg1;
    }
}

void Digitizer_Configuration::on_pushButton_DigConfig_Load_clicked()
{

}

void Digitizer_Configuration::on_checkBox_EveryChannel_clicked(bool checked)
{
    if(checked == true){
        ChannelMask = true;

        ui->comboBox_Channels->setDisabled(true);
        channel_index_old = channel_index;

        ui->spinBox_RecordLength->setValue(RecordLength_temp[channel_index]);
        ui->comboBox_ChannelEnableMask->setCurrentIndex(ChannelEnableMask_temp[channel_index]);
        ui->spinBox_ChannelDCOffset->setValue(ChannelDCOffset_temp[channel_index]);
    }
    else{
        ChannelMask = false;

        ui->comboBox_Channels->setEnabled(true);
        channel_index = channel_index_old;
        ui->spinBox_RecordLength->setValue(RecordLength_temp[channel_index]);
        ui->comboBox_ChannelEnableMask->setCurrentIndex(ChannelEnableMask_temp[channel_index]);
        ui->spinBox_ChannelDCOffset->setValue(ChannelDCOffset_temp[channel_index]);
    }
}

