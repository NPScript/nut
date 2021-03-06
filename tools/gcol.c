#include <stdio.h>
#include <stdlib.h>

unsigned col;
char c;
int count;

int main(int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "gcol [column number]\n");
		return -1;
	}

	col = atoi(argv[1]);

	c = getchar();

	while (c != EOF) {
		count = 1;
		while (c != '\n') {
			if (c == ' ' || c == '\t') {
				++count;
				while ((c = getchar()) == ' ' || c == '\t');
				continue;
			} else if (count == col) {
				putc(c, stdout);
			} else if (count > col) {
				while (getchar() != '\n');
				break;
			}
			c = getchar();
		}
		putc('\n', stdout);
		c = getchar();
	}

	return 0;
}
