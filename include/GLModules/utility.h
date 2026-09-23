#ifndef UTILITY_H
#define UTILITY_H

#include <glad/gl.h>
#include <stdbool.h>
#include <stddef.h>

size_t utility_get_opengl_type_size(GLenum type);
bool utility_read_file(const char *path, char *buf, size_t size);

#endif
