cmake_minimum_required(VERSION 3.5)
project(
  GLModules
  VERSION 1.0.0
  DESCRIPTION "Modules for my OpenGL projects"
  HOMEPAGE_URL "https://github.com/f01zy/GLModules"
  LANGUAGES C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(OpenGL_GL_PREFERENCE GLVND)
set(LIBRARY GLModules)

file(GLOB SOURCE src/*.c)
add_library(${LIBRARY} STATIC ${SOURCE})

find_package(OpenGL REQUIRED)
add_subdirectory(third_party/freetype)
add_subdirectory(third_party/glfw)
add_subdirectory(third_party/glad)
add_subdirectory(third_party/cglm)

target_include_directories(${LIBRARY} PUBLIC include)
target_link_libraries(${LIBRARY} PUBLIC 
  OpenGL::GL
  freetype
  cglm
  glfw
  glad
)
