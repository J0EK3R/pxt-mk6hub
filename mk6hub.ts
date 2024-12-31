/// <reference no-default-lib="true"/>
/**
 * Support for MK6 Hub.
 */
//% color=#00c300 weight=100 icon="\uf294" block="MK6 Hub"
namespace mk6hub {

    /**
    *  MK6 Hub Start
    * @param hwid hex HWID, eg: "0f0f0f0f0f"
    */
    //% blockId=mk6hub_start 
    //% block="MK6 Hub start HWID is %hwid"
    //% blockGap=8 weight=60
    // //% help=pxt-mk6hub/start 
    // help は省略すると README が表示される。
    // ※ 認証された拡張パッケージのみであることに注意。任意のときは適切に URL など用意すること
    export function start(hwid: string): void {
        if (hwid.length != 10) {
            // TODO: エラーの返し方がいまいちわからない。
            // 16進数の10桁文字列でない場合は、エラーを返したいのだけれど
            // こっちはシミュレーター側。cpp でも、同じようなバリデーションが必要
        }
        return startWithDeviceMessage(hwid, "00");
    }

    /**
    *  MK6 Hub Start with Device Message. 1 byte to 13 bytes.
    * @param hwid hex HWID, eg: "0f0f0f0f0f"
    * @param message hex Device Message 1byte to 13byte, eg: "1a2b3c4d5e6f70809010a0b0c0"
    */
    //% blockId=mk6hub_start_with_devicemessage
    //% block="MK6 Hub start HWID is %hwid|with Device Message %message"
    //% shim=mk6hub::startWithDeviceMessage
    //% blockGap=8 weight=55 blockExternalInputs=1
    // //% help=pxt-mk6hub/start-with-device-message
    export function startWithDeviceMessage(hwid: string, message: string): void {
        if (hwid.length != 10) {
            // TODO: エラーの返し方がいまいちわからない。Display 使う
            basic.clearScreen();
            basic.showString("HWID is invalid.");

        }
        if (message.length > 26 || message.length % 2 != 0) {
            // TODO: エラーの返し方がいまいちわからない。Display 使う
            basic.clearScreen();
            basic.showString("Massage is invalid.");
        }
        return;
    }


    /**
     * Stops advertising MK6 Hub end points
     */
    //% blockId=mk6hub_stop
    //% block="MK6 Hub stop"
    //% shim=mk6hub::stop
    //% weight=10 blockGap=8 advanced=true
    export function stop() {
        return;
    };

//     /**
//      * Stops advertising MK6 Hub end points
//      */
//     //% blockId=mk6hub_central
//     //% block="MK6 Hub central"
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