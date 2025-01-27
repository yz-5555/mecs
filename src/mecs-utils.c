#include "mecs-utils.h"
#include <stdio.h>

u32 get_bit(Bitset bitset, u32 index) {
    u32 i = index % (sizeof(Bitset) * 8);

    return ((bitset >> i) & 1);
}
void set_bit(Bitset bitset, u32 index, u32 value) {
    if (value == 0)
        bitset &= ~(1UL << index);
    else if (value == 1)
        bitset |= (1UL << index);
}
void print_bitset(const Bitset bitset) {
    for (size_t i = sizeof(bitset) * 8 - 1; i >= 0; i -= 1) {
        printf("%llu", (bitset >> i) & 1);
    }
    printf("\n");
}
