#ifndef MECS_BITSET_H
#define MECS_BITSET_H

#include <limits.h>

#define BITSET_ARRAY_LENGTH(L, T) ((L + BITS_PER(T) - 1) / BITS_PER(T))

#define BITS_PER(T) (sizeof(T) * CHAR_BIT)
#define GET_BITSET_LENGTH(B) (sizeof(B) * CHAR_BIT)

#define SET_BIT(B, I) ((B) |= (1U << (I)))
#define CLEAR_BIT(B, I) ((B) &= ~(1U << (I)))
#define GET_BIT(B, I) (((B) >> (I)) & 1U)

#endif
