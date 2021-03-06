#include <stdio.h>
#include <stdlib.h>

char stdin_line[BUFSIZ];
unsigned col;

inline static void get_col() {
	int count = 1;
	char * c = stdin_line;

	for (;count != col && *c != '\n'; ++c) {
		if (*c == ' ' || *c == '\t') {
			++count;
			for (;*c == ' ' || *c == '\t'; ++c);
			--c;
		}
	}

	for (; *c != ' ' && *c != '\t' && *c !='\n'; ++c) {
		putc(*c, stdout);
	}
	putc('\n', stdout);
}

inline static void read_stdin() {
	while (fgets(stdin_line, sizeof stdin_line, stdin)) {
		get_col();
	}
}

int main(int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "gcol [column number]\n");
		return -1;
	}

	col = atoi(argv[1]);

	read_stdin();

	return 0;
}
