#include <stdio.h>
#include "rover.h"
#include "string.h"

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
		printf("invalid input try again\n");
		return -1;
	}
	line[strlen(line) - 1] = '\0';

	return 0;
}
	

int main() {
	
	for (;;) {
		char line[128];
		rover_init();

		command_promt();
		if (readline(line, sizeof(line))) {
			continue;
		}

		if (strcmp(line, "temperature") == 0) {
			float temperature = get_temp();
			printf("Current temperature is %7.2f\n", temperature);
			printf("input new value in range from -273.15 to 150");
		}

		if (strcmp(line, "exit") == 0)
			break;
	}
	return 0;
}


	












