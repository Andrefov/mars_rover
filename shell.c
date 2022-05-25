#include "shell.h"
#include "rover.h"
#include <stdlib.h>
int temp_unit = 0;


void shell_temp(const char* args)
{
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		if (rover_set_temp(atof(args)) == -1) {
			printf("ivalid value, type help or ?\n");
			return;
		}
		return;
	}
	else if (strncmp(args, "--size", 6) == 0) {
		int size_a = rover_get_temp_size();
		if (temp_unit == 0) {
			printf("size of temperature is %d bytes.\n", size_a);
			return;
		}
	}
	else if (strncmp(args, "--units", 7) == 0) {
		args += strlen("--units") + 1;
		if (strncmp(args, "C", 1) == 0) {
			temp_unit = 0;
		}
		else if (strncmp(args, "K", 1) == 0) {
			temp_unit = 1;
		}
		else
			printf("ivalid value, type help or ?\n");
		return;
	}

	if (temp_unit == 0) {
		printf("  temp: %.2f°C\n", rover_get_temp());
	}
	else {
		float temp_a = rover_get_temp()+ 273.15;
		printf("  temp: %.2f°K\n", temp_a);
	}

}

void shell_bat(const char* args)
{
	if (strncmp(args, "--set", 5) == 0) {
		args += strlen("--set") + 1;
		if (rover_set_bat(atoi(args)) == -1) {
			printf("ivalid value, type help or ?\n");
			return;
		}
		return;
	}
	else if (strncmp(args, "--size", 6) == 0) {
		int size_a = rover_get_bat_size();
		printf("size of battery is %d byte.\n", size_a);
		return;
	}

	printf("  bat: %d%%\n", rover_get_bat());
}

void shell_velocity(const char* args)
{
	if (strncmp(args, "--size", 6) == 0) {
		int size_a = rover_get_velocity_size();
		printf("size of velocity is %d bytes.\n", size_a);
		return;
	}
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
			printf("ivalid value, type help or ?\n");
			return;
		}
		return;
	}
	else if (strncmp(args, "--size", 6) == 0) {
		int size_a = rover_get_speed_size();
		printf("size of speed is %d bytes.\n", size_a);
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
			printf("ivalid value, type help or ?\n");
			return;
		}
		return;
	}
	else if (strncmp(args, "--size", 6) == 0) {
		int size_a = rover_get_direction_size();
		printf("size of direction is %d bytes.\n", size_a);
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
			printf("ivalid value, type help or ?\n");
			return;
		}
		return;
	}
	else if (strncmp(args, "--size", 6) == 0) {
		int size_a = rover_get_name_size();
		printf("size of name is %d bytes.\n", size_a);
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
			printf("ivalid value, type help or ?\n");
			return;
		}
	}
	else if (strncmp(args, "--size", 6) == 0) {
		int size_a = rover_get_status_size();
		printf("size of status is %d bytes.\n", size_a);
		return;
	}

	printf("Rover status is %s\n", rover_get_status());
}


