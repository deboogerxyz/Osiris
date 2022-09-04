#pragma once

#include "Inconstructible.h"
#include "Pad.h"
#include "Platform.h"
#include "VirtualMethod.h"

class NetworkChannel {
public:
    INCONSTRUCTIBLE(NetworkChannel)

    VIRTUAL_METHOD(float, getLatency, 9, (int flow), (this, flow))

    PAD(WIN32_LINUX(24, 44))
    int outSequenceNumber;
    int inSequenceNumber;
    int outSequenceNumberAcknowledge;
    int outReliableState;
    int inReliableState;
    int chokedPackets;
};
