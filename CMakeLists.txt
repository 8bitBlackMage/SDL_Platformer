cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
project(SDL_Platformer)






include_directories(include /usr/include/SDL2)
add_executable(SDL_Platformer src/main.cpp src/RenderWindow.cpp include/Entity.h src/Entity.cpp include/Events.h src/Events.cpp)

target_link_libraries(SDL_Platformer -lSDL2 -lSDL2_image )

# file copying functions
set (source "${CMAKE_SOURCE_DIR}/res")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/res")
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "symbolic link resources folder from ${source} => ${destination}"
)