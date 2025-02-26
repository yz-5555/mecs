#ifndef MECS_WORLD_H
#define MECS_WORLD_H

#include "mecs-entity.h"

#include "utils/mecs-constants.h"
#include "utils/mecs-sparse-set.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct MecsWorld {
    uint64_t* entities;         // Array of entity bitsets
    size_t entities_capacity;   // Capacity of `entities`
    MecsSparseSet* components;  // Array of component sparse sets
    size_t components_capacity; // Capacity of `components`
} MecsWorld;

// World member functions
MecsWorld* mecs_world_new(size_t entities_capacity, size_t components_capacity);
void mecs_world_free(MecsWorld* world);

#define MECS_WORLD_DEFAULT() mecs_world_new(MECS_ENTITIES_CAPACITY, MECS_COMPONENTS_CAPACITY)

// Entity mananger
MecsEntity mecs_entity_new(MecsWorld* world);
void mecs_entity_set(MecsWorld* world, MecsEntity entity);
void mecs_entity_remove(MecsWorld* world, MecsEntity entity);
bool mecs_entity_alive(const MecsWorld* world, MecsEntity entity);

// Component manager
MecsEntity mecs_component_new(MecsWorld* world);
void mecs_component_set(MecsWorld* world, MecsEntity component_entity);
void mecs_component_remove(MecsWorld* world, MecsEntity component_entity);

#endif
