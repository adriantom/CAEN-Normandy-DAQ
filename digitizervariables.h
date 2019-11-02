#ifndef DIGITIZERVARIABLES_H
#define DIGITIZERVARIABLES_H
//extern uint32_t ChannelEnableMask[8];
#endif // DIGITIZERVARIABLES_H
//#include "CAENDigitizer.h"

#include <cmath>
#include <iostream>

using namespace  std;
/*
class DigitizerVaribles
{
public:
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
};
*/
//========== VARIABLES ===================

// digitizer configuration
/*
static double PostTriggSize = 0.00;
static int AcquisitionMode = 0;
static int DESM = 0;
static int DecimationFactor = 0;

static double RecordLength [8] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
//static uint32_t ChannelEnableMask [8] = {0,0,0,0,0,0,0,0};
//double ChannelDCOffset [9] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
static int ChannelDCOffset [8] = {0,0,0,0,0,0,0,0};
*/

// trigger configuration
/*
static int SoftwareTriggerMode = 0;
static int ExternalTriggerInputMode = 0;
static int IOLevel = 0;
static int RunSynchronizationMode = 0;

static int TriggerPolarity [8] = {0,0,0,0,0,0,0,0};
static double ChannelTriggerThreshold [8] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
static int ChannelSelfTrigger [8] = {0,0,0,0,0,0,0,0};
*/
//int Maseczka()//(uint32_t ChEnableMask [8])
//{
/*
    uint32_t Mask_temp = 0;

    for(int i=0;i<8;i++){
        Mask_temp = Mask_temp + std::pow(2,i) * (uint32_t)ChEnableMask[i];
    }
    cout << "Mask " << Mask_temp << endl;

    return Mask_temp;
    */
//}

