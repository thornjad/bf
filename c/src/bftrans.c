// brainfuck translator, using a C intermediary file

#include <stdio.h>

int run(char const inPath[], char const outPath[]);

int main(int argc, char const *argv[]) {
  if (argc <= 1) {
    printf("No arguments supplied\n");
    return 1;
  }
  if (argc == 2) {
    argv[2] = "bfa.c";
  }
  return run(argv[1], argv[2]);
}

int run(char const inPath[], char const outPath[]) {
  FILE *srcFile = fopen(inPath, "r");
  if (srcFile == 0) {
    printf("Could not open source file");
    return 1;
  } else {
    char c;
    // create output file
    FILE *outFile = fopen(outPath, "w");

    // initialize turing machine
    fputs("#include <stdio.h>\n#include <stdlib.h>\n", outFile);
    fputs("int main(void){", outFile);
    fputs("char*a=calloc(120000,sizeof(int));", outFile);
    fputs("if(a==NULL){printf(\"Unable to allocate space\");exit(1);}", outFile);
    fputs("char*p=a;\n", outFile);

    // translate src file
    int currentLineLen = 0;
    int charsAdded = 0;
    while ((c = fgetc(srcFile)) != EOF) {
      switch (c) {
        case '>':
          fputs("++p;", outFile);
          charsAdded = 4;
          break;
        case '<':
          fputs("--p;", outFile);
          charsAdded = 4;
          break;
        case '+':
          fputs("++*p;", outFile);
          charsAdded = 5;
          break;
        case '-':
          fputs("--*p;", outFile);
          charsAdded = 5;
          break;
        case '.':
          fputs("putchar(*p);", outFile);
          charsAdded = 12;
          break;
        case ',':
          fputs("*p=getchar();", outFile);
          charsAdded = 13;
          break;
        case '[':
          fputs("while(*p){", outFile);
          charsAdded = 10;
          break;
        case ']':
          fputs("}", outFile);
          charsAdded = 1;
          break;
        default:
          // all other input ignored
          charsAdded = 0;
          break;
      }
      if (charsAdded) {
        currentLineLen += charsAdded;
        if (++currentLineLen > 240) {
          fputc('\n', outFile);
          currentLineLen = 0;
        }
      }
    }
    fputs("free(a);", outFile);
    fputs("}", outFile);
    fclose(srcFile);
    fclose(outFile);
    return 0;
  }
}
