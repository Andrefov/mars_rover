enum rover_state{
	exploring,
	sampling,
	returning,
	idle,
};

void rover_init();

float get_temp();
void set_temp(float temp_);

int get_bat();
void set_bat(int bat_);

int get_velocity();
void set_velocity(int velocity_);

int get_temp_size();
int get_velocity_size();
int get_bat_size();

void get_temp_range();
void get_bat_range();
void get_velocity_range();

int get_status();
void set_status(enum rover_state rover_);

