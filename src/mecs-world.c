#include "mecs-world.h"
#include "utils/mecs-bitset.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

World* mecs_new_world() {
    World* world = malloc(sizeof(World));
    if (!world)
        return NULL;
    memset(world->entities, 0, sizeof(world->entities));
    world->entities_size = sizeof(world->entities) / sizeof(world->entities[0]);

    return world;
}
void mecs_free_world(World* world) {
	free(world);
}
Entity mecs_new_entity(World* world) {
    int array_index = 0;
    for (int i = 0; i < world->entities_size; i += 1) {
        if (world->entities[i] != ~0ULL) {
            array_index = i;
            break;
        }
    }

    int entity_index = __builtin_ctz(~(world->entities[array_index]));
    SET_BIT(world->entities[array_index], entity_index);

    return entity_index;
}
void mecs_remove_entity(World* world, Entity entity) {
	int array_index = entity / BITSET_SIZE(world->entities[0]);
	int entity_index = entity % BITSET_SIZE(world->entities[0]);

	CLEAR_BIT(world->entities[array_index], entity_index);
}
bool mecs_is_alive(const World* world, Entity entity) {
	int array_index = entity / BITSET_SIZE(world->entities[0]);
	int entity_index = entity % BITSET_SIZE(world->entities[0]);

    return GET_BIT(world->entities[array_index], entity_index);
}
void mecs_print_entities(const World* world) {
    for (int i = 0; i < world->entities_size; i += 1) {
        for (int j = 0; j < BITSET_SIZE(world->entities[0]); j += 1) {
            printf("Entity %llu: ", i * BITSET_SIZE(world->entities[0]) + j);
            if (world->entities[i] >> j & 0x1)
                printf("1\n");
            else
                printf("0\n");
        }
    }
}
