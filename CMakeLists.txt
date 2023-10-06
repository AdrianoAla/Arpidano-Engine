cmake_minimum_required(VERSION 3.22)
project(PROJECT_NAME)

set(CMAKE_CXX_STANDARD 11)

# Must set the path to the main.cpp, for example: scripts/main.cpp if it is inside a folder

add_executable(${PROJECT_NAME} scripts/main.cpp

        scripts/Game/Game.cpp

        scripts/ECS/Components.h

        scripts/Utils/Vector2.h

        scripts/Collision/Collision.cpp
        scripts/Collision/Collision.h

        scripts/Components/ColliderComponent.h
        scripts/Components/KeyboardControllerComponent.h
        scripts/Components/TransformComponent.h

        scripts/Camera/Camera.cpp
        scripts/Camera/Camera.h
        scripts/Components/RendererComponent.h
        scripts/Components/BallControllerComponent.h
        scripts/Components/AIControllerComponent.h


)

# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})