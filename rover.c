#include "rover.h"


static unsigned char bat;
static unsigned int velocity;
enum rover_state status;
static char* name;
static float temp;

void rover_init(){
	temp = 210;
	bat = 99;
	velocity = 5;
	status = exploring;
	name = "internet explorer";
}


float rover_get_temp(){
	return temp;
}
void rover_set_temp(float temp_){
	temp = temp_;
}


int rover_get_bat(){
	return bat;
}
void rover_set_bat(int bat_){
	bat = bat_;
}


int rover_get_velocity(){
	return velocity;
}
void rover_set_velocity(int velocity_){
	velocity = velocity_;
}


int rover_get_temp_size(){
	return sizeof(temp);
}
int rover_get_bat_size(){
	return sizeof(bat);
}
int rover_get_velocity_size(){
	return sizeof(velocity);
}


void rover_get_temp_range(){

}
void rover_get_bat_range(){

}
void rover_get_velocity_range(){

}


char* rover_get_status() {
	switch (status) {
	case exploring:
		return "exploring";
	case sampling:
		return "sampling";
	case returning:
		return "returning";
	case idle:
		return "idle";
	}
}
void rover_set_status(enum rover_state status_){
	status = status_;
}

char *rover_get_name() {
	return name;
}
void rover_set_name(char* name_) {
	name = name_;
}
