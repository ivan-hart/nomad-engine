cmake_minimum_required(VERSION 3.30.5)

project(nomad-engine VERSION 0.0.1)

set(SOURCES
    src/main.cpp
    src/glad.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARIES}
)