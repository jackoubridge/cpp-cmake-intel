#pragma once
#include <vector>
#include <ipp/ipps.h>

struct DataBlock
{
    Ipp32f* data;
    int dataSize;
    float sampleRate;
};
