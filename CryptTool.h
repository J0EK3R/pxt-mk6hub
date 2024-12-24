#ifndef CRYPTTOOL_H
#define CRYPTTOOL_H

#include "MicroBitConfig.h"
#include "pxt.h"

class CryptTool
{
public:
    void EnCrypt(uint8_t *addr, uint8_t addrLength, uint8_t *data, uint8_t dataLength, uint8_t ctxValue);
};

#endif