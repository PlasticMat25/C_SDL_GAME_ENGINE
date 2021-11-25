cmake_minimum_required(VERSION 3.7)

project(GAME)

add_executable(GAME
	src/main.c
	src/Application.c
	src/Graphics.c
	src/Input.c
	src/Texture.c
	src/Vector2.c)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)

TARGET_LINK_LIBRARIES(GAME ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
