cmake_minimum_required(VERSION 3.8)
project(sandbox_rush_04)

set(CMAKE_C_STANDARD 99)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

set(SOURCE_FILES main.c sdl_init.c sdl_init.h sdl_close.c sdl_close.h sdl_struct.h sdl_image.c sdl_image.h sdl_player.c sdl_player.h sdl_display.c sdl_display.h game.c game.h)
add_executable(sandbox_rush_04 ${SOURCE_FILES})
target_link_libraries(sandbox_rush_04 SDL2 SDL2_ttf SDL2_image)