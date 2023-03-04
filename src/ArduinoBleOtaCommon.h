#pragma once
#include "BleOtaStorage.h"
#include "BleOtaVersion.h"
#include "BleSender.h"
#include "BleOtaUploader.h"
#include <ArduinoBLE.h>


class ArduinoBleOTAClass: public BleSender
{
public:
    bool begin(const String& deviceName, OTAStorage& storage);
    bool begin(OTAStorage& storage);
    bool begin(const String& deviceName, OTAStorage& storage,
               const String& hwName, BleOtaVersion hwVersion,
               const String& swName, BleOtaVersion swVersion);
    bool begin(OTAStorage& storage,
               const String& hwName, BleOtaVersion hwVersion,
               const String& swName, BleOtaVersion swVersion);
    void pull();

private:
    void begin(const String &hwName, BleOtaVersion hwVersion,
               const String &swName, BleOtaVersion swVersion);
    void send(const uint8_t* data, size_t length) override;

protected:
    BleOtaUploader bleOtaUploader;
};

extern ArduinoBleOTAClass ArduinoBleOTA;