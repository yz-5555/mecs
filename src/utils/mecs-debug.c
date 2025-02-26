#include "utils/mecs-debug.h"
#include "utils/mecs-bitset.h"

#include <stdint.h>
#include <stdio.h>

// TODO: Design better logic. Currently not functional and not looks that efficient.
void mecs_print_entities(const MecsWorld* world) {
    size_t len = MECS_BITSET_ARRAY_LEN(world->entities_capacity, uint64_t);
    size_t page_len = MECS_BITSET_LEN(uint64_t);

    for (size_t i = 0; i < len - 1; i += 1) {
        for (size_t j = 0; j < page_len; j += 1) {
            printf("Entity %llu: ", i * page_len + j);
            if (world->entities[i] >> j & 0x1)
                printf("true\n");
            else
                printf("false\n");
        }
    }
    for (size_t i = 0; i < (world->entities_capacity % page_len); i += 1) {
        printf("Entity %llu: ", (len - 1) * page_len + i);
        if (world->entities[len - 1] >> i & 0x1)
            printf("true\n");
        else
            printf("false\n");
    }
}
