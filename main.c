#include <stdio.h>
#include "rover.h"

void command_promt() {
	printf("Type command listed bellow:\n");
	printf("temperature, battery, velocity\n");
	printf("temperature size, battery size, velocity size\n");
	printf("temperature range, battery range, velocity range\n");
	printf("temp absolute, units, exit\n");
}

const char* input_reader() {
	char line[128];
	line[sizeof(line) - 1] = 0xaa;
	
	char buffer[30];
	fgets(buffer, sizeof(buffer), stdin);
	if (fgets(line, sizeof(line), stdin) == NULL)
		printf("invalid input, try again.\n");
		

	if (line[sizeof(line) - 1] == '\0' && line[sizeof(line) - 2] != '\n') 
		printf("invalid input, try again.\n");
		
		

	return buffer;
		
}





int main(){

	const char* input = 0;


	while (input != "exit") {
		command_promt();
		input = input_reader();
			
		
	}
return 0;

};











