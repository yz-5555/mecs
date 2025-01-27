#ifndef MECS_UTILS_H
#define MECS_UTILS_H

#include <stdint.h>
#include <stdbool.h>

#define MAX_COMPONENTS 32
#define MAX_ENTITIES 1000

typedef uint32_t u32;

typedef struct {
	void* sparse;
	u32 dense[MAX_ENTITIES];
	size_t size;
	u32 count;
} SparseSet;

// Bitset
#define BITSET_BLOCKS(COUNT) (COUNT / (sizeof(uint64_t) * 8) + 1)

typedef uint64_t Bitset;

u32 get_bit(Bitset bitset, u32 index);
void set_bit(Bitset bitset, u32 index, u32 value);
void print_bitset(const Bitset bitset);

#endif
