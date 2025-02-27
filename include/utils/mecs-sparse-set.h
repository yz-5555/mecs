#ifndef MECS_SPARSE_SET_H
#define MECS_SPARSE_SET_H

#include <stdint.h>

typedef struct MecsSparseSet {
    size_t *sparse;  // Sparse array
    void *dense;     // Dense array
    size_t size;     // Size of the type in dense array
    size_t capacity; // Length of sparse array
    size_t length;   // Length of dense array
} MecsSparseSet;

void mecs_sparse_set_init(MecsSparseSet *sparse_set, size_t size, size_t capacity, size_t length);
void mecs_sparse_set_free(MecsSparseSet *sparse_set);
void *mecs_sparse_set_index(const MecsSparseSet *sparse_set, size_t index);

#define MECS_SPARSE_SET_INDEX(sparse_set_ptr, index, T) ((const T *)mecs_sparse_set_index(sparse_set_ptr, index))

#endif
