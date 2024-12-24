#include "MicroBitConfig.h"
#include "CryptTool.h"

//================================================================
#if MICROBIT_CODAL
//================================================================

#include <stdbool.h>
#include <stdint.h>

static uint8_t invert_8(uint8_t value) 
{
    uint8_t result = 0;
    for (int index = 0; index < 8; ++index) {
        if ((value & (1 << index)) != 0) {
            result |= (1 << (7 - index));
        }
    }
    return result;
}

static uint16_t invert_16(uint16_t value) 
{
    uint16_t result = 0;
    for (int index = 0; index < 16; ++index) {
        if ((value & (1 << index)) != 0) {
            result |= (1 << (15 - index));
        }
    }
    return result;
}

static uint16_t check_crc16(const uint8_t* array1, uint8_t array1Length, const uint8_t* array2, uint8_t array2Length) 
{
    uint16_t result = 0xffff;
    for (uint8_t index = 0; index < array1Length; ++index) {
        result ^= static_cast<uint16_t>(array1[array1Length - 1 - index] << 8);

        for (uint8_t local_24 = 0; local_24 < 8; ++local_24) {
            if ((result & 0x8000) == 0) {
                result <<= 1;
            } else {
                result = (result << 1) ^ 0x1021;
            }
        }
    }

    for (uint8_t index = 0; index < array2Length; ++index) {
        uint8_t cVar1 = invert_8(array2[index]);

        result ^= static_cast<uint16_t>(cVar1 << 8);

        for (uint8_t local_2c = 0; local_2c < 8; ++local_2c) {
            if ((result & 0x8000) == 0) {
                result <<= 1;
            } else {
                result = (result << 1) ^ 0x1021;
            }
        }
    }

    uint16_t result_inverse = invert_16(result);
    return static_cast<uint16_t>(result_inverse ^ 0xffff);
}


static void whitening_init(uint8_t val, uint8_t ctx[7]) {
    ctx[0] = 1;
    ctx[1] = (val >> 5) & 1;
    ctx[2] = (val >> 4) & 1;
    ctx[3] = (val >> 3) & 1;
    ctx[4] = (val >> 2) & 1;
    ctx[5] = (val >> 1) & 1;
    ctx[6] = val & 1;
}

static uint8_t whitening_output(uint8_t ctx[7]) {
    uint8_t value_3 = ctx[3];
    uint8_t value_6 = ctx[6];
    ctx[3] = ctx[2];
    ctx[2] = ctx[1];
    ctx[1] = ctx[0];
    ctx[0] = ctx[6];
    ctx[6] = ctx[5];
    ctx[5] = ctx[4];
    ctx[4] = value_3 ^ value_6;
    return ctx[0];
}

// static void whitening_encode(uint8_t data[], int dataStartIndex, int len, uint8_t ctx[7]) {
//     for (int index = 0; index < len; ++index) {
//         uint8_t currentByte = data[dataStartIndex + index];
//         int currentResult = 0;
//         for (int bitIndex = 0; bitIndex < 8; ++bitIndex) {
//             uint8_t uVar2 = whitening_output(ctx);
//             currentResult = (uVar2 ^ ((currentByte >> bitIndex) & 1U)) << bitIndex | currentResult;
//         }
//         data[dataStartIndex + index] = static_cast<uint8_t>(currentResult);
//     }
// }

void CryptTool::enCrypt(const uint8_t *addr, const uint8_t addrLength, const uint8_t *data, const uint8_t dataLength, const uint8_t ctxValue) {

    MICROBIT_DEBUG_DMESG("CryptTool::enCrypt");

}

//================================================================
#else // MICROBIT_CODAL
//================================================================


//================================================================
#endif // MICROBIT_CODAL
//================================================================
