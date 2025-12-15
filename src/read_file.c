#include "read_file.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *read_file(FILE *file, size_t *size) {
  if (fseek(file, 0, SEEK_END) != 0) {
    fprintf(stderr, "ERROR: fseek failed!\n");
    return NULL;
  }
  long file_size = ftell(file);
  if (file_size < 0) {
    fprintf(stderr, "ERROR: could not determine file size!\n");
    return NULL;
  }
  if (fseek(file, 0, SEEK_SET) != 0) {
    fprintf(stderr, "ERROR: fseek reset failed!\n");
    return NULL;
  }

  *size = (size_t)file_size;

  char *buffer = malloc(*size);
  if (!buffer) {
    fprintf(stderr, "ERROR: could not allocate memory to buffer!\n");
    return NULL;
  }

  size_t n = fread(buffer, 1, *size, file);
  if (n != *size) {
    fprintf(stderr, "ERROR: could not read file contents!\n");
    free(buffer);
    return NULL;
  }

  return buffer;
}
