#include "mecs.h"
#include <stdio.h>

int main(void) {
    World* world = mecs_new_world();
    mecs_print_entities(world);
    mecs_new_entity(world);
    mecs_new_entity(world);
    mecs_new_entity(world);
    mecs_print_entities(world);
    return 0;
}
