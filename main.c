#include <stdio.h>
#include "rover.h"

void command_promt(){
	printf("Type command listed bellow:\n");
	printf("temperature, battery, velocity, status, name\n");
	printf("temperature size, battery size, velocity size, name size\n");
	printf("temperature range, battery range, velocity range\n");
	printf("temp absolute, units, exit\n");
}

int readline(char* line, size_t llen) {
	line[llen - 1] = 0xaa;
	if (fgets(line, llen, stdin) == NULL)
		return -1;

	if (line[llen - 1] == '\0' && line[llen - 2] != '\n') {
		printf("invalid input try again.\n");
		return -1;
	}

	return 0;
}
	

int main() {
	char line[128];
	for (;;) {

		command_promt();
		if (readline(line, sizeof(line)))
			continue;

		if (strcmp(line, "temperature")== 0) {
			float temperature = get_temp();
			printf("Current temperature is %7.2f", temperature);
		}

		if (strcmp(line, "exit") == 0)
			break;
	}
	return 0;
}


	












