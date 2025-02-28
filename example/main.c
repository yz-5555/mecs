#include "mecs.h"

#include <raylib.h>
#include <stdio.h>

int main(void) {
    InitWindow(800, 600, "mecs - example");
    SetTargetFPS(60);

    MecsWorld *world = mecs_world_new(64, 4);
    MecsEntity entity = mecs_entity_new(world);

    mecs_entity_set(world, 63);

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
