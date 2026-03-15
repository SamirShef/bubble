#ifndef CHUNK_H
#define CHUNK_H

#include "opcodes.h"
#include "value.h"

#define CONSTS_SIZE 128

struct Chunk {
    enum OpCode *bc;
    size_t bcCount;
    struct Value constants[CONSTS_SIZE];
};

#endif
