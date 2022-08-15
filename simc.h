/*

SIMC.H
(Simplified Commands)
8/11/2022

*/

// *cmd is the command to execute
// *outp is where the output will be stored
int silent_run(char *cmd, char *outp);

int silent_run(char *cmd, char *outp) {
	FILE *p;
	char c;

	p = popen(cmd, "r");
	if (p == NULL) {
		printf("%s\n", "Process failed to run.");
		pclose(p);
		return 1;
	} else {
		while ( (c=fgetc(p)) != EOF ) {
			strcat(outp, &c);
		}
	}
	pclose(p);
	
	return 0;
}