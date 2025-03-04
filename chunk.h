#pragma once

#include "common.h"
#include <vector>

enum OpCode {
    OP_RETURN
};

struct Chunk {
    std::vector<uint8_t> code;
};

void writeChunk(Chunk& chunk, uint8_t byte);
