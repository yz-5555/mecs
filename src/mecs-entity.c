#include "mecs-entity.h"
#include "utils/mecs-bitset.h"

#include <stdio.h>

Entity mecs_new_entity(World* world) {
    int array_index = 0;
    size_t len = BITSET_ARRAY_LEN(world->entities_capacity, uint64_t);

    for (int i = 0; i < len; i += 1) {
        if (world->entities[i] != ~0ULL) {
            array_index = i;
            break;
        }
    }

    int entity_index = __builtin_ctz(~(world->entities[array_index]));

    SET_BIT(world->entities[array_index], entity_index);

    return entity_index;
}
void mecs_remove_entity(World* world, Entity entity) {
    if (entity >= world->entities_capacity)
        return;

    int array_index = entity / BITSET_LEN(uint64_t);
    int entity_index = entity % BITSET_LEN(uint64_t);

    CLEAR_BIT(world->entities[array_index], entity_index);
}
bool mecs_is_alive(const World* world, Entity entity) {
    if (entity >= world->entities_capacity)
        return false;

    int array_index = entity / BITSET_LEN(uint64_t);
    int entity_index = entity % BITSET_LEN(uint64_t);

    return (bool)GET_BIT(world->entities[array_index], entity_index);
}
void mecs_print_entities(const World* world) {
    size_t len = BITSET_ARRAY_LEN(world->entities_capacity, uint64_t);
    size_t page_len = BITSET_LEN(uint64_t);

    for (int i = 0; i < len; i += 1) {
        for (int j = 0; j < page_len; j += 1) {
            printf("Entity %llu: ", i * page_len + j);
            if (world->entities[i] >> j & 0x1)
                printf("1\n");
            else
                printf("0\n");
        }
    }
}
