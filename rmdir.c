#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "rmdir: no arguments provided.\n");
    return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; i++) {
    if (rmdir(argv[i]) != 0) {
      fprintf(stderr, "rmdir: unable to remove '%s': %s\n", argv[i],
              strerror(errno));
    }
  }
}
