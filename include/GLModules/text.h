#ifndef TEXT_INCLUDED
#define TEXT_INCLUDED

#include <cglm/cglm.h>
#include <stdbool.h>
#include <stdint.h>

#include "mesh.h"

typedef struct {
  uint32_t texture;
  uint32_t advance;
  ivec2 size;
  ivec2 bearing;
} Character;

typedef struct {
  Character characters[255];
} Font;

void text_render(const Font *font, const Mesh *mesh, const char *text, vec2 pos, float scale, vec3 color, uint32_t shader_program);
bool font_initialize(Font *font, const char *path, int size);
void font_free(const Font *font);

#endif
