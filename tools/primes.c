#include <stdio.h>
#include <stdlib.h>

int * primes;
int limit;
int i;
int j;

int main(int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "primes [limit]\n");
		return -1;
	}
	limit = atoi(argv[1]);

	primes = (int *)malloc(limit * sizeof(int));

	for (i = 0; i < limit; ++i)
		primes[i] = 0;

	for (i = 2; i < limit; ++i) {
		if (!primes[i]) {
			printf("%i\n", i);
			for (j = i*i; j < limit; j += i)
				primes[j] = 1;
		}
	}

	return 0;
}
