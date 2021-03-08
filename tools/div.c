#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	if (argc < 2)
		return -1;

	double div = atof(argv[1]);
	for (int i = 1; i < argc - 1; ++i) {
		div /= atof(argv[i + 1]);
	}

	printf("%.15g\n", div);

	return 0;
}
