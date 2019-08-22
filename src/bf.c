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
#include <string.h>
#include <stdlib.h>

/* void parse(char const path[]); */
/* char* mapSymbol(char bfChar); */

char* mapSymbol(char bfChar) {
	switch(bfChar) {
		case '>':
			return "++p;";
		case '<':
			return "--p;";
		case '+':
			return "++*p;";
		case '-':
			return "--*p;";
		case '.':
			return "putchar(*p);";
		case ',':
			return "*p=getchar();";
		case '[':
			return "while(*p){";
		case ']':
			return "}";
		default:
			return "";
	}
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
    while ((c = fgetc(srcFile)) != EOF) {
			fputs(mapSymbol(c), outFile);
    }

    fputs("free(a);", outFile);
    fputs("}", outFile);
    fclose(srcFile);
    fclose(outFile);
  }
}


int main(int argc, char const *argv[]) {
  if (argc <= 1) {
    printf("Usage:\n\tbf [subcommand] <file>\n");
    return 1;
	}

	char run = strncmp(argv[1], "run", 3) == 0;
	char compile = run | (strncmp(argv[1], "compile", 7) == 0);
	char noSubcommand = ~run & ~compile;

	if (compile | run) {
		parse(argv[2]);
	} else {
		parse(argv[1]);
	}

	if (run | noSubcommand) {
		system("cc -Wall bfa.c -o bfa");
		system("./bfa");
		system("rm -f bfa bfa.c");
	}

	return 0;
}
