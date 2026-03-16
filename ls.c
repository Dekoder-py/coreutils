#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ls(char *path) {
  DIR *d = opendir(path);
  if (d == NULL) {
    fprintf(stderr, "ls: unable to open directory '%s': %s\n", path,
            strerror(errno));
    return;
  }

  errno = 0;
  struct dirent *ent;
  while ((ent = readdir(d)) != NULL) {
    printf("%s\n", ent->d_name);
  }
  if (errno != 0) {
    fprintf(stderr, "ls: error occurred: %s\n", strerror(errno));
  }
  closedir(d);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    ls(".");
    return EXIT_SUCCESS;
  }

  for (int i = 1; i < argc; i++) {
    ls(argv[i]);
  }
}
