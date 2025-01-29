#ifndef MECS_SPARSESET_H
#define MECS_SPARSESET_H

#include <stdint.h>
#include "mecs-constants.h"

typedef struct {
    void* sparse;
    uint32_t dense[MAX_ENTITIES];
    size_t size;
    uint32_t length;
} SparseSet;

#endif
