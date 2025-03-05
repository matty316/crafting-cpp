#include "chunk.h"

void writeChunk(Chunk& chunk, uint8_t byte) {
    chunk.code.push_back(byte);
}

int addConstant(Chunk& chunk, Value value) {
    chunk.constants.push_back(value);
    return chunk.constants.size() - 1;
}
