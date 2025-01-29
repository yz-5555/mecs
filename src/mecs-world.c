#include "mecs-world.h"
#include <stdio.h>

Entity mecs_new_entity(World* world) {
	size_t size = sizeof(world->entities) / sizeof(world->entities[0]);
	int index = __builtin_ctz(world->entities[size - 1]);
	printf("index: %d", index);
	CLEAR_BIT(world->entities[size - 1], index + 1);

	return (index + 1);
}
