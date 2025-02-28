#ifndef MECS_WORLD_H
#define MECS_WORLD_H

#include "mecs-entity.h"

#include "utils/mecs-bitset.h"
#include "utils/mecs-sparse-set.h"

#include <stdbool.h>
#include <stdint.h>

// Constants
#define MECS_ENTITIES_CAPACITY 128

#define MECS_COMPONENTS_CAPACITY 32

#define MECS_ENTITIES_BITSET_TYPE uint64_t

enum {
    MECS_ENTITIES_BITSET_LEN = MECS_BITSET_LEN(MECS_ENTITIES_BITSET_TYPE)
};
// Types
typedef struct MecsWorld {
    MECS_ENTITIES_BITSET_TYPE *entities; // Array of entity bitsets
    size_t entities_capacity;            // Capacity of `entities`
    MecsSparseSet *components;           // Array of component sparse sets
    size_t components_capacity;          // Capacity of `components`
} MecsWorld;

// World member functions
MecsWorld *mecs_world_new(size_t entities_capacity, size_t components_capacity);
void mecs_world_free(MecsWorld *world);

#define MECS_WORLD_DEFAULT() mecs_world_new(MECS_ENTITIES_CAPACITY, MECS_COMPONENTS_CAPACITY)

// Entity mananger
MecsEntity mecs_entity_new(MecsWorld *world);

static inline void mecs_entity_set(MecsWorld *world, MecsEntity entity) {
    if (entity >= world->entities_capacity)
        return;

    size_t array_index = entity / MECS_ENTITIES_BITSET_LEN;
    size_t entity_index = entity % MECS_ENTITIES_BITSET_LEN;

    MECS_SET_BIT(world->entities[array_index], entity_index, MECS_ENTITIES_BITSET_TYPE);
}
static inline void mecs_entity_remove(MecsWorld *world, MecsEntity entity) {
    if (entity >= world->entities_capacity)
        return;

    size_t array_index = entity / MECS_ENTITIES_BITSET_LEN;
    size_t entity_index = entity % MECS_ENTITIES_BITSET_LEN;

    MECS_CLEAR_BIT(world->entities[array_index], entity_index, MECS_ENTITIES_BITSET_TYPE);
}
static inline bool mecs_entity_alive(const MecsWorld *world, MecsEntity entity) {
    if (entity >= world->entities_capacity)
        return false;

    size_t array_index = entity / MECS_ENTITIES_BITSET_LEN;
    size_t entity_index = entity % MECS_ENTITIES_BITSET_LEN;

    return (bool)MECS_GET_BIT(world->entities[array_index], entity_index, MECS_ENTITIES_BITSET_TYPE);
}

// Component manager
MecsEntity mecs_component_new(MecsWorld *world);
void mecs_component_set(MecsWorld *world, MecsEntity component_entity);
void mecs_component_remove(MecsWorld *world, MecsEntity component_entity);

#endif
