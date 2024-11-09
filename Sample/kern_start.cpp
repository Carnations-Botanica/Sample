//
//  kern_start.cpp
//  Sample
//
//  Created by royalgraphx on 11/9/24.
//

#include "kern_start.hpp"

// Main Function
void sampleInit() {

    // Say hello!
    DBGLOG(MODULE_SHORT, "Hello World from Sample.kext!");
    SYSLOG(MODULE_SHORT, "Hello World from Sample.kext!");

}

const char *bootargOff[] {
    "-smpleoff"
};

const char *bootargDebug[] {
    "-smpledbg"
};

const char *bootargBeta[] {
    "-smplebeta"
};

PluginConfiguration ADDPR(config) {
    xStringify(PRODUCT_NAME),
    parseModuleVersion(xStringify(MODULE_VERSION)),
    LiluAPI::AllowNormal |
    LiluAPI::AllowSafeMode |
    LiluAPI::AllowInstallerRecovery,
    bootargOff,
    arrsize(bootargOff),
    bootargDebug,
    arrsize(bootargDebug),
    bootargBeta,
    arrsize(bootargBeta),
    KernelVersion::Mavericks,
    KernelVersion::Sequoia,
    []() {
        sampleInit();
    }
};
