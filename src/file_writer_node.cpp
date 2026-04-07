#include "file_writer_node.h"

FileWriterNode::FileWriterNode(tbb::flow::graph& g)
    : node(g, tbb::flow::serial, [](const DataBlock& block)
    {
	    std::ofstream file("tone-out.raw", std::ios::binary);

	    file.write(
		    reinterpret_cast<const char*>(block.data),
		    block.dataSize * sizeof(float)
	    );

	    ippsFree(block.data);
    })
{}
