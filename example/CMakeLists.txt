set(PROJ example)

add_subdirectory(external/raylib)

add_executable(${PROJ} main.c)

target_link_libraries(${PROJ} PRIVATE mecs)
target_link_libraries(${PROJ} PRIVATE raylib)
