cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
project(SDL_Platformer)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(include  ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(SDL_Platformer src/main.cpp src/RenderWindow.cpp include/Entity.h src/Entity.cpp include/Events.h src/Events.cpp include/TextureWrapper.h)

target_link_libraries(SDL_Platformer ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} )

# file copying functions
set (source "${CMAKE_SOURCE_DIR}/res")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/res")
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "symbolic link resources folder from ${source} => ${destination}"
)