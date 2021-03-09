#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

double get_time() {
	struct timeval time;
	if (gettimeofday(&time, NULL))
		return 0;

	return (double)time.tv_sec + (double)time.tv_usec * 0.000001;
}

int main(int argc, char ** argv) {
	if (argc < 2) {
		fprintf(stderr, "performance iterations [command 1] [command 2] ...");
		return -1;
	}

	double t1, t2;
	char command[1024];
	int iterations = atoi(argv[1]);

	for (int cmd = 2; cmd < argc; ++cmd) {
		strcpy(command, argv[cmd]);
		strcat(command, " > /dev/null");
		t1 = get_time();
		for (int i = 0; i < iterations; ++i) {
			system(command);
		}
		t2 = get_time();
		printf("%s took %f seconds to execute %i times\n", argv[cmd], (t2 - t1), iterations);
	}

	return 0;
}
