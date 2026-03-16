#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "mkdir: no arguments provided.\n");
    return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; i++) {
    if (mkdir(argv[i], 0755) != 0) {
      fprintf(stderr, "mkdir: unable to create directory '%s': %s\n", argv[i],
              strerror(errno));
    }
  }
}
