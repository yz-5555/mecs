#ifndef MECS_SPARSESET_H
#define MECS_SPARSESET_H

#include "mecs-constants.h"
#include <stdint.h>

typedef struct {
    void* sparse;
    uint32_t dense[MAX_ENTITIES];
    size_t element_size;
    uint32_t set_size;
} SparseSet;

void mecs_init_sparse_set(SparseSet* sparse_set);
void mecs_free_sparse_set(SparseSet* sparse_set);

#endif
