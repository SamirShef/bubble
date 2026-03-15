#ifndef VALUE_H
#define VALUE_H

#include <stdint.h>

enum ValueType {
    Int,
    Real
};

struct Value {
    enum ValueType type;
    union {
        int64_t i;
        double r;
    } data;
};

#endif
