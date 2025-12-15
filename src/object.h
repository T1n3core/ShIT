#ifndef OBJECT_H
#define OBJECT_H

#include <stddef.h>
#include <string.h>

typedef enum { BLOB, TREE, COMMIT, UNKNOWN } object_type;

static inline const char *objtype_tostring(object_type t) {
  switch (t) {
  case BLOB:
    return "blob";
  case TREE:
    return "tree";
  case COMMIT:
    return "commit";
  default:
    return NULL;
  }
}

static inline object_type string_toobjtype(const char *s) {
  if (strcmp(s, "blob") == 0)
    return BLOB;
  if (strcmp(s, "tree") == 0)
    return TREE;
  if (strcmp(s, "commit") == 0)
    return COMMIT;
  return UNKNOWN;
}

int store_object(object_type type, const void *content, size_t size,
                 unsigned char sha1_out[20]);

#endif
