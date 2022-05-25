#include "rover.h"
#include "string.h"
#include <stdio.h>


static unsigned char bat;
struct vector velocity;
enum rover_state status;
static char* name;
static float temp;

void rover_init(){
	temp = -210;
	velocity.direction = 0;
	velocity.magnitude = 25;
	bat = 99;
	status = exploring;
	name = "internet explorer";
}


float rover_get_temp(){
	return temp;
}
int rover_set_temp(float temp_) {
	float temp_a = temp_;
	temp_a *= 100;
	temp_a= (int)temp_a;
	if (temp_a > -27315 && temp_a <=20000){
		temp = temp_;
		return 0;
	}
	else
		return -1;
}


int rover_get_bat(){
	return bat;
}
int rover_set_bat(int bat_){
	if (bat_ >= 0 && bat_ <= 100) {
		bat = bat_;
		return 0;
	}
	else if (bat_ == 0) {
		rover_set_status(idle);
		return 0;
	}
	else
		return -1;
	bat = bat_;
}


int rover_get_velocity(int *direction_, int *magnitude_) {
	*direction_ = velocity.direction;
	*magnitude_ = velocity.magnitude;
	return 0;
}
int rover_set_velocity(int direction_, int magnitude_) {
	if (direction_ >= 0 && direction_ <= 359) {
		velocity.direction = direction_;
		return 0;
	}
	else if (magnitude_ >= 0 && magnitude_ <= 50) {
		velocity.magnitude = magnitude_;
		return 0;
	}
	else return -1;
		
}


int rover_get_temp_size() {
	return sizeof(temp);
}
int rover_get_bat_size() {
	return sizeof(bat);
}
int rover_get_velocity_size() {
	return sizeof(velocity);
}
int rover_get_speed_size() {
	return sizeof(velocity.magnitude);
}
int rover_get_direction_size() {
	return sizeof(velocity.direction);
}
int rover_get_name_size() {
	return sizeof(name);
}
int rover_get_status_size() {
	return sizeof(status);
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
int rover_set_name(char* name_) {
	if ((strlen(name_) - 1) > 0 && (strlen(name_) - 1) <= 20) {
		name = name_;
		return 0;
	}
	else
		return -1;
}
