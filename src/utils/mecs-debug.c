#include "utils/mecs-debug.h"
#include "utils/mecs-bitset.h"

#include <stdint.h>
#include <stdio.h>

void mecs_print_entities(const MecsWorld* world) {
    size_t len = MECS_BITSET_ARRAY_LEN(world->entities_capacity, uint64_t);
    size_t page_len = MECS_BITSET_LEN(uint64_t);

    for (size_t i = 0; i < len; i += 1) {
        for (size_t j = 0; j < page_len; j += 1) {
            printf("Entity %llu: ", i * page_len + j);
            if (world->entities[i] >> j & 0x1)
                printf("1\n");
            else
                printf("0\n");
        }
    }
}
