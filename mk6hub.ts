/// <reference no-default-lib="true"/>
/**
 * Support for MK6 Hub.
 */
//% color=#00c300 weight=100 icon="\uf294" block="MK6Hub"
namespace mk6hub {

    // color="#00c300" weight=100 icon="\uf3c0"

    /**
    *  MK6Hub Start
    * @param hwid hex HWID, eg: "0f0f0f0f0f"
    */
    //% blockId=mk6hub_start 
    //% block="MK6Hub start HWID is %hwid"
    //% blockGap=8 weight=60
    // //% help=pxt-mk6hub/start 
    export function start(hwid: string): void {
        if (hwid.length != 10) {
        }
        return startWithDeviceMessage(hwid, "00");
    }

    /**
    *  MK6Hub Start with Device Message. 1 byte to 13 bytes.
    * @param hwid hex HWID, eg: "0f0f0f0f0f"
    * @param message hex Device Message 1byte to 13byte, eg: "1a2b3c4d5e6f70809010a0b0c0"
    */
    //% blockId=mk6hub_start_with_devicemessage
    //% block="MK6Hub start HWID is %hwid|with Device Message %message"
    //% shim=mk6hub::startWithDeviceMessage
    //% blockGap=8 weight=55 blockExternalInputs=1
    // //% help=pxt-mk6hub/start-with-device-message
    export function startWithDeviceMessage(hwid: string, message: string): void {
        if (hwid.length != 10) {
            basic.clearScreen();
            basic.showString("HWID is invalid.");

        }
        if (message.length > 26 || message.length % 2 != 0) {
            basic.clearScreen();
            basic.showString("Massage is invalid.");
        }
        return;
    }


    /**
     * Stops advertising MK6Hub end points
     */
    //% blockId=mk6hub_stop
    //% block="MK6 Hub stop"
    //% shim=mk6hub::stop
    //% weight=10 blockGap=8 advanced=true
    export function stop() {
        return;
    };

//     /**
//      * Stops advertising MK6Hub end points
//      */
//     //% blockId=mk6hub_central
//     //% block="MK6Hub central"
//     //% weight=10 blockGap=8 advanced=true
//     //% group="micro:bit (V2)"
//     export function onCentralEvent() {
//         #if MICROBIT_CODAL
//         registerWithDal(uBit.logo.id, action, body);
// #else
//         target_panic(PANIC_VARIANT_NOT_SUPPORTED);
// #endif
//         return;
//     };
}