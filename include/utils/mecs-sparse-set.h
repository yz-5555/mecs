#ifndef MECS_SPARSE_SET_H
#define MECS_SPARSE_SET_H

#include <stdint.h>

typedef struct {
    uint32_t* sparse; // sparse array
    void* dense;      // dense array
    size_t size;      // size of the type in dense array
    size_t capacity;  // length of sparse array
    size_t length;    // length of dense array
} SparseSet;

void mecs_init_sparse_set(SparseSet* sparse_set, size_t size, size_t capacity, size_t length);
void mecs_free_sparse_set(SparseSet* sparse_set);
void* mecs_sparse_set_at(const SparseSet* sparse_set, uint32_t index);

#endif
