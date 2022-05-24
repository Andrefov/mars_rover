#include "shell.h"
#include "rover.h"
#include <stdlib.h>


void shell_temp(const char* args)
{
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		if (rover_set_temp(atof(args)) == -1) {
			printf("ivalid value, type ""help"" or ""?"" \n");
			return;
		}
		return;
	}

	printf("  temp: %.2f°C\n", rover_get_temp());
}

void shell_bat(const char* args)
{
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		if (rover_set_bat(atoi(args)) == -1) {
			printf("ivalid value, type ""help"" or ""?"" \n");
			return;
		}
		return;
	}

	printf("  bat: %d%%\n", rover_get_bat());
}

void shell_velocity(const char* args)
{
	int direction = 0;
	int magnitude = 0;
	
	rover_get_velocity(&direction, &magnitude);
	printf("velocity:%d km\\h, direction: %d degrees\n", magnitude, direction);
}

void shell_speed(const char* args) {
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		int a = atoi(args);

		if (rover_set_velocity(-1, atoi(args)) == -1) {
			printf("ivalid value, type ""help"" or ""?"" \n");
			return;
		}
		return;
	}
	int direction = 0;
	int magnitude = 0;

	rover_get_velocity(&direction, &magnitude);
	printf("velocity:%d km\\h, \n", magnitude);
}

void shell_direction(const char* args) {
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		int a = atoi(args);

		if (rover_set_velocity(atoi(args), -1) == -1) {
			printf("ivalid value, type help or ? \n");
			return;
		}
		return;
	}
	int direction = 0;
	int magnitude = 0;

	rover_get_velocity(&direction, &magnitude);
	printf("direction: %d degrees\n", direction);
}

void shell_name(const char* args)
{
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		if (rover_set_name(args) == -1) {
			printf("ivalid value, type help or ? \n");
			return;
		}
		return;
	}

	printf("Rover name is: %s\n", rover_get_name());
}

void shell_status(const char* args) 
{
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		if (strcmp(args, "exploring") == 0){
			rover_set_status(exploring);
			rover_set_velocity(-1, 25);
		}

		else if (strcmp(args, "sampling") == 0) {
			rover_set_status(sampling);
			rover_set_velocity(-1, 0);
		}

		else if (strcmp(args, "returning") == 0) {
			rover_set_status(returning);
			rover_set_velocity(-1, 25);
		}

		else if (strcmp(args, "idle") == 0) {
			rover_set_status(idle);
			rover_set_velocity(-1, 0);
		}
		else {
			printf("ivalid value, type ""help"" or ""?"" \n");
			return;
		}
	}

	printf("Rover status is %s\n", rover_get_status());
}


