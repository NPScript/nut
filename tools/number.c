#include <stdio.h>

char line[BUFSIZ];
char * separator = "";
int n = 1;

int main(int argc, char ** argv) {
	if (argc == 2) {
		separator = argv[1];
	} else {
		fprintf(stderr, "number [separator]\n");
		return -1;
	}

	for (;fgets(line, BUFSIZ, stdin); ++n) {
		printf("%i%s%s", n, separator, line);
	}

	return 0;
}
