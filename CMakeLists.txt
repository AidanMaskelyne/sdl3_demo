cmake_minimum_required(VERSION 3.10...3.28)

# For playing nice with bloatware (IDEs)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(
	SDL3Demo,
	VERSION 1.0
	LANGUAGES CXX
)

# C++17 to use the filesystem stuff
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_EXTENSIONS OFF)

# Allow the user to choose between using the version of SDL in `deps/SDL` or the installed version on their system
option(USE_SYSTEM_SDL3 "Use the system version of SDL" OFF)

if (NOT USE_SYSTEM_SDL3)
	# Build SDL3 as a shared library only
	set(SDL_STATIC ON)
	set(SDL_SHARED OFF)
	add_subdirectory(deps/SDL EXCLUDE_FROM_ALL)
else()
	# This is required, otherwise SDL3 won't be found
	find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-static)
endif()

add_executable(SDL3Demo
	src/main.cpp

	src/Config.h
	src/Config.cpp

	src/INI.h
)

# Set `SDL3Demo` as the startup project in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SDL3Demo)

target_link_libraries(SDL3Demo PRIVATE SDL3::SDL3)