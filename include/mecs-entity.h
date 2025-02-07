#ifndef MECS_ENTITY_H
#define MECS_ENTITY_H

#include "mecs-world.h"
#include <stdint.h>

typedef uint32_t Entity;

// TODO: Design: Entity or World?

Entity mecs_new_entity(World* world);
void mecs_remove_entity(World* world, Entity entity);
bool mecs_is_alive(const World* world, Entity entity);
void mecs_print_entities(const World* world);

#endif
