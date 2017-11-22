/* brainfuck interpreter, using a C intermediary file
 *
 * Copyright 2017 Jade M Thornton
 * Free for use under the terms of the ISC license
 *
 * The interpreter takes a single .bf file as an argument and runs it.
 * All illegal brainfuck characters are treated as
 * whitespace.
 *
 */

#include <stdio.h>
#include <stdlib.h>

void parse(char const path[]);

int main(int argc, char const *argv[]) {
  if (argc <= 1) {
    printf("No arguments supplied\n");
    return 1;
  }
  parse(argv[1]);
  system("cc -Wall bfa.c -o bfa");
  system("./bfa");
  system("rm -f bfa bfa.c");

}

void parse(char const path[]) {
  FILE *srcFile = fopen(path, "r");
  if (srcFile == 0) {
    printf("Could not open source file");
    exit(1);
  } else {
    char c;
    // create output file
    FILE *outFile = fopen("bfa.c", "w");

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
  }
}
