#include <stdio.h>

char stdin_lines[BUFSIZ][BUFSIZ];
char stdout_lines[BUFSIZ][BUFSIZ];
int inline_iterator[BUFSIZ];
int outline_iterator[BUFSIZ];
int lines;
char separator;
int i;
int length;
int has_char;
int all_newline = 0;

int main(int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "columnify [separator]\n");
		return -1;
	}
	
	separator = argv[1][0];

	for (lines = 0; fgets(stdin_lines[lines], BUFSIZ, stdin); ++lines) {
		inline_iterator[lines] = 0;
		outline_iterator[lines] = 0;
	}

	while (!all_newline) {
		has_char = 0;
		all_newline = 1;
		i = 0;

		while (i < lines) {
			if (stdin_lines[i][inline_iterator[i]] == separator || stdin_lines[i][inline_iterator[i]] == '\n') {
				if (stdin_lines[i][inline_iterator[i]] != '\n')
					all_newline = 0;

				stdout_lines[i][outline_iterator[i]] = ' ';
			} else {
				has_char = 1;
				all_newline = 0;
				stdout_lines[i][outline_iterator[i]] = stdin_lines[i][inline_iterator[i]];
				++inline_iterator[i];
			}
			++outline_iterator[i];

			++i;
		}


		if (!has_char && !all_newline) {
			i = 0;
			while (i < lines) {
				stdout_lines[i][outline_iterator[i]] = ' ';
				if (stdin_lines[i][inline_iterator[i]] != '\n')
					++inline_iterator[i];
				++outline_iterator[i];
				++i;
			}
		}
	}

	for (i = 0; i < lines; ++i) {
		stdout_lines[lines][outline_iterator[i] + 1] = 0;
	}
	
	for (i = 0; i < lines; ++i) {
		printf("%s\n", stdout_lines[i]);
	}

	return 0;
}
