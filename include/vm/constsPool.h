#ifndef CONSTSPOOL_H
#define CONSTSPOOL_H

#include <stddef.h>
#include "value.h"

#define POOL_SIZE 128

struct ConstsPool {
    struct Value pool[POOL_SIZE];
    size_t count;
};

size_t
getOrCreateConst(struct ConstsPool *pool, struct Value v);

#endif
