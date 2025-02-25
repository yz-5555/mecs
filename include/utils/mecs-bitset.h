#ifndef MECS_BITSET_H
#define MECS_BITSET_H

#include <limits.h>

#define MECS_BITS_PER(T) (sizeof(T) * CHAR_BIT)

#define MECS_BITSET_ARRAY_LEN(L, T) ((L + MECS_BITS_PER(T) - 1) / MECS_BITS_PER(T))
#define MECS_BITSET_LEN(B) (sizeof(B) * CHAR_BIT)

#define MECS_SET_BIT(B, I) ((B) |= (1U << (I)))
#define MECS_CLEAR_BIT(B, I) ((B) &= ~(1U << (I)))
#define MECS_GET_BIT(B, I) (((B) >> (I)) & 1U)

#endif
