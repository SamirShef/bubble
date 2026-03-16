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

#define cmpVals(v1, v2) (v1.type == v2.type     && \
                         v1.data.i == v2.data.i && \
                         v1.data.r == v2.data.r)

#endif
