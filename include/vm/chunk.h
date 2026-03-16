#ifndef CHUNK_H
#define CHUNK_H

#include "opcodes.h"
#include "constsPool.h"


struct Chunk {
    enum OpCode *bc;
    size_t bcCount;
    struct ConstsPool constants;
};

#endif
