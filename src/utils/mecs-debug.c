#include "utils/mecs-debug.h"

#include <stdio.h>

// TODO: Design better logic. Currently not functional and not looks that efficient.
void mecs_print_entities(const MecsWorld *world) {
    for (MecsEntity i = 0; i < world->entities_capacity; i += 1) {
        printf("Entity %llu: ", i);
        if (mecs_entity_alive(world, i))
            printf("true\n");
        else
            printf("false\n");
    }
}
