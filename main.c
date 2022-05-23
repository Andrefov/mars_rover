#include <stdio.h>
#include "rover.h"
#include "shell.h"
#include "string.h"
#include <stdlib.h>



int readline(char* line, size_t llen) {
	line[llen - 1] = 0xaa;

	if (fgets(line, llen, stdin) == NULL)
		return -1;

	if (line[llen - 1] == '\0' && line[llen - 2] != '\n') {
		printf("invalid input try again\n");
		return -1;
	}
	line[strlen(line) - 1] = '\0';

	return 0;
}

int main() {

	rover_init();

	for (;;) {
		char line[128];

		printf("cmd> ");
		if (readline(line, sizeof(line))) {
			continue;
		}

		if (strcmp(line, "help") == 0 || strcmp(line, "?") == 0) {
			printf("temp      <[--get]|--set>\n");
			printf("bat       <[--get]|--set>\n");
			printf("velocity  <[--get]|--set> 0 -\n");
			printf("name      <[--get]|--set>\n");
			printf("status    <[--get]|--set> exploring, sampling, returning, idle\n");
			printf("exit\n");
		}
		else if (strncmp(line, "temp", 4) == 0)
			shell_temp(line + 4);
		else if (strncmp(line, "bat", 3) == 0)
			shell_bat(line + 3);
		else if (strncmp(line, "velocity", 8) == 0)
			shell_velocity(line + 8);
		else if (strncmp(line, "name", 4) == 0)
			shell_name(line + 4);
		else if (strncmp(line, "status", 6) == 0)
			shell_status(line + 6);
		else if (strcmp(line, "exit") == 0)
			break;
	}
	return 0;
}















