#ifndef OPCODES_H
#define OPCODES_H

enum OpCode {
#define OP(n) n,
#include "opcodes.def"
#undef OP
};

#endif
