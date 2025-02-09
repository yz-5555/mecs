#include "mecs-world.h"
#include "utils/mecs-bitset.h"
#include "utils/mecs-sparse-set.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

World* mecs_new_world(size_t entities_capacity, size_t components_capacity) {
    World* world = malloc(sizeof(World));
    if (!world)
        return NULL;

    // Initialize array of entity bitsets
    world->entities = malloc(BITSET_ARRAY_LEN(entities_capacity, uint64_t) * sizeof(uint64_t));
    if (!world->entities)
        return NULL;
    memset(world->entities, 0, BITSET_ARRAY_LEN(entities_capacity, uint64_t) * sizeof(uint64_t));

    world->entities_capacity = entities_capacity;

    // Initialize array of component sparse sets
    world->components = malloc(components_capacity * sizeof(SparseSet));
    if (!world->components)
        return NULL;

    world->components_capacity = components_capacity;

    return world;
}
void mecs_free_world(World* world) {
    mecs_free_sparse_set(world->components);
    free(world);
}
Entity mecs_new_entity(World* world) {
    size_t array_index = 0;
    size_t len = BITSET_ARRAY_LEN(world->entities_capacity, uint64_t);

    for (size_t i = 0; i < len; i += 1) {
        if (world->entities[i] != ~0ULL) {
            array_index = i;
            break;
        }
    }

    size_t entity_index = __builtin_ctz(~(world->entities[array_index]));

    SET_BIT(world->entities[array_index], entity_index);

    return entity_index;
}
void mecs_remove_entity(World* world, Entity entity) {
    if (entity >= world->entities_capacity)
        return;

    size_t array_index = entity / BITSET_LEN(uint64_t);
    size_t entity_index = entity % BITSET_LEN(uint64_t);

    CLEAR_BIT(world->entities[array_index], entity_index);
}
bool mecs_is_alive(const World* world, Entity entity) {
    if (entity >= world->entities_capacity)
        return false;

    size_t array_index = entity / BITSET_LEN(uint64_t);
    size_t entity_index = entity % BITSET_LEN(uint64_t);

    return (bool)GET_BIT(world->entities[array_index], entity_index);
}
void mecs_print_entities(const World* world) {
    size_t len = BITSET_ARRAY_LEN(world->entities_capacity, uint64_t);
    size_t page_len = BITSET_LEN(uint64_t);

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
