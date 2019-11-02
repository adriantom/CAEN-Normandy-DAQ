#include "trigger_configuration.h"
#include "ui_trigger_configuration.h"
//#include "ui_mainwindow.h"
//#include "mainwindow.h"
//#include "mainwindow.cpp"
#include <iostream>
#include <algorithm>
/*
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
TriggerConfigurationVariables
DigitizerConfigurationVariables
DigitizerVaribles
#endif // MAINWINDOW_H


#pragma once
*/
#include "digitizervariables.h"
#pragma once
using namespace std;



static int SoftwareTriggerMode = 0;
static int ExternalTriggerInputMode = 0;
static int IOLevel = 0;
static int RunSynchronizationMode = 0;

static int TriggerPolarity [8] = {0,0,0,0,0,0,0,0};
static double ChannelTriggerThreshold [8] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
static int ChannelSelfTrigger [8] = {0,0,0,0,0,0,0,0};





// TEMPORARY SETTINGS VARIABLES

static int SoftwareTriggerMode_temp = 0;
static int ExternalTriggerInputMode_temp = 0;
static int IOLevel_temp = 0;
static int RunSynchronizationMode_temp = 0;

static bool TriggChannelMask = false;

static int trigg_channel_index = 0;
static int trigg_channel_index_old;

static int TriggerPolarity_temp [8] = {0,0,0,0,0,0,0,0};
static double ChannelTriggerThreshold_temp [9] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
static int ChannelSelfTrigger_temp [8] = {0,0,0,0,0,0,0,0};



Trigger_Configuration::Trigger_Configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Trigger_Configuration)
{
    ui->setupUi(this);

    ui->comboBox_SoftwareTriggerMode->setCurrentIndex(SoftwareTriggerMode);
    ui->comboBox_ExternalTriggerInputMode->setCurrentIndex(ExternalTriggerInputMode);
    ui->comboBox_IOLevel->setCurrentIndex(IOLevel);
    ui->RunSynchronizationMode->setCurrentIndex(RunSynchronizationMode);

    ui->checkBox_EveryChannel->setChecked(TriggChannelMask);

    ui->comboBox_Channels->setCurrentIndex(trigg_channel_index);
    ui->comboBox_TriggerPolarity->setCurrentIndex(TriggerPolarity[trigg_channel_index]);
    ui->doubleSpinBox_ChannelTriggerThreshold->setValue(ChannelTriggerThreshold[trigg_channel_index]);
    ui->comboBox_ChannelSelfTrigger->setCurrentIndex(ChannelSelfTrigger[trigg_channel_index]);

    ui->comboBox_Channels->setDisabled(TriggChannelMask);

    ui->pushButton_TriggConfig_Load->setDisabled(true);
    ui->pushButton_TriggConfig_Save->setDisabled(true);
}

Trigger_Configuration::~Trigger_Configuration()
{
    delete ui;
}

void Trigger_Configuration::on_pushButton_TriggConfig_Cancel_clicked()
{
    QWidget::close();
}

void Trigger_Configuration::on_pushButton_TriggConfig_OK_clicked()
{
    SoftwareTriggerMode = SoftwareTriggerMode_temp;
    ExternalTriggerInputMode = ExternalTriggerInputMode_temp;
    IOLevel = IOLevel_temp;
    RunSynchronizationMode = RunSynchronizationMode_temp;

    copy(begin(TriggerPolarity_temp), end(TriggerPolarity_temp), TriggerPolarity);
    copy(begin(ChannelTriggerThreshold_temp), end(ChannelTriggerThreshold_temp), ChannelTriggerThreshold);
    copy(begin(ChannelSelfTrigger_temp), end(ChannelSelfTrigger_temp), ChannelSelfTrigger);

//    cout << "===== selfTrigger ======== " << ChannelSelfTrigger[0] << endl;

    emit setTrigSettings();

    QWidget::close();
}



void Trigger_Configuration::on_comboBox_SoftwareTriggerMode_currentIndexChanged(int index)
{
    SoftwareTriggerMode_temp = index;
}

void Trigger_Configuration::on_comboBox_ExternalTriggerInputMode_currentIndexChanged(int index)
{
    ExternalTriggerInputMode_temp = index;
}

void Trigger_Configuration::on_comboBox_IOLevel_currentIndexChanged(int index)
{
    IOLevel_temp = index;
}

void Trigger_Configuration::on_RunSynchronizationMode_currentIndexChanged(int index)
{
    RunSynchronizationMode_temp = index;
}


//=================================================
//                      CHANNELS
//=================================================

void Trigger_Configuration::on_comboBox_Channels_currentIndexChanged(int index)
{
    trigg_channel_index = index;
    ui->comboBox_TriggerPolarity->setCurrentIndex(TriggerPolarity_temp[trigg_channel_index]);
    ui->doubleSpinBox_ChannelTriggerThreshold->setValue(ChannelTriggerThreshold_temp[trigg_channel_index]);
    ui->comboBox_ChannelSelfTrigger->setCurrentIndex(ChannelSelfTrigger_temp[trigg_channel_index]);
}



void Trigger_Configuration::on_comboBox_TriggerPolarity_currentIndexChanged(int index)
{
    if(TriggChannelMask == true){
        for(int i=0;i<8;i++){
            TriggerPolarity_temp[i] = index;
        }
    }
    else{
        TriggerPolarity_temp[trigg_channel_index] = index;
    }
}

void Trigger_Configuration::on_doubleSpinBox_ChannelTriggerThreshold_valueChanged(double arg1)
{
    if(TriggChannelMask == true){
        for(int i=0;i<8;i++){
            ui->horizontalSlider_ChannelTriggerThreshold->setValue(arg1);
            ChannelTriggerThreshold_temp[i] = arg1;
        }
    }
    else{
        ui->horizontalSlider_ChannelTriggerThreshold->setValue(arg1);
        ChannelTriggerThreshold_temp[trigg_channel_index] = arg1;
    }
}

void Trigger_Configuration::on_comboBox_ChannelSelfTrigger_currentIndexChanged(int index)
{
    if(TriggChannelMask == true){
        for(int i=0;i<8;i++){
            ChannelSelfTrigger_temp[i] = index;
        }
    }
    else{
        ChannelSelfTrigger_temp[trigg_channel_index] = index;
//        cout << ">>>>> index <<<<<<<  " << index << endl;
    }
}

void Trigger_Configuration::on_horizontalSlider_ChannelTriggerThreshold_valueChanged(int value)
{
//    double thresholdValue = value/100.0;
    double thresholdValue = value;

    ui->doubleSpinBox_ChannelTriggerThreshold->setValue(thresholdValue);
}

void Trigger_Configuration::on_checkBox_EveryChannel_clicked(bool checked)
{
    if(checked == true){
        TriggChannelMask = true;

        ui->comboBox_Channels->setDisabled(true);
        trigg_channel_index_old = trigg_channel_index;
 //       channel_index = 9;

        ui->comboBox_TriggerPolarity->setCurrentIndex(TriggerPolarity_temp[trigg_channel_index]);
        ui->doubleSpinBox_ChannelTriggerThreshold->setValue(ChannelTriggerThreshold_temp[trigg_channel_index]);
        ui->comboBox_ChannelSelfTrigger->setCurrentIndex(ChannelSelfTrigger_temp[trigg_channel_index]);
    }
    else{
        TriggChannelMask = false;

        ui->comboBox_Channels->setEnabled(true);
        trigg_channel_index = trigg_channel_index_old;
        ui->comboBox_TriggerPolarity->setCurrentIndex(TriggerPolarity_temp[trigg_channel_index]);
        ui->doubleSpinBox_ChannelTriggerThreshold->setValue(ChannelTriggerThreshold_temp[trigg_channel_index]);
        ui->comboBox_ChannelSelfTrigger->setCurrentIndex(ChannelSelfTrigger_temp[trigg_channel_index]);
    }
}
