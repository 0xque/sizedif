#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simc.h"

int main(int argc, char *argv[]) {
	
	if (argc == 2 && strcmp(argv[1], "--help") == 0) {
		printf("sizedif is a utility program written in C that calculates\nthe size difference in bytes between two given files.\n\n");
		printf("Args: --help OR <file_1> <file_2>\n");
		return 0;
	}
	if (argc != 3) {
		printf("Incorrect args! Program expects two file names.\n");
		return 1;
	}

	// char arrs where cmds will be stored
	char cmd1[100] = "cat ";
	char cmd2[100] = "cat ";

	// Setup cmds to read # of chars in file
	strcat(cmd1, argv[1]);
	strcat(cmd1, " | wc -c");
	strcat(cmd2, argv[2]);
	strcat(cmd2, " | wc -c");

	// char arrs where output will be stored
	char out1[16] = {0};
	char out2[16] = {0};

	// Executes cmds and stores output
	silent_run(cmd1, out1);
	silent_run(cmd2, out2);

	printf("%s_SIZE: %s", argv[1], out1);
	printf("%s_SIZE: %s", argv[2], out2);
	printf("SIZE_DIF: %d\n", abs(atoi(out1) - atoi(out2)));
	
	return 0;
}