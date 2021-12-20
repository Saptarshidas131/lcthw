// import standard input/output header
#include <stdio.h>

// main function with command line arguments
int main(int argc, char *argv[])
{
    // set i to 0
	int i = 0;
	
    // check if the number of arguments is 1, then print the statement
	if(argc == 1) {
		printf("You only have one argument. You suck.\n");
    // if the number of arguments is between 1 and 4 then print the arguments
	} else if(argc > 1 && argc < 4) {
		printf("Here's your arguments:\n");

		for(i = 0; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
     // if there more than 4 arguments then print
	} else {
		printf("You have too many arguments. You suck. \n");
	}
	return 0;
}
