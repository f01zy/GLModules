#ifndef SPHERE_H
#define SPHERE_H

#include "mesh.h"
#include <cglm/cglm.h>

typedef struct {
  struct {
    Vertice *buf;
    size_t len;
    size_t size;
  } vertices;

  struct {
    ivec3 *buf;
    size_t len;
    size_t size;
  } indices;
} SphereData;

void sphere_data_initialize(SphereData *data, int sectors, int stacks);
void sphere_data_free(const SphereData *data);
size_t sphere_get_vertices_size(const SphereData *data);
size_t sphere_get_indices_size(const SphereData *data);
void sphere_render(const Mesh *mesh, vec3 pos, vec3 color, float radius, size_t indices_count, uint32_t shader_program);

#endif
