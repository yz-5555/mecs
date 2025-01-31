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

    return world;
}

Entity mecs_new_entity(World* world) {
    size_t size = sizeof(world->entities) / sizeof(world->entities[0]);

    int array_index = 0;
    for (int i = 0; i < size; i += 1) {
        if (world->entities[i] != ~0ULL) {
            array_index = i;
            break;
        }
    }

    int entity_index = __builtin_ctz(~(world->entities[array_index]));
    printf("Entity created: %d", array_index * 64 + entity_index);

    SET_BIT(world->entities[array_index], entity_index);

    return entity_index;
}
void mecs_remove_entity(World* world, Entity entity) {
}
bool mecs_is_alive(const World* world, Entity entity) {
    return true;
}
void mecs_print_entities(const World* world) {
    size_t size = sizeof(world->entities) / sizeof(world->entities[0]);

    for (int i = 0; i < size; i += 1) {
        for (int j = 0; j < GET_BITSET_LENGTH(world->entities[0]); j += 1) {
            printf("Entity %llu: ", i * GET_BITSET_LENGTH(world->entities[0]) + j);
            if (world->entities[i] >> j & 0x1)
                printf("1\n");
            else
                printf("0\n");
        }
    }
}
