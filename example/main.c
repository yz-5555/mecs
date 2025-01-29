#include "mecs.h"
#include <stdio.h>

int main(void) {
    World world;
    world.entities[0] = 18446744073709551615ULL;
    world.entities[1] = 35;

    for (int i = 0; i < 64; i += 1) {
        printf("Bit %d: %llu\n", i, GET_BIT(world.entities[0], i));
    }
	for (int i = 0; i < 10; i += 1) {
		printf("Bit %d: %llu\n", i + 64, GET_BIT(world.entities[1], i));
	}

	Entity entity = mecs_new_entity(&world);
    for (int i = 0; i < 64; i += 1) {
        printf("Bit %d: %llu\n", i, GET_BIT(world.entities[0], i));
    }
	for (int i = 0; i < 10; i += 1) {
		printf("Bit %d: %llu\n", i + 64, GET_BIT(world.entities[1], i));
	}
    return 0;
}
