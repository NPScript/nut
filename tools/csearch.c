#include <stdlib.h>
#include <stdio.h>

char filepath[BUFSIZ];
char * pattern;

static int file_contains_pattern() {
	FILE * file = fopen(filepath, "r");
	char c;
	char * p = pattern;

	while ((c = fgetc(file)) != EOF) {
		if (*p == 0) {
			return 1;
		} else if (*p == c) {
			++p;
		} else {
			p = pattern;
		}
	}

	fclose(file);

	return 0;
}

int main(int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "csearch [pattern]\n");
		return -1;
	}

	pattern = argv[1];

	while (fgets(filepath, BUFSIZ, stdin)) {
		char * c;
		for (c = filepath; *c != '\n'; ++c);
		*c = 0;
		if (file_contains_pattern())
			printf("%s\n", filepath);
	}

	return 0;
}
