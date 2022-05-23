#include "rover.h"


unsigned char bat;
unsigned int velocity;
rover_state;
const char* name;
float temp;

void rover_init(){
	temp = 210;
	bat = 99;
	velocity = 5;
	rover_state = exploring;
	name = "internet explorer";
}


float get_temp(){
	return temp;
}
void set_temp(float temp_){
	temp = temp_;
}


int get_bat(){
	return bat;
}
void set_bat(int bat_){
	bat = bat_;
}


int get_velocity(){
	return velocity;
}
void set_velocity(int velocity_){
	velocity = velocity_;
}


int get_temp_size(){
	return sizeof(temp);
}
int get_bat_size(){
	return sizeof(bat);
}
int get_velocity_size(){
	return sizeof(velocity);
}

void get_temp_range(){

}
void get_bat_range(){

}
void get_velocity_range(){

}

int get_status(){
	return rover_state;
}
void set_status(enum rover_state status_){
	rover_state = status_;

}

