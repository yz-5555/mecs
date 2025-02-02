#ifndef MECS_BITSET_H
#define MECS_BITSET_H

#include <limits.h>

#define BITS_PER(T) (sizeof(T) * CHAR_BIT)

#define BITSET_ARRAY_LEN(L, T) ((L + BITS_PER(T) - 1) / BITS_PER(T))
#define BITSET_LEN(B) (sizeof(B) * CHAR_BIT)

#define SET_BIT(B, I) ((B) |= (1U << (I)))
#define CLEAR_BIT(B, I) ((B) &= ~(1U << (I)))
#define GET_BIT(B, I) (((B) >> (I)) & 1U)

#endif
