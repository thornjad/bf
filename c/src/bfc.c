#include <stdio.h>

#define VERSION "0.1.0"
#define TESTPATH "./test/test.bf"

void printVersion();

char tape[32000] = {0};
char *head = &tape[0];

int main(int argc, char const *argv[]) {
  printVersion();
  // if (argc <= 1) {
  //   printf("No arguments supplied\n");
  //   return 1;
  // }
  // TODO check for valid file format. For now, call local file
  // char *path[(sizeof argv / sizeof *argv)] = argv[1];
  // TODO pass all args to cc
  // TODO parser/translate to c
  // TODO call cc on c file

  return 0;
}

void printVersion() {
  printf("bfc v%s\n\n", VERSION);
}

void inc() {
  ++head;
}
