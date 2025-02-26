#include "mecs-world.h"

#include "utils/mecs-bitset.h"
#include "utils/mecs-sparse-set.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MecsWorld* mecs_world_new(size_t entities_capacity, size_t components_capacity) {
    MecsWorld* world = malloc(sizeof(MecsWorld));
    if (!world)
        return NULL;

    // Initialize array of entity bitsets
    world->entities = malloc(MECS_BITSET_ARRAY_LEN(entities_capacity, uint64_t) * sizeof(uint64_t));
    if (!world->entities)
        return NULL;
    memset(world->entities, 0, MECS_BITSET_ARRAY_LEN(entities_capacity, uint64_t) * sizeof(uint64_t));

    world->entities_capacity = entities_capacity;

    // Initialize array of component sparse sets
    world->components = malloc(components_capacity * sizeof(MecsSparseSet));
    if (!world->components)
        return NULL;

    world->components_capacity = components_capacity;

    return world;
}
void mecs_world_free(MecsWorld* world) {
    mecs_sparse_set_free(world->components);
    free(world);
}
MecsEntity mecs_entity_new(MecsWorld* world) {
    size_t array_index = 0;
    size_t len = MECS_BITSET_ARRAY_LEN(world->entities_capacity, uint64_t);

    for (size_t i = 0; i < len; i += 1) {
        if (world->entities[i] != ~0ULL) {
            array_index = i;
            break;
        }
    }

    size_t entity_index = __builtin_ctz(~(world->entities[array_index]));

    MECS_SET_BIT(world->entities[array_index], entity_index);

    return entity_index;
}
// TODO: this function is not functional.
void mecs_entity_set(MecsWorld* world, MecsEntity entity) {
    if (entity >= world->entities_capacity)
        return;

    size_t array_index = entity / MECS_BITSET_LEN(uint64_t);
    size_t entity_index = entity % MECS_BITSET_LEN(uint64_t);

    printf("entity: %llu\narray_index: %llu\nentity_index: %llu\n", entity, array_index, entity_index);

    MECS_SET_BIT(world->entities[array_index], entity_index);
}
void mecs_entity_remove(MecsWorld* world, MecsEntity entity) {
    if (entity >= world->entities_capacity)
        return;

    size_t array_index = entity / MECS_BITSET_LEN(uint64_t);
    size_t entity_index = entity % MECS_BITSET_LEN(uint64_t);

    MECS_CLEAR_BIT(world->entities[array_index], entity_index);
}
bool mecs_entity_alive(const MecsWorld* world, MecsEntity entity) {
    if (entity >= world->entities_capacity)
        return false;

    size_t array_index = entity / MECS_BITSET_LEN(uint64_t);
    size_t entity_index = entity % MECS_BITSET_LEN(uint64_t);

    return (bool)MECS_GET_BIT(world->entities[array_index], entity_index);
}
MecsEntity mecs_component_new(MecsWorld* world) {
    MecsEntity e;
    return e;
}
void mecs_component_set(MecsWorld* world, MecsEntity component_entity) {
}
void mecs_component_remove(MecsWorld* world, MecsEntity component_entity) {
}
