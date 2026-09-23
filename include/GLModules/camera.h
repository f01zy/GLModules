#ifndef CAMERA_H
#define CAMERA_H

#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

typedef struct {
  vec3 pos, dir;
  vec3 up, right;
  float yaw, pitch;
  float radius;
  float fov;
} Camera;

void camera_initialize(Camera *camera);
void camera_update_position(Camera *camera);
void camera_get_view_matrix(const Camera *camera, mat4 view);
void camera_mouse_scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void camera_mouse_position_callback(GLFWwindow *window, double xpos, double ypos);

#endif
