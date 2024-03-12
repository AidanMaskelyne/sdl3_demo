cmake_minimum_required(VERSION 3.10...3.28)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(
	SDL3Demo,
	VERSION 1.0
	LANGUAGES CXX
)

option(USE_SYSTEM_SDL3 "Use the system version of SDL" OFF)

if (NOT USE_SYSTEM_SDL3)
	set(SDL_STATIC ON)
	set(SDL_SHARED OFF)
	add_subdirectory(deps/SDL EXCLUDE_FROM_ALL)
else()
	find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-static)
endif()

add_executable(SDL3Demo src/main.cpp)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SDL3Demo)

target_link_libraries(SDL3Demo PRIVATE SDL3::SDL3)
