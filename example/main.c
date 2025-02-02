#include "mecs.h"
#include <stdio.h>

int main(void) {
    World* world = mecs_new_world();
    mecs_print_entities(world);

    Entity entity = mecs_new_entity(world);
    mecs_print_entities(world);
    printf("%d\n", mecs_is_alive(world, entity));

    mecs_remove_entity(world, entity);
    mecs_print_entities(world);
    printf("%d\n", mecs_is_alive(world, entity));

    mecs_free_world(world);
    return 0;
}
