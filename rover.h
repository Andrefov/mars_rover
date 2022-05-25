enum rover_state{
	exploring,
	sampling,
	returning,
	idle,
};

struct vector { unsigned int direction; unsigned int magnitude; };

void rover_init();

float rover_get_temp();
int rover_set_temp(float temp_);

int rover_get_bat();
int rover_set_bat(int bat_);

int rover_get_velocity(int* direction_, int* magnitude_);
int rover_set_velocity(int direction_, int magnitude_);

int rover_get_temp_size();
int rover_get_velocity_size();
int rover_get_speed_size();
int rover_get_direction_size();
int rover_get_bat_size();
int rover_get_name_size();
int rover_get_status_size();

char* rover_get_status();
void rover_set_status(enum rover_state rover_);

char* rover_get_name();
int rover_set_name(char* name_);



