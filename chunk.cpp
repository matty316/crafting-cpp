#include "chunk.h"

void writeChunk(Chunk &chunk, uint8_t byte, int line) {
  chunk.code.push_back(byte);
  chunk.lines.push_back(line);
}

int addConstant(Chunk &chunk, Value value) {
  chunk.constants.push_back(value);
  return chunk.constants.size() - 1;
}
