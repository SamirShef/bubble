#include <stdio.h>
#include "vm/vm.h"
#include <stdlib.h>

int
main(int argc, char **argv) {
    enum OpCode bc[] = {
                         LDC, 0, 0, 0,
                         LDC, 0, 0, 1,
                         AddI,
                         LDG, 0, 0, 0,
                         AddI,
                         Print,
                         LDC, 0, 0, 2,
                         LDC, 0, 0, 3,
                         AddF,
                         Print,
                       };
    size_t bcCount = sizeof(bc) / sizeof(enum OpCode);
    struct Chunk mainChunk = { bc, bcCount, { .count = 0 } };
    getOrCreateConst(&mainChunk.constants, (struct Value) { Int, 2  });
    getOrCreateConst(&mainChunk.constants, (struct Value) { Int, 3  });
    getOrCreateConst(&mainChunk.constants, (struct Value) { Int, .data.r = 2 });
    getOrCreateConst(&mainChunk.constants, (struct Value) { Int, .data.r = 3 });
    struct VM vm = newVM();
    emitGlob(&vm, (struct Value) { Int, 5  });
    vm.chunks[0] = mainChunk;
    initVM(&vm);
    run(&vm);
    return 0;
}
