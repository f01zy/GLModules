#include <glad/gl.h>

#include <GLFW/glfw3.h>
#include <stdio.h>

#include "GLModules/window.h"

GLFWwindow *window_create(int width, int height, const char *title) {
  if (!glfwInit()) {
    printf("[ERROR] Failed to initialize GLFW\n");
    return NULL;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
  if (!window) {
    printf("[ERROR] Failed to create window\n");
    glfwTerminate();
    return NULL;
  }

  glfwMakeContextCurrent(window);

  int version = gladLoadGL(glfwGetProcAddress);
  if (version == 0) {
    printf("[ERROR] Failed to initialize OpenGL context (GLAD)\n");
    glfwDestroyWindow(window);
    glfwTerminate();
    return NULL;
  }

  printf("[LOG] Loaded OpenGL %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));

  return window;
}
