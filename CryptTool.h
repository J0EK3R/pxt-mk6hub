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
    void enCrypt(const uint8_t *addr, const uint8_t addrLength, const uint8_t *data, const uint8_t dataLength, const uint8_t ctxValue);
};

//================================================================
#else // MICROBIT_CODAL
//================================================================

//================================================================
#endif // MICROBIT_CODAL
//================================================================

#endif