#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "cp: not enough arguments provided.\n");
    return EXIT_FAILURE;
  }
  if (argc > 3) {
    fprintf(stderr, "cp: too many arguments.\n");
    return EXIT_FAILURE;
  }

  const char *source = argv[1];
  const char *dest = argv[2];

  FILE *src_fp = fopen(source, "rb");
  if (src_fp == NULL) {
    fprintf(stderr, "Failed to open source file '%s': %s\n", source,
            strerror(errno));
    return EXIT_FAILURE;
  }

  fseek(src_fp, 0, SEEK_END);
  long size = ftell(src_fp);
  fseek(src_fp, 0, SEEK_SET);

  uint8_t *data = malloc(size);

  fread(data, 1, size, src_fp);

  FILE *dest_fp = fopen(dest, "wb");
  if (dest_fp == NULL) {
    fprintf(stderr, "Failed to open destination file '%s': %s\n", dest,
            strerror(errno));
    return EXIT_FAILURE;
  }

  fwrite(data, 1, size, dest_fp);
}
