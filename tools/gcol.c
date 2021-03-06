#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stdin_line[BUFSIZ];
char col_line[BUFSIZ];
unsigned col;

static void get_col() {
	int count = 0;
	char * c;
	char * b = stdin_line;

	for (c = stdin_line; c < stdin_line + BUFSIZ && count < col; ++c) {
		if (*c == ' ' || *c == '\t' || *c == '\n') {
			while ((*c == ' ' || *c == '\t' || *c == '\n') && c < stdin_line + BUFSIZ) { ++c; }
			--c;
			++count;

			if (count == col - 1)
				b = c + 1;
		}
	}

	if (count < col) {
		col_line[0] = '\0';
		return;
	}

	int i = 0;
	for (; b < c; ++b) {
		col_line[i] = *b;
		++i;
	}

	if (col_line[i - 1] == '\n')
		col_line[i - 1] = '\0';
	else
		col_line[i] = '\0';
}

static void read_stdin() {
	for (int i = 0; fgets(stdin_line, sizeof stdin_line, stdin); ++i) {
		get_col();
		printf("%s\n", col_line);
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
