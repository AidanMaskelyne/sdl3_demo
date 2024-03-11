cmake_minimum_required(VERSION 3.10...3.28)

project(
	SDL3Demo,
	VERSION 1.0
	LANGUAGES CXX
)

option(USE_SYSTEM_SDL3 "Use the system's libraries" OFF)

if (SDL3DEMO_VENDORED)
	add_subdirectory(deps/SDL EXCLUDE_FROM_ALL)
else()
	find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

add_executable(SDL3Demo src/main.cpp)

target_link_libraries(SDL3Demo PRIVATE SDL3::SDL3)
