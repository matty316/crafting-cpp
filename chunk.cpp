#include "chunk.h"

void writeChunk(Chunk& chunk, uint8_t byte) {
    chunk.code.push_back(byte);
}
