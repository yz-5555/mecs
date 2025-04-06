#include "mecs-world.h"

#include "utils/mecs-bitset.h"
#include "utils/mecs-sparse-set.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MecsWorld *mecs_world_new(size_t entities_capacity, size_t components_capacity) {
    MecsWorld *world = malloc(sizeof(MecsWorld));
    if (!world)
        return NULL;

    // Initialize array of entity bitsets
    size_t len = MECS_BITSET_ARRAY_LEN(entities_capacity, uint64_t);
    world->entities = malloc(len * sizeof(uint64_t));
    if (!world->entities)
        return NULL;
    memset(world->entities, 0, len * sizeof(uint64_t));

    world->entities_capacity = entities_capacity;

    world->entities_allocated_capacity = MECS_ENTITIES_BITSET_LEN * len;

    // Initialize array of component sparse sets
    world->components = malloc(components_capacity * sizeof(MecsSparseSet));
    if (!world->components)
        return NULL;

    world->components_capacity = components_capacity;

    return world;
}
void mecs_world_free(MecsWorld *world) {
    mecs_sparse_set_free(world->components);
    free(world);
}
MecsEntity mecs_entity_new(MecsWorld *world) {
    size_t array_index = 0;
    size_t len = MECS_BITSET_ARRAY_LEN(world->entities_capacity, uint64_t);

    for (size_t i = 0; i < len; i += 1) {
        if (world->entities[i] != ~(MecsEntityBitset)0) {
            array_index = i;
            break;
        }
    }

    size_t entity_index = mecs_count_trailing_zero(~(world->entities[array_index]));

    MECS_SET_BIT(world->entities[array_index], entity_index, MecsEntityBitset);

    return entity_index;
}
MecsEntity mecs_component_new(MecsWorld *world) {
    MecsEntity e;
    return e;
}
void mecs_component_set(MecsWorld *world, MecsEntity component_entity) {
}
void mecs_component_remove(MecsWorld *world, MecsEntity component_entity) {
}
