#pragma once
#include "BleOtaStorage.h"
#include "BleOtaVersion.h"
#include "BleSender.h"
#include "BleOtaUploader.h"
#include <NimBLEDevice.h>

class ArduinoBleOTAClass: public BLECharacteristicCallbacks, public BleSender
{
public:
    bool begin(const std::string& deviceName, OTAStorage& storage);
    bool begin(OTAStorage& storage);
    bool begin(const std::string& deviceName, OTAStorage& storage,
               const std::string& hwName, BleOtaVersion hwVersion,
               const std::string& swName, BleOtaVersion swVersion);
    bool begin(OTAStorage& storage,
               const std::string& hwName, BleOtaVersion hwVersion,
               const std::string& swName, BleOtaVersion swVersion);
    void pull();

private:
    void begin(BLEService& service,
               const std::string& hwName, BleOtaVersion hwVersion,
               const std::string& swName, BleOtaVersion swVersion);
    void onWrite(BLECharacteristic* characteristic) override;
    void send(const uint8_t* data, size_t length);
    BLECharacteristic* txCharacteristic;

protected:
    BleOtaUploader bleOtaUploader;
};

extern ArduinoBleOTAClass ArduinoBleOTA;