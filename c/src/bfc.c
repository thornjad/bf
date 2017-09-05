#include <stdio.h>

#define VERSION "0.1.0"

void printVersion();

int main(int argc, char const *argv[]) {
  printVersion();
  if (argc < 1) {
    printf("No arguments supplied\n");
    return 1;
  }


  return 0;
}

void printVersion() {
  printf("bfc v%s\n", VERSION);
}
