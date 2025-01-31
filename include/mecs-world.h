#ifndef MECS_WORLD_H
#define MECS_WORLD_H

#include "utils/mecs-bitset.h"
#include "utils/mecs-constants.h"
#include "mecs-entity.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct {
	uint64_t entities[BITSET_ARRAY_SIZE(MAX_ENTITIES, uint64_t)];
	size_t entities_size;
} World;

World* mecs_new_world();
void mecs_free_world(World* world);

Entity mecs_new_entity(World* world);
void mecs_remove_entity(World* world, Entity entity);
bool mecs_is_alive(const World* world, Entity entity);
void mecs_print_entities(const World* world);

#endif
