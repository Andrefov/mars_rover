#include "shell.h"
#include "rover.h"
#include <stdlib.h>


void shell_temp(const char* args)
{
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		rover_set_temp(atof(args));
		return;
	}

	printf("  temp: %.2f°C\n", rover_get_temp());
}

void shell_bat(const char* args)
{
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		rover_set_bat(atoi(args));
		return;
	}

	printf("  bat: %d%%\n", rover_get_bat());
}

void shell_velocity(const char* args)
{
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		rover_set_velocity(atoi(args));
		return;
	}
	int * direction_;
	direction_ = 0;
	int * magnitude_;
	magnitude_ = 0;
	rover_get_velocity(direction_, magnitude_);
	printf("  velocity:%d km\\h, direction: %d degrees\n", direction_, magnitude_ );
}

void shell_name(const char* args)
{
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		rover_set_name(args);
		return;
	}

	printf("Rover name is %s\n", rover_get_name());
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
		return;
	}

	printf("Rover status is %s\n", rover_get_status());
}


