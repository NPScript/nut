#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	double mul = 1;
	for (int i = 0; i < argc - 1; ++i) {
		mul *= atof(argv[i + 1]);
	}

	printf("%.15g\n", mul);

	return 0;
}
