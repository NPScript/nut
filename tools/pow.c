#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	if (argc < 2)
		return -1;

	double pow = 1;
	double org = atof(argv[1]);
	int n = 0;
	int is_neg = 0;

	for (int i = 2; i < argc; ++i) {
		n += atof(argv[i]);
	}

	if (n < 0) {
		n *= -1;
		is_neg = 1;
	}

	for (int i = 0; i < n; ++i) {
		pow *= org;
	}

	if (is_neg)
		pow = 1 / pow;

	printf("%.15g\n", pow);

	return 0;
}
