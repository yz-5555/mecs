#include "mecs-world.h"

#include "utils/mecs-debug.h"

#include <stdio.h>

void mecs_print_entities(const MecsWorld *world) {
    for (MecsEntity i = 0; i < world->entities_allocated_capacity; i += 1) {
        printf("Entity %llu: ", i);
        if (i < world->entities_capacity) {
            if (mecs_entity_alive(world, i))
                printf("\x1b[102mACTIVE\x1b[0m\n");
            else
                printf("\x1b[2mINACTIVE\x1b[0m\n");
        } else {
            printf("\x1b[94mEMPTY\x1b[0m\n");
        }
    }
}
