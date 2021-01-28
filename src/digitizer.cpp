#include <iostream>
#include <vector>
//#include "digitizervariables.h"
#include "digitizer_configuration.cpp"
#include "trigger_configuration.cpp"
#include "savefile.cpp"

#ifndef DIGITIZERVARIABLES_H
#define DIGITIZERVARIABLES_H
uint32_t ChannelEnableMask [8] = {0,0,0,0,0,0,0,0};
#endif

#include "CAENDigitizer.h"

#include <cstdlib>
#include <cmath>
#include <fstream>
#include <ctime>




#pragma once

using namespace std;


// === zmienne globalne =====

int handle;
CAEN_DGTZ_BoardInfo_t BoardInfo;
CAEN_DGTZ_EventInfo_t eventInfo;
CAEN_DGTZ_UINT16_EVENT_t *Evt = NULL;
int count;
char *buffer = NULL;
CAEN_DGTZ_ErrorCode ret;
char *evtptr = NULL;
uint32_t numEvents;
uint32_t size,bsize;
int i;

int zz;


int Nbit = 14;
double Ts = 2.0;
int Nch = 8;

static bool LogScale = false;

int dc_file;
uint32_t DCoffset;
uint32_t NumEvents, AllocatedSize, BufferSize;
CAEN_DGTZ_EventInfo_t EventInfo;
//CAEN_DGTZ_UINT16_EVENT_t *Evt = NULL;
char *EventPtr = NULL;



uint32_t mask, channel, Tvalue;

// Digitizer cinfig variables

CAEN_DGTZ_AcqMode_t mem_mode;
uint32_t percent;

// DIGITIZER FUNCTIONS CLASS

int WriteRegisterBitmask(int32_t handle, uint32_t address, uint32_t data, uint32_t mask) {
    int32_t ret = CAEN_DGTZ_Success;
    uint32_t d32 = 0xFFFFFFFF;

    ret = CAEN_DGTZ_ReadRegister(handle, address, &d32);
    if(ret != CAEN_DGTZ_Success)
        return ret;

    data &= mask;
    d32 &= ~mask;
    d32 |= data;
    ret = CAEN_DGTZ_WriteRegister(handle, address, d32);
    return ret;
}


uint32_t MASK_BIN(uint32_t maska)
{
    for(int i=7; i==0; i--)
    {
    ChannelEnableMask[i]=maska%2;
    maska = maska/2;
    }
    return maska;
}


uint32_t MASK()
{
    uint32_t Mask_temp = 0;

    for(int i=0;i<8;i++){
        Mask_temp = Mask_temp + pow(2,i) * ChannelEnableMask[i];
    }
    return Mask_temp;
}



void Reset()
{
    ret = CAEN_DGTZ_Reset(handle);
}

void Calibration()
{
    ret = CAEN_DGTZ_Calibrate(handle);
}


int Get_Digitizer_Configuration()
{
//  GET POST TRIGGER SIZE
    ret = CAEN_DGTZ_GetPostTriggerSize(handle, &percent);
    if(ret != CAEN_DGTZ_Success)
    {
        return ret;
    };
    PostTriggSize = (int)percent;

//  GET ACQUISITION MODE
    ret = CAEN_DGTZ_GetAcquisitionMode(handle, &mem_mode);
    if(ret != CAEN_DGTZ_Success)
    {
        return ret;
    };

        if(mem_mode == CAEN_DGTZ_SW_CONTROLLED){
            AcquisitionMode = 0;
        }
        else if(mem_mode == CAEN_DGTZ_S_IN_CONTROLLED){
            AcquisitionMode = 1;
        }
        else if(mem_mode == CAEN_DGTZ_FIRST_TRG_CONTROLLED){
            AcquisitionMode = 2;
        }

//      UNUSED PARAMETERS (with x730 family)

//    CEAN_DGTZ_EnaDis_t DESmode;
//    ret = CAEN_DGTZ_GetDESMode(handle, &DESmode);
//        DESM = DESmode;
//    uint16_t factor;
//    ret = GetDecimation


    uint32_t size, mask, channel, Tvalue;
    for(int ch=0; ch<8; ch++){
        channel = (uint32_t)ch;

//      GET RECORD LENGTH
        ret = CAEN_DGTZ_GetRecordLength(handle, &size /*, channel*/);
        if(ret != CAEN_DGTZ_Success)
        {
            return ret;
        };
        RecordLength[ch] = size;
        cout<<"size "<<size<<" ch:"<<ch<<" RL:"<<RecordLength[ch]<<endl;
//      GET CHANNEL DC OFFSET
        ret = CAEN_DGTZ_GetChannelDCOffset(handle, channel, &Tvalue);
        if(ret != CAEN_DGTZ_Success)
        {
            return ret;
        };
        ChannelDCOffset[ch] = Tvalue;
    }

//  GET CHANNEL ENABLE MASK
    ret = CAEN_DGTZ_GetChannelEnableMask(handle,&mask);
    if(ret != CAEN_DGTZ_Success)
    {
        return ret;
    };
    mask = MASK_BIN(mask);

//  PROPERLY RETURN
    return 0;
}

int Get_Trigger_Configuration()
{
    CAEN_DGTZ_TriggerMode_t trg_mode,ext_trg_mode,ch_self_trg_mode;

    ret = CAEN_DGTZ_GetSWTriggerMode(handle, &trg_mode);
    if(ret != CAEN_DGTZ_Success)
    {
        return ret;
    };
        if(trg_mode == CAEN_DGTZ_TRGMODE_DISABLED){
            SoftwareTriggerMode = 0;
        }
        else if(trg_mode == CAEN_DGTZ_TRGMODE_EXTOUT_ONLY){
            SoftwareTriggerMode = 1;
        }
        else if(trg_mode == CAEN_DGTZ_TRGMODE_ACQ_ONLY){
            SoftwareTriggerMode = 2;
        }
        else if(trg_mode == CAEN_DGTZ_TRGMODE_ACQ_AND_EXTOUT){
            SoftwareTriggerMode = 3;
        }

    ret = CAEN_DGTZ_GetExtTriggerInputMode(handle, &ext_trg_mode);
    if(ret != CAEN_DGTZ_Success)
    {
        return ret;
    };
        if(ext_trg_mode == CAEN_DGTZ_TRGMODE_DISABLED){
            ExternalTriggerInputMode = 0;
        }
        else if(ext_trg_mode == CAEN_DGTZ_TRGMODE_EXTOUT_ONLY){
            ExternalTriggerInputMode = 1;
        }
        else if(ext_trg_mode == CAEN_DGTZ_TRGMODE_ACQ_ONLY){
            ExternalTriggerInputMode = 2;
        }
        else if(ext_trg_mode == CAEN_DGTZ_TRGMODE_ACQ_AND_EXTOUT){
            ExternalTriggerInputMode = 3;
        }

    CAEN_DGTZ_IOLevel_t level;
    ret = CAEN_DGTZ_GetIOLevel(handle, &level);
    if(ret != CAEN_DGTZ_Success)
    {
        return ret;
    };
        if(level == CAEN_DGTZ_IOLevel_NIM){
            IOLevel = 0;
        }
        else if(level == CAEN_DGTZ_IOLevel_TTL){
            IOLevel = 1;
        }

    CAEN_DGTZ_RunSyncMode_t sync_mode;
    ret = CAEN_DGTZ_GetRunSynchronizationMode(handle, &sync_mode);
    if(ret != CAEN_DGTZ_Success)
    {
        return ret;
    };
        if(sync_mode == CAEN_DGTZ_RUN_SYNC_Disabled){
            RunSynchronizationMode = 0;
        }
        else if(sync_mode == CAEN_DGTZ_RUN_SYNC_TrgOutTrgInDaisyChain){
            RunSynchronizationMode = 1;
        }
        else if(sync_mode == CAEN_DGTZ_RUN_SYNC_TrgOutSinDaisyChain){
            RunSynchronizationMode = 2;
        }
        else if(sync_mode == CAEN_DGTZ_RUN_SYNC_SinFanout){
            RunSynchronizationMode = 3;
        }

    //uint32_t size, mask, channel, Tvalue;
    CAEN_DGTZ_TriggerPolarity_t polarity;
    for(int ch=0; ch<8; ch++){
        channel = (uint32_t)ch;
        ret = CAEN_DGTZ_GetTriggerPolarity(handle, channel, &polarity);
        if(ret != CAEN_DGTZ_Success)
        {
            return ret;
        };
            if(polarity == 0){ //CAEN_DGTZ_TriggerOnRisingEdge
                TriggerPolarity[ch] = 0;
            }
            else if(polarity == 1){ //CAEN_DGTZ_TriggerOnFallingEdge
                TriggerPolarity[ch] = 1;
            }
        ret = CAEN_DGTZ_GetChannelTriggerThreshold(handle, channel, &Tvalue);
        if(ret != CAEN_DGTZ_Success)
        {
            return ret;
        };
        ChannelTriggerThreshold[ch] = Tvalue;

        ret = CAEN_DGTZ_GetChannelSelfTrigger(handle, channel, &ch_self_trg_mode);
        cout << "CAEN_DGTZ_GetChannelSelfTrigger " << channel << "  " << ch_self_trg_mode << endl;
        if(ret != CAEN_DGTZ_Success)
        {
            return ret;
        };
            if(ch_self_trg_mode == 0){ //CAEN_DGTZ_TRGMODE_DISABLED
                ChannelSelfTrigger[ch] = 0;
            }
            else if(ch_self_trg_mode == 1){ // CAEN_DGTZ_TRGMODE_EXTOUT_ONLY
                ChannelSelfTrigger[ch] = 1;
            }
            else if(ch_self_trg_mode == 2){ //CAEN_DGTZ_TRGMODE_ACQ_ONLY
                ChannelSelfTrigger[ch] = 2;
            }
            else if(ch_self_trg_mode == 3){ //CAEN_DGTZ_TRGMODE_ACQ_AND_EXTOUT
                ChannelSelfTrigger[ch] = 3;
            }
    }

    return 0;
}

int Set_Digitizer_Configuration()
{
    uint32_t percent = (uint32_t)PostTriggSize;
    ret = CAEN_DGTZ_SetPostTriggerSize(handle, percent);
    if(ret != CAEN_DGTZ_Success)
    {
        return ret;
    };
        if(AcquisitionMode == 0){
            mem_mode = CAEN_DGTZ_SW_CONTROLLED;
            ret = CAEN_DGTZ_SetAcquisitionMode(handle, mem_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "set AccMode0 ret: " << ret << endl;
        }
        else if(AcquisitionMode == 1){
            mem_mode = CAEN_DGTZ_S_IN_CONTROLLED;
            ret = CAEN_DGTZ_SetAcquisitionMode(handle, mem_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "set AccMode1 ret: " << ret << endl;
        }
        else if(AcquisitionMode == 2){
            mem_mode = CAEN_DGTZ_FIRST_TRG_CONTROLLED;
            ret = CAEN_DGTZ_SetAcquisitionMode(handle, mem_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "set AccMode2 ret: " << ret << endl;
        }

    uint32_t /*size,*/ channel, Tvalue;

    for(int ch=0; ch<8; ch++){
        channel = (uint32_t)ch;
//        cout << "channel" << channel << endl;
        size = (uint32_t)RecordLength[ch];
        cout << "RecordLength: " << RecordLength[ch] << endl;
        ret = CAEN_DGTZ_SetRecordLength(handle, size, channel); // Psuje sie !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(ret != CAEN_DGTZ_Success)
        {
            return ret;
        };
//        cout << "set RecLen ch" << i << " ret: " << ret << endl;

        Tvalue = ChannelDCOffset[ch];
        ret = CAEN_DGTZ_SetChannelDCOffset(handle, channel, Tvalue);
        if(ret != CAEN_DGTZ_Success)
        {
            return ret;
        };
//        cout << "set ChDCOffset ch" << i << " ret: " << ret << endl;
    }

    // ERROR
    mask = MASK();
    cout << "mask: " << mask << endl;
    ret = CAEN_DGTZ_SetChannelEnableMask(handle,255);
    if(ret != CAEN_DGTZ_Success)
    {
        return ret;
    };
//    cout << "set ChEnableMask ret: " << ret << endl;

    return 0;

}

int Set_Trigger_Configuration()
{

    ret = CAEN_DGTZ_SetMaxNumEventsBLT(handle,1);
    if(ret != CAEN_DGTZ_Success)
    {
        return ret;
    };

    CAEN_DGTZ_TriggerMode_t trg_mode,ext_trg_mode,ch_self_trg_mode;
//        CAEN_DGTZ_TriggerMode_t trg_mode,ext_trg_mode;

        if(SoftwareTriggerMode == 0){
            trg_mode = CAEN_DGTZ_TRGMODE_DISABLED;
            ret = CAEN_DGTZ_SetSWTriggerMode(handle, trg_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }
        else if(SoftwareTriggerMode == 1){
            trg_mode = CAEN_DGTZ_TRGMODE_EXTOUT_ONLY;
            ret = CAEN_DGTZ_SetSWTriggerMode(handle, trg_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }
        else if(SoftwareTriggerMode == 2){
            trg_mode = CAEN_DGTZ_TRGMODE_ACQ_ONLY;
            ret = CAEN_DGTZ_SetSWTriggerMode(handle, trg_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }
        else if(SoftwareTriggerMode == 3){
            trg_mode = CAEN_DGTZ_TRGMODE_ACQ_AND_EXTOUT;
            ret = CAEN_DGTZ_SetSWTriggerMode(handle, trg_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }


        if(ExternalTriggerInputMode == 0){
            ext_trg_mode = CAEN_DGTZ_TRGMODE_DISABLED;
            ret = CAEN_DGTZ_SetExtTriggerInputMode(handle, ext_trg_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }
        else if(ExternalTriggerInputMode == 1){
            ext_trg_mode = CAEN_DGTZ_TRGMODE_EXTOUT_ONLY;
            ret = CAEN_DGTZ_SetExtTriggerInputMode(handle, ext_trg_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }
        else if(ExternalTriggerInputMode == 2){
            ext_trg_mode = CAEN_DGTZ_TRGMODE_ACQ_ONLY;
            ret = CAEN_DGTZ_SetExtTriggerInputMode(handle, ext_trg_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }
        else if(ExternalTriggerInputMode == 3){
            ext_trg_mode = CAEN_DGTZ_TRGMODE_ACQ_AND_EXTOUT;
            ret = CAEN_DGTZ_SetExtTriggerInputMode(handle, ext_trg_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }

    CAEN_DGTZ_IOLevel_t level;
        if(IOLevel == 0){
            level = CAEN_DGTZ_IOLevel_NIM;
            ret = CAEN_DGTZ_SetIOLevel(handle, level);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }
        else if(IOLevel == 1){
            level = CAEN_DGTZ_IOLevel_TTL;
            ret = CAEN_DGTZ_SetIOLevel(handle, level);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }

    CAEN_DGTZ_RunSyncMode_t sync_mode;
        if(RunSynchronizationMode == 0){
            sync_mode = CAEN_DGTZ_RUN_SYNC_Disabled;
            ret = CAEN_DGTZ_SetRunSynchronizationMode(handle, sync_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }
        else if(RunSynchronizationMode == 1){
            sync_mode = CAEN_DGTZ_RUN_SYNC_TrgOutTrgInDaisyChain;
            ret = CAEN_DGTZ_SetRunSynchronizationMode(handle, sync_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }
        else if(RunSynchronizationMode == 2){
            sync_mode = CAEN_DGTZ_RUN_SYNC_TrgOutSinDaisyChain;
            ret = CAEN_DGTZ_SetRunSynchronizationMode(handle, sync_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }
        else if(RunSynchronizationMode == 3){
            sync_mode = CAEN_DGTZ_RUN_SYNC_SinFanout;
            ret = CAEN_DGTZ_SetRunSynchronizationMode(handle, sync_mode);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }

 //   uint32_t size, mask, channel, Tvalue;
    CAEN_DGTZ_TriggerPolarity_t polarity;
    for(int ch=0; ch<8; ch++){
        channel = (uint32_t)ch;

        if(TriggerPolarity[ch] == 0){
            polarity = CAEN_DGTZ_TriggerOnRisingEdge; // zmiany sie nie zapisuja
            ret = CAEN_DGTZ_SetTriggerPolarity(handle, channel, polarity);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }
        else if(TriggerPolarity[ch] == 1){
            polarity = CAEN_DGTZ_TriggerOnFallingEdge;
            ret = CAEN_DGTZ_SetTriggerPolarity(handle, channel, polarity);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
//            cout << "ret: " << ret << endl;
        }



        Tvalue = ChannelTriggerThreshold[ch];
        ret = CAEN_DGTZ_SetChannelTriggerThreshold(handle, channel, Tvalue);
        if(ret != CAEN_DGTZ_Success)
        {
            return ret;
        };
//        cout << "retChTriggThre: " << ret << endl;
//        cout << "TValue set: " << Tvalue << endl;



//          TO SIE COS PSUJE
        if(ChannelSelfTrigger[ch] == 0){
            ch_self_trg_mode = CAEN_DGTZ_TRGMODE_DISABLED;
            ret = CAEN_DGTZ_SetChannelSelfTrigger(handle, ch_self_trg_mode, 255);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
        }
        else if(ChannelSelfTrigger[ch] == 1){
            ch_self_trg_mode = CAEN_DGTZ_TRGMODE_EXTOUT_ONLY;
            ret = CAEN_DGTZ_SetChannelSelfTrigger(handle, ch_self_trg_mode, 255);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
        }
        else if(ChannelSelfTrigger[ch] == 2){
            ch_self_trg_mode = CAEN_DGTZ_TRGMODE_ACQ_ONLY;
            ret = CAEN_DGTZ_SetChannelSelfTrigger(handle, ch_self_trg_mode, 255);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
        }
        else if(ChannelSelfTrigger[ch] == 3){
            ch_self_trg_mode = CAEN_DGTZ_TRGMODE_ACQ_AND_EXTOUT;
            ret = CAEN_DGTZ_SetChannelSelfTrigger(handle, ch_self_trg_mode, 255);
            if(ret != CAEN_DGTZ_Success)
            {
                return ret;
            };
        }

// ==================================

    }

    return 0;
}



// =============   DC OFFSET   ==============================

void Calibrate_DC_Offset(int handle, uint32_t ch, int dc_file=0, uint32_t *DCoffset=NULL)
{
// void Calibrate_DC_Offset(int handle, WaveDumpConfig_t WDcfg, CAEN_DGTZ_BoardInfo_t BoardInfo)
float cal = 1;
float offset = 0;
int i = 0, k = 0, p = 0, acq = 0;
CAEN_DGTZ_AcqMode_t mem_mode;
uint32_t  AllocatedSize;
uint32_t BufferSize;
CAEN_DGTZ_EventInfo_t       EventInfo;
char *bufferr = NULL;
char *EventPtr = NULL;
CAEN_DGTZ_UINT16_EVENT_t    *Event16 = NULL;
ret = CAEN_DGTZ_GetAcquisitionMode(handle, &mem_mode);//chosen value stored
ret = CAEN_DGTZ_SetAcquisitionMode(handle, CAEN_DGTZ_SW_CONTROLLED);
ret = CAEN_DGTZ_SetExtTriggerInputMode(handle, CAEN_DGTZ_TRGMODE_DISABLED);
ret = CAEN_DGTZ_SetPostTriggerSize(handle, 0);
ret = CAEN_DGTZ_MallocReadoutBuffer(handle, &bufferr, &AllocatedSize);
ret = CAEN_DGTZ_AllocateEvent(handle, (void**)&Event16);
#define NPOINTS 2
#define NACQS   50
float avg_value[NPOINTS] = { 0 };
uint32_t dc[NPOINTS] = {25,75}; //test values (%)
ch=0;
printf("Starting channel %d DAC calibration...\n", ch);
ret = CAEN_DGTZ_SetChannelSelfTrigger(handle,CAEN_DGTZ_TRGMODE_DISABLED, (1 << ch));
//int cal_ok[8]={1};

for (p=0; p<NPOINTS; p++){
    ret = CAEN_DGTZ_SetChannelDCOffset(handle, (uint32_t)ch, (uint32_t)((float)(abs((int)(dc[p]) - 100))*(655.35)));
    usleep(200000);
    ret = CAEN_DGTZ_SWStartAcquisition(handle);
    CAEN_DGTZ_ClearData(handle);

    int value[NACQS] = { 0 };
    for (acq = 0; acq < NACQS; acq++){	CAEN_DGTZ_SendSWtrigger(handle);
        ret = CAEN_DGTZ_ReadData(handle, CAEN_DGTZ_SLAVE_TERMINATED_READOUT_MBLT, bufferr, &BufferSize);
        ret = CAEN_DGTZ_GetEventInfo(handle, bufferr, BufferSize, 0, &EventInfo, &EventPtr);
        ret = CAEN_DGTZ_DecodeEvent(handle, EventPtr, (void**)&Event16);
        for (i = 1; i < 7; i++){value[acq] += (int)(Event16->DataChannel[ch][i]);}
        value[acq] = (value[acq] / 6);
    }  //for acq

     ///check for clean baselines
    int maxx = 0;
    int mpp = 0;
    int size = (int)pow(2, (double)14);
    int *freq = (int*)calloc(size, sizeof(int));
    for (k = 0; k < NACQS; k++){
        if (value[k] > 0 && value[k] < size){freq[value[k]]++; if (freq[value[k]] > maxx) { maxx = freq[value[k]]; mpp = value[k]; }}}
    free(freq);
    int ok = 0;
    for (k = 0; k < NACQS; k++){
        if (value[k] == mpp || value[k] == (mpp + 1) || value[k] == (mpp - 1)){avg_value[p] = avg_value[p] + (float)value[k]; ok++;}}
    avg_value[p] = (avg_value[p] / (float)ok)*100. / (float)size;
} // for p

CAEN_DGTZ_SWStopAcquisition(handle);
cal = ((float)(avg_value[1] - avg_value[0]) / (float)(dc[1] - dc[0]));
offset = (float)(dc[1] * avg_value[0] - dc[0] * avg_value[1]) / (float)(dc[1] - dc[0]);
printf("Cal %f   offset %f\n", cal, offset);
//CAEN_DGTZ_PulsePolarityPositive
*DCoffset= (uint32_t)((float)(fabs(( ((float)dc_file - offset )/ cal ) - 100.))*(655.35));
printf("DCoffset[%d]=%d\n",ch,*DCoffset);
if (*DCoffset > 65535) *DCoffset = 65535;
//if (*DCoffset < 0) *DCoffset = 0;
ret = CAEN_DGTZ_SetChannelDCOffset(handle, (uint32_t)ch, *DCoffset);
usleep(200000);
CAEN_DGTZ_FreeReadoutBuffer(&bufferr);
CAEN_DGTZ_FreeEvent(handle, (void**)&Event16);
ret = CAEN_DGTZ_SetPostTriggerSize(handle, 49);
ret = CAEN_DGTZ_SetAcquisitionMode(handle, mem_mode);
ret = CAEN_DGTZ_SetExtTriggerInputMode(handle,CAEN_DGTZ_TRGMODE_ACQ_ONLY);

}



//=====================================================

void Digitizer_Congiguration()
{
    uint32_t DCoffset = 32768;

    ret = CAEN_DGTZ_SetRecordLength(handle,1030);
    ret = CAEN_DGTZ_SetPostTriggerSize(handle,49);
    ret = CAEN_DGTZ_SetIOLevel(handle, CAEN_DGTZ_IOLevel_NIM);
    ret = CAEN_DGTZ_SetMaxNumEventsBLT(handle,1);
    ret = CAEN_DGTZ_SetAcquisitionMode(handle, CAEN_DGTZ_SW_CONTROLLED);
    ret = CAEN_DGTZ_SetExtTriggerInputMode(handle,CAEN_DGTZ_TRGMODE_ACQ_ONLY);
    ret = CAEN_DGTZ_SetChannelEnableMask(handle, 1);
    ret = CAEN_DGTZ_SetChannelDCOffset(handle, 0,DCoffset);
    ret = CAEN_DGTZ_SetChannelDCOffset(handle, 0, 65000);
    for(int i=1; i<8; i++) CAEN_DGTZ_SetChannelDCOffset(handle, i, 32768);
    ret = CAEN_DGTZ_SetChannelTriggerThreshold(handle, 0, 106);
    for(int i=1; i<8; i++)CAEN_DGTZ_SetChannelTriggerThreshold(handle, i, 100);
    for(int i=0; i<8; i++)CAEN_DGTZ_SetTriggerPolarity(handle, i,
    CAEN_DGTZ_TriggerOnRisingEdge );
    ret = CAEN_DGTZ_SetChannelSelfTrigger(handle, CAEN_DGTZ_TRGMODE_ACQ_ONLY, 1);
}


int x_range = 1030;
int y_range = 1030;


// ALL BELOW VECTORS ARE INITIALIZED BY ZEROS
// SIGNAL

QVector<double> xaqh_ch0(x_range), yaqh_ch0(y_range);
QVector<double> xaqh_ch1(x_range), yaqh_ch1(y_range);
QVector<double> xaqh_ch2(x_range), yaqh_ch2(y_range);
QVector<double> xaqh_ch3(x_range), yaqh_ch3(y_range);
QVector<double> xaqh_ch4(x_range), yaqh_ch4(y_range);
QVector<double> xaqh_ch5(x_range), yaqh_ch5(y_range);
QVector<double> xaqh_ch6(x_range), yaqh_ch6(y_range);
QVector<double> xaqh_ch7(x_range), yaqh_ch7(y_range);


// HISTOGRAM

QVector<double> xaqh_ch0_hist(60000), yaqh_ch0_hist(60000);
QVector<double> xaqh_ch1_hist(60000), yaqh_ch1_hist(60000);
QVector<double> xaqh_ch2_hist(60000), yaqh_ch2_hist(60000);
QVector<double> xaqh_ch3_hist(60000), yaqh_ch3_hist(60000);
QVector<double> xaqh_ch4_hist(60000), yaqh_ch4_hist(60000);
QVector<double> xaqh_ch5_hist(60000), yaqh_ch5_hist(60000);
QVector<double> xaqh_ch6_hist(60000), yaqh_ch6_hist(60000);
QVector<double> xaqh_ch7_hist(60000), yaqh_ch7_hist(60000);

QVector<double> xaqh_ch0_hist_integral(60000), yaqh_ch0_hist_integral(60000);
QVector<double> xaqh_ch1_hist_integral(60000), yaqh_ch1_hist_integral(60000);
QVector<double> xaqh_ch2_hist_integral(60000), yaqh_ch2_hist_integral(60000);
QVector<double> xaqh_ch3_hist_integral(60000), yaqh_ch3_hist_integral(60000);
QVector<double> xaqh_ch4_hist_integral(60000), yaqh_ch4_hist_integral(60000);
QVector<double> xaqh_ch5_hist_integral(60000), yaqh_ch5_hist_integral(60000);
QVector<double> xaqh_ch6_hist_integral(60000), yaqh_ch6_hist_integral(60000);
QVector<double> xaqh_ch7_hist_integral(60000), yaqh_ch7_hist_integral(60000);



int integral_ch0_hist = 0;
int integral_ch1_hist = 0;
int integral_ch2_hist = 0;
int integral_ch3_hist = 0;
int integral_ch4_hist = 0;
int integral_ch5_hist = 0;
int integral_ch6_hist = 0;
int integral_ch7_hist = 0;


double min_x = 0;
double max_x = x_range;
double min_y = 0;
double max_y = 11000;


//double max_y_ch0 = 0;
//double min_y_ch0 = 0;


int x[1030], y[1030];

int Data_Accquisition(ofstream& file)
{

//  Digitizer_Congiguration();

//    QVector<double> * xaqh_ch0, * yaqh_ch0;
//    xaqh_ch0 = new QVector<double> (1030);
//    yaqh_ch0 = new QVector<double> (1030);



  ret = CAEN_DGTZ_AllocateEvent(handle, (void**)&Evt); // sprawdzic czy zrobil alokacje
  if(ret != CAEN_DGTZ_Success)
  {
      return ret;
  };
  ret = CAEN_DGTZ_MallocReadoutBuffer(handle,&buffer,&size);
  if(ret != CAEN_DGTZ_Success)
  {
      return ret;
  };
  ret = CAEN_DGTZ_SWStartAcquisition(handle);
  if(ret != CAEN_DGTZ_Success)
  {
      return ret;
  };
  ret = CAEN_DGTZ_SendSWtrigger(handle);
  if(ret != CAEN_DGTZ_Success)
  {
      return ret;
  };
  ret = CAEN_DGTZ_ReadData(handle,CAEN_DGTZ_SLAVE_TERMINATED_READOUT_MBLT,buffer,&bsize);
  if(ret != CAEN_DGTZ_Success)
  {
      return ret;
  };
  ret = CAEN_DGTZ_GetNumEvents(handle,buffer,bsize,&numEvents);
  if(ret != CAEN_DGTZ_Success)
  {
      return ret;
  };
  ret = CAEN_DGTZ_GetEventInfo(handle,buffer,bsize,i,&eventInfo,&evtptr);
  if(ret != CAEN_DGTZ_Success)
  {
      return ret;
  };
  ret = CAEN_DGTZ_DecodeEvent(handle,evtptr,(void**)&Evt);
  if(ret != CAEN_DGTZ_Success)
  {
      return ret;
  };


//  int yaq[1030],xaq[1030];
  for(int i=0; i<x_range; i++){

//      ofstream myfile;
//      myfile.open(filepath.toStdString(), ios_base::app);

//=====  READ DATA AND SAVE TO TAB  ========
//      x[i] = i;//
//      y[i] = (int)(*((Evt->DataChannel[0])+i));
      xaqh_ch0[i]=(int)i;
      yaqh_ch0[i]=(int)(*((Evt->DataChannel[0])+i));
      xaqh_ch1[i]=i;
      yaqh_ch1[i]=(int)(*((Evt->DataChannel[1])+i));
      xaqh_ch2[i]=i;
      yaqh_ch2[i]=(int)(*((Evt->DataChannel[2])+i));
      xaqh_ch3[i]=i;
      yaqh_ch3[i]=(int)(*((Evt->DataChannel[3])+i));
      xaqh_ch4[i]=i;
      yaqh_ch4[i]=(int)(*((Evt->DataChannel[4])+i)); // Dlaczeg to sie tu wywala? bo maska w wavedump jest ustawiona na 1 nie 255 (najprawdopodobniej)
      xaqh_ch5[i]=i;
      yaqh_ch5[i]=(int)(*((Evt->DataChannel[5])+i)); // Dlaczeg to sie tu wywala?
      xaqh_ch6[i]=i;
      yaqh_ch6[i]=(int)(*((Evt->DataChannel[6])+i)); // Dlaczeg to sie tu wywala?
      xaqh_ch7[i]=i;
      yaqh_ch7[i]=(int)(*((Evt->DataChannel[7])+i)); // Dlaczeg to sie tu wywala?

//==============================================

      int integral_ch0_hist = integral_ch0_hist + yaqh_ch0[i];
      int integral_ch1_hist = integral_ch1_hist + yaqh_ch1[i];
      int integral_ch2_hist = integral_ch2_hist + yaqh_ch2[i];
      int integral_ch3_hist = integral_ch3_hist + yaqh_ch3[i];
      int integral_ch4_hist = integral_ch4_hist + yaqh_ch4[i];
      int integral_ch5_hist = integral_ch5_hist + yaqh_ch5[i];
      int integral_ch6_hist = integral_ch6_hist + yaqh_ch6[i];
      int integral_ch7_hist = integral_ch7_hist + yaqh_ch7[i];

//      yaqh_ch0_hist[1750-5] += 1;

      if(fileFormat==1){
          file <<xaqh_ch0[i]<< "\t" << yaqh_ch0[i] << yaqh_ch1[i] << "\t" << yaqh_ch2[i] << "\t" << yaqh_ch3[i] << "\t" << yaqh_ch4[i] << "\t" << yaqh_ch5[i] << "\t" << yaqh_ch6[i] << "\t" << yaqh_ch7[i] << "\t" << endl;
//      myfile.close();
      }

      else if(fileFormat==0){

      }
  }

//  qSort(yaqh_ch0.begin(), yaqh_ch0.end());
//    min_y_ch0 = yaqh_ch0.first();
//    max_y_ch0 = yaqh_ch0.last();
//  for(int i=0; i<x_range; i++){
//    yaqh_ch0_hist[1750-yaqh_ch0[i]] += 1;
//  }

  return 0;
}


void testowanie(ofstream& file)
{
  //  TFile hfile(file,"RECREATE");

  //  TTree *tree = new TTree("T","An example of a ROOT tree");

    for(int i=1; i<101; i++)
    {
        file << i << endl;
    }
}



