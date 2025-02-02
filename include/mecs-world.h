#ifndef MECS_WORLD_H
#define MECS_WORLD_H

#include "mecs-entity.h"
#include "utils/mecs-constants.h"
#include "utils/mecs-sparse-set.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint64_t* entities;         // Array of entity bitsets
    size_t entities_capacity;   // Capacity of `entities`
    SparseSet* components;      // Array of component sparse sets
    size_t components_capacity; // Capacity of `components`
} World;

World* mecs_new_world(size_t entities_capacity, size_t components_capacity);
#define MECS_DEFAULT_WORLD() mecs_new_world(MECS_ENTITIES_CAPACITY, MECS_COMPONENTS_CAPACITY)

void mecs_free_world(World* world);

Entity mecs_new_entity(World* world);
void mecs_remove_entity(World* world, Entity entity);
bool mecs_is_alive(const World* world, Entity entity);
void mecs_print_entities(const World* world);

#endif
