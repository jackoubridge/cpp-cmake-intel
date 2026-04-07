#pragma once
#include <oneapi/tbb.h>
#include <ipp/ipps.h>
#include <fstream>
#include "data_block.h"
#include <iostream>

class FileReaderNode
{
public:
    tbb::flow::input_node<DataBlock> node;

    FileReaderNode(tbb::flow::graph& g);
};
