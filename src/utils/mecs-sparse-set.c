#include "utils/mecs-sparse-set.h"
#include <stdlib.h>

void mecs_init_sparse_set(SparseSet* sparse_set, size_t size, size_t capacity, size_t length) {
    sparse_set->sparse = malloc(capacity * sizeof(size_t));
    sparse_set->dense = malloc(length * size);
    sparse_set->size = size;

    sparse_set->capacity = capacity;
    sparse_set->length = length;
}
void mecs_free_sparse_set(SparseSet* sparse_set) {
    free(sparse_set->sparse);
    free(sparse_set->dense);
}
void* mecs_sparse_set_at(const SparseSet* sparse_set, size_t index) {
    if (index >= sparse_set->capacity)
        return NULL;

    size_t i = sparse_set->sparse[index];
    if (i >= sparse_set->length)
        return NULL;

    return (void*)((char*)sparse_set->dense + index * sparse_set->size);
}
