#include "vm/constsPool.h"
#include <assert.h>

size_t
getOrCreateConst(struct ConstsPool *pool, struct Value v) {
    size_t i = 0;
    for (; i < pool->count; ++i) {
        if (cmpVals(pool->pool[i], v)) {
            return i;
        }
    }
    // TODO: replace to own error handler
    assert(pool->count < POOL_SIZE && "Pool overflow!");
    pool->pool[i] = v;
    ++pool->count;
    return i;
}
