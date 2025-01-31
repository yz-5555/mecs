cmake_minimum_required(VERSION 3.23)

project(mecs LANGUAGES C)

add_library(${PROJECT_NAME}
	src/mecs.c
	src/mecs-world.c
	src/mecs-utils.c
	src/mecs-entity.c
	src/mecs-component.c
	src/utils/mecs-sparseset.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(example)
