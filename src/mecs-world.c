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
    world->entities_capacity = entities_capacity;
    world->entities = malloc(BITSET_ARRAY_LEN(entities_capacity, uint64_t) * sizeof(uint64_t));
    if (!world->entities)
        return NULL;

    memset(world->entities, 0, BITSET_ARRAY_LEN(entities_capacity, uint64_t) * sizeof(uint64_t));

    // Initialize array of component sparse sets
    world->components_capacity = components_capacity;
    world->components = malloc(components_capacity * sizeof(SparseSet));
    if (!world->components)
        return NULL;

    return world;
}
void mecs_free_world(World* world) {
    mecs_free_sparse_set(world->components);
    free(world);
}
