#include "vm/vm.h"
#include <assert.h>
#include <stdio.h>

struct VM
newVM() {
    struct VM vm = { .ip = NULL  };
    vm.stackTop = vm.stackBegin = vm.stack;
    vm.stackEnd = vm.stack + STACK_SIZE;
    return vm;
}

void
initVM(struct VM *vm) {
    vm->ip = vm->chunks[0].bc;
}

size_t
getIndex(struct VM *vm) {
#define PART(n, a) size_t n = (*vm->ip++ << (a)) & 0xFF
    PART(major, 24);
    PART(middle, 8);
    PART(minor, 0);
    return major | middle | minor;
#undef PART
}

struct Value
pop(struct VM *vm) {
    // TODO: replace assert to own error handler
    assert(vm->stackTop > vm->stackBegin && "Stack underflow!");
    return *vm->stackTop--;
}

void
push(struct VM *vm, struct Value v) {
    // TODO: replace assert to own error handler
    assert(vm->stackTop < vm->stackEnd && "Stack overflow!");
    *++vm->stackTop = v;
}

void
run(struct VM *vm) {
    // TODO: storing max ip into VM instead comparing
    //       with lastIp
    struct Chunk *chunk = &vm->chunks[0];
    enum OpCode *lastIp = chunk->bc + chunk->bcCount;
    while (vm->ip < lastIp) {
        switch (*vm->ip++) {
            case LDC: {
                size_t index = getIndex(vm);
                printf("ldc: %zu\n", index);
                push(vm, /*chunk->constants[index]*/
                /* TODO: crate this function:*/
                     chunk->constants.pool[index]
                );
                break;
            }
            case LDG:
                printf("ldg: %zu\n", getIndex(vm));
                break;
            case AddI: {
                printf("addi:\n");
                struct Value b = pop(vm);
                printf("  b = %ld\n", b.data.i);
                struct Value a = pop(vm);
                printf("  a = %ld\n", a.data.i);
                push(vm, (struct Value) { Int, .data.i =
                                          a.data.i + b.data.i  });
                break;
            }
            case AddF: {
                printf("addf:\n");
                struct Value b = pop(vm);
                printf("  b = %g\n", b.data.r);
                struct Value a = pop(vm);
                printf("  a = %g\n", a.data.r);
                push(vm, (struct Value) { Real, .data.r =
                                          a.data.r + b.data.r  });
                break;
            }
            case Print: {
                printf("print:\n");
                struct Value v = pop(vm);
                if (v.type == Int) {
                    printf("  Int %ld\n", v.data.i);
                }
                else {
                    printf("  Real %g\n", v.data.r);
                }
                break;
            }
        }
    }
    printf("\033[1;34mExecution successfully!\n\033[0m");
}
