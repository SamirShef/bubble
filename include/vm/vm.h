#ifndef VM_H
#define VM_H

#include "value.h"
#include "chunk.h"

#define STACK_SIZE 128

struct VM {
    struct Value globs[128];
    struct Chunk chunks[128];
    enum OpCode *ip;
    struct Value stack[STACK_SIZE];
    struct Value *stackTop, *stackBegin, *stackEnd;
};

struct VM
newVM();

void
initVM(struct VM *vm);

size_t
getIndex(struct VM *vm);

struct Value
pop(struct VM *vm);

void
push(struct VM *vm, struct Value v);

void
run(struct VM *vm);

#endif
