#include "pxt.h"
#include "MK6HubService.h"
#include <stdio.h>
#include <ctype.h>
#include "MicroBitConfig.h"

using namespace pxt;

/**
 * Support for MK6 Hub.
 */
//% color=#00c300 weight=100 icon="\uf294" block="MK6 Hub"
namespace mk6hub {

    MK6HubService* _pService[3] = {
        NULL,
        NULL,
        NULL
    };

    MK6HubService* getService(uint8_t hubNo) {

        MK6HubService *pService = _pService[hubNo];

        if (NULL == pService)
        {
#if MICROBIT_CODAL
            pService = new MK6HubService(hubNo);
#else
            pService = new MK6HubService(hubNo, *uBit.ble);
#endif
            _pService[hubNo] = pService;
        }

        return pService;
    }

    //%
    void init(uint8_t hubNo) {

        MK6HubService *pService = getService(hubNo);

        pService->connect();
    }


    //% 
    void setChannel(uint8_t hubNo, uint8_t channel, float value) {        

        MK6HubService *pService = getService(hubNo);

        pService->setChannel(channel, value);
    }   


    //% 
    void setChannelOffset(uint8_t hubNo, uint8_t channel, float value) {        

        MK6HubService *pService = getService(hubNo);

        pService->setChannelOffset(channel, value);
    }   


    //% 
    void sendData(uint8_t hubNo) {        

        MK6HubService *pService = getService(hubNo);

        pService->sendData();
    }   


    //% 
    void stop(uint8_t hubNo) {        

        MK6HubService *pService = getService(hubNo);

        if (NULL != pService) {
            pService->stop();
        }        
    }   


    //% 
    uint8_t getVersion(uint8_t hubNo) {        

        MK6HubService *pService = getService(hubNo);

        return pService->getVersion();
    }   
}