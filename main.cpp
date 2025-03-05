#include "chunk.h"
#include "common.h"
#include "debug.h"

int main(int agrc, const char *argv[]) {
  Chunk chunk;
  int constant = addConstant(chunk, 1.2);
  writeChunk(chunk, OP_CONSTANT, 123);
  writeChunk(chunk, constant, 123);
  writeChunk(chunk, OP_RETURN, 123);

  disassembleChunk(chunk, "test chunk");
  return 0;
}
