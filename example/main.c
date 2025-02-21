#include "mecs.h"
#include <raylib.h>

int main(void) {
    World* world = mecs_new_world(64, 4);
    Entity entity = mecs_new_entity(world);

    InitWindow(800, 600, "mecs - example");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(WHITE);
            if (mecs_is_alive(world, entity))
                DrawText("Hello, entity!", 190, 200, 20, BLACK);
        }
        EndDrawing();
    }

    CloseWindow();

    mecs_free_world(world);
    return 0;
}
