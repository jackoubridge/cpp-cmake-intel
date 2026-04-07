#pragma once
#include <oneapi/tbb.h>
#include <ipp/ipps.h>
#include "data_block.h"
#include <fstream>

class FileWriterNode
{
public:
    tbb::flow::function_node<DataBlock> node;

    FileWriterNode(tbb::flow::graph& g);
};
