#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int agrc, const char* argv[]) {
    Chunk chunk;
    writeChunk(chunk, OP_RETURN);
    disassembleChunk(chunk, "test chunk");
    return 0;
}
