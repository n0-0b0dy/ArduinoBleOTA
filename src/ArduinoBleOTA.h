#pragma once

#ifdef USE_NIM_BLE_ARDUINO_LIB
#include "ArduinoBleOtaNimBle.h"
#else
#ifdef USE_ARDUINO_BLE
#include "ArduinoBleOtaCommon.h"
#ifndef BLE_PULL_REQUIRED
    #define BLE_PULL_REQUIRED
#endif
#endif
#endif