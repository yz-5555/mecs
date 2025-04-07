#include "mecs.h"
#include "utils/mecs-sparse-set.h"

#include <raylib.h>
#include <stdio.h>

typedef struct Vec2 {
    float x;
    float y;
} Vec2;

int main(void) {
    InitWindow(800, 600, "mecs - example");
    SetTargetFPS(60);

    MecsWorld *world = mecs_world_new(50, 4);
    MecsEntity entity = mecs_entity_new(world);

    mecs_entity_set(world, 49);

    MecsSparseSet set;
    Vec2 vec;
    vec.x = 0.5f;
    vec.y = 9.8f;
    mecs_sparse_set_init(&set, sizeof(Vec2), 10, 10);
    set.sparse[0] = 0;
    mecs_sparse_set_set(&set, 0, &vec);

    const Vec2 *v = MECS_SPARSE_SET_INDEX(&set, 0, Vec2);
    printf("%f, %f\n", v->x, v->y);

    mecs_sparse_set_free(&set);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            entity = mecs_entity_new(world);
            printf("Entity created at #%llu\n", entity);
        }
        if (IsKeyPressed(KEY_ENTER)) {
            mecs_print_entities(world);
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            mecs_entity_remove(world, entity);
            printf("Entity removed at #%llu\n", entity);
            entity -= 1;
        }

        BeginDrawing();
        {
            ClearBackground(WHITE);
            DrawText("Hello, mecs!", 190, 200, 20, BLACK);
        }
        EndDrawing();
    }

    mecs_world_free(world);

    CloseWindow();

    return 0;
}
