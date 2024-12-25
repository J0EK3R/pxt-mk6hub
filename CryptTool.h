#ifndef CRYPTTOOL_H
#define CRYPTTOOL_H

#include "MicroBitConfig.h"
#include "pxt.h"

//================================================================
#if MICROBIT_CODAL
//================================================================

class CryptTool
{
    public:
    void get_rf_payload(const uint8_t *addr, const uint8_t addrLength, const uint8_t *data, const uint8_t dataLength, const uint8_t ctxValue);

    private:
    const uint8_t ctxValue = 0x25;
    const uint8_t addressArray[5] = {0xC1, 0xC2, 0xC3, 0xC4, 0xC5};
};

//================================================================
#else // MICROBIT_CODAL
//================================================================

//================================================================
#endif // MICROBIT_CODAL
//================================================================

#endif