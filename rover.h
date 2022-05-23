enum rover_state{
	exploring,
	sampling,
	returning,
	idle,
};

void rover_init();

float rover_get_temp();
void rover_set_temp(float temp_);

int rover_get_bat();
void rover_set_bat(int bat_);

int rover_get_velocity();
void rover_set_velocity(int velocity_);

int rover_get_temp_size();
int rover_get_velocity_size();
int rover_get_bat_size();

void rover_get_temp_range();
void rover_get_bat_range();
void rover_get_velocity_range();

char* rover_get_status();
void rover_set_status(enum rover_state rover_);

char* rover_get_name();
void rover_set_name(char* name_);



