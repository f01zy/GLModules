#include <cglm/cglm.h>
#include <math.h>

#include "GLModules/camera.h"
#include "GLModules/defines.h"

float last_mouse_x = 0.0f;
float last_mouse_y = 0.0f;
bool is_first_mouse = true;
vec3 world_up = {0.0f, 1.0f, 0.0f};
vec3 target = {0.0f, 0.0f, 0.0f};

void camera_update_position(Camera *camera) {
  vec3 temp, direction;
  temp[0] = camera->radius * cos(glm_rad(camera->yaw)) * cos(glm_rad(camera->pitch));
  temp[1] = camera->radius * sin(glm_rad(camera->pitch));
  temp[2] = camera->radius * sin(glm_rad(camera->yaw)) * cos(glm_rad(camera->pitch));
  glm_vec3_copy(temp, camera->pos);
  glm_vec3_sub(target, camera->pos, camera->dir);
  glm_normalize(camera->dir);
  glm_cross(camera->dir, world_up, camera->right);
  glm_normalize(camera->right);
  glm_cross(camera->right, camera->dir, camera->up);
  glm_normalize(camera->up);
}

void camera_initialize(Camera *camera) {
  camera->fov = 45.0f;
  camera->yaw = 90.0f;
  camera->pitch = 45.0f;
  camera->radius = 10.0f;
  camera_update_position(camera);
}

void camera_get_view_matrix(const Camera *camera, mat4 view) { return glm_lookat((float *)camera->pos, target, (float *)camera->up, view); }

void camera_mouse_scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
  Camera *camera = (Camera *)glfwGetWindowUserPointer(window);
  float radius = camera->radius - yoffset;
  if (radius > 0.0f && radius <= MAX_CAMERA_RADIUS) {
    camera->radius = radius;
    camera_update_position(camera);
  }
}

void camera_mouse_position_callback(GLFWwindow *window, double xpos, double ypos) {
  Camera *camera = (Camera *)glfwGetWindowUserPointer(window);
  if (is_first_mouse) {
    last_mouse_x = xpos;
    last_mouse_y = ypos;
    is_first_mouse = false;
  }
  float xoffset = xpos - last_mouse_x;
  float yoffset = ypos - last_mouse_y;
  last_mouse_x = xpos;
  last_mouse_y = ypos;
  if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
    camera->pitch = glm_clamp(camera->pitch + yoffset, -89.0f, 89.0f);
    camera->yaw += xoffset;
    camera_update_position(camera);
  }
}
