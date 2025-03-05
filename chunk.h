#pragma once

#include "common.h"
#include "value.h"
#include <vector>

enum OpCode {
    OP_CONSTANT,
    OP_RETURN
};

struct Chunk {
    std::vector<uint8_t> code;
    std::vector<Value> constants;
};

void writeChunk(Chunk& chunk, uint8_t byte);
int addConstant(Chunk& chunk, Value value);
