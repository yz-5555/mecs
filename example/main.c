#include "mecs-entity.h"
#include "mecs-world.h"
#include <raylib.h>

int main(void) {
    InitWindow(800, 600, "mecs - example");
    SetTargetFPS(60);

    MecsWorld* world = mecs_world_new(64, 4);
    MecsEntity entity = mecs_entity_new(world);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_SPACE))
            entity = mecs_entity_new(world);
        if (IsKeyDown(KEY_BACKSPACE))
            mecs_entity_remove(world, entity);

        BeginDrawing();
        {
            ClearBackground(WHITE);
            if (mecs_entity_alive(world, entity))
                DrawText("Hello, entity!", 190, 200, 20, BLACK);
        }
        EndDrawing();
    }

    mecs_world_free(world);

    CloseWindow();

    return 0;
}
