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

void printValue(Value value) {
    printf("%g", value);
}

static size_t constantInstruction(const char* name, Chunk& chunk, size_t offset) {
    uint8_t constant = chunk.code[offset + 1];
    printf("%-16s %4d '", name, constant);
    printValue(chunk.constants[constant]);
    printf("'\n");
    return offset + 2;
}

size_t disassembleInstruction(Chunk& chunk, size_t offset) {
    printf("%04lu ", offset);

    uint8_t instruction = chunk.code[offset];
    switch (instruction) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        default:
            std::cout << "Unknown OpCode\n";
            return offset + 1;
    }
}

