#include "utils/mecs-sparse-set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mecs_sparse_set_init(MecsSparseSet *sparse_set, size_t size, size_t capacity, size_t length) {
    sparse_set->sparse = malloc(capacity * sizeof(size_t));
    sparse_set->dense = malloc(length * size);
    sparse_set->size = size;
    sparse_set->capacity = capacity;
    sparse_set->length = length;
}
void mecs_sparse_set_free(MecsSparseSet *sparse_set) {
    free(sparse_set->sparse);
    free(sparse_set->dense);
}
void *mecs_sparse_set_index(const MecsSparseSet *sparse_set, size_t index) {
    if (index >= sparse_set->capacity)
        return NULL;

    size_t i = sparse_set->sparse[index];
    if (i >= sparse_set->length)
        return NULL;

    return (void *)((char *)sparse_set->dense + i * sparse_set->size);
}
void mecs_sparse_set_set(MecsSparseSet *sparse_set, size_t index, const void *value) {
    if (index >= sparse_set->capacity)
        return;

	size_t i = sparse_set->sparse[index];
	if (i >= sparse_set->length)
		return;

    memcpy(
        (char *)sparse_set->dense + i * sparse_set->size,
        value,
        sparse_set->size);
}
void mecs_sparse_set_push_back(MecsSparseSet *sparse_set, const void *value) {
}
