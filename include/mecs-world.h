#ifndef MECS_WORLD_H
#define MECS_WORLD_H

#include "mecs-entity.h"
#include <stdbool.h>

typedef struct {
} World;

Entity mecs_new_entity(World* world);
Entity mecs_remove_entity(World* world, Entity entity);
Entity mecs_is_alive(const World* world, Entity entity);
Entity mecs_log_entities(const World* world);

#endif
