#include <stdio.h>
#include "vm/vm.h"

int
main(int argc, char **argv) {
    enum OpCode bc[] = {
                         LDC, 0, 0, 0,
                         LDC, 0, 0, 1,
                         AddI,
                         Print,
                         LDC, 0, 0, 2,
                         LDC, 0, 0, 3,
                         AddF,
                         Print,
                       };
    size_t bcCount = sizeof(bc) / sizeof(enum OpCode);
    struct Chunk mainChunk = { bc, bcCount };
    mainChunk.constants[0] = (struct Value) { Int, 2  };
    mainChunk.constants[1] = (struct Value) { Int, 3  };
    mainChunk.constants[2] = (struct Value) { Int, .data.r = 2 };
    mainChunk.constants[3] = (struct Value) { Int, .data.r = 3 };
    struct VM vm = newVM();
    vm.chunks[0] = mainChunk;
    initVM(&vm);
    run(&vm);
    return 0;
}
