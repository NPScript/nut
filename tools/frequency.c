#include <stdio.h>
#include <string.h>

int show_count = 0;
int word_count[BUFSIZ];
char words[BUFSIZ][BUFSIZ];
char word[BUFSIZ];
char c;
int i;
int max;

inline static void print_help() {
	fprintf(stderr, "frequency [-n]\n");
}

int main(int argc, char ** argv) {
	if (argc == 2) {
		if (!strcmp(argv[1], "-n")) {
			show_count = 1;
		} else {
			print_help();
			return -1;
		}
	} else if (argc != 1) {
		print_help();
		return -1;
	}

	c = getchar();

	while (c != EOF) {
		i = 0;
		while (c != '\n' && c != ' ' && c != '\t') {
			word[i] = c;
			++i;
			c = getchar();
		}
		
		word[i] = 0;

		for (i = 0; words[i][0] != 0; ++i) {
			if (strcmp(word, words[i]) == 0)
				break;
		}

		if (words[i][0] == 0) {
			strcpy(words[i], word);
			word_count[i] = 0;
		}

		word_count[i] += 1;

		c = getchar();
	}

	while (1) {
		max = 0;

		i = 0;
		for (; words[i][0] != 0; ++i) {
			if (word_count[i] > word_count[max])
				max = i;
		}

		if (word_count[max] == -1)
			break;

		if (show_count)
			printf("%s %i\n", words[max], word_count[max]);
		else
			printf("%s\n", words[max]);

		word_count[max] = -1;
	}

	return 0;
}
