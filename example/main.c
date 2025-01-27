#include "mecs-utils.h"
#include "mecs.h"

#include <stdio.h>

int main(void) {
    Bitset bitset = 0xFFFFFFFFFFFFFFFF;
	printf("Before: %d, %d", 5, get_bit(bitset, 5));
	set_bit(bitset, 5, 0);
	printf("After: %d, %d", 5, get_bit(bitset, 5));
    hi_mecs();

    return 0;
}
