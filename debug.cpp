#include "debug.h"
#include "chunk.h"
#include <cstddef>
#include <iostream>

void disassembleChunk(Chunk& chunk, const char* name) {
    std::cout << "== " << name << " ==\n";

    for (size_t offset = 0; offset < chunk.code.size();) {
        offset = disassembleInstruction(chunk, offset);
    }
}

static size_t simpleInstruction(const char* name, size_t offset) {
    std::cout << name << "\n"; 
    return offset + 1;
}

size_t disassembleInstruction(Chunk& chunk, size_t offset) {
    printf("%04lu ", offset);

    uint8_t instruction = chunk.code[offset];
    switch (instruction) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            std::cout << "Unknown OpCode\n";
            return offset + 1;
    }
}

