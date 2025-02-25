cmake_minimum_required(VERSION 3.23)

project(mecs LANGUAGES C)

add_library(${PROJECT_NAME}
	src/mecs-world.c
	src/utils/mecs-debug.c
	src/utils/mecs-sparse-set.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(example)

message("C: ${CMAKE_C_FLAGS}")
message("CXX: ${CMAKE_CXX_FLAGS}")
