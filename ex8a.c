/* for extra credit */

// include standard input/output header
#include <stdio.h>

// main function with command line arguments, argc stores the number of command line arguments passed and argv stores the arguments as a character array
int main(int argc, char *argv[])
{
    // assign 0 to i
	int i = 0;
	
    // ignoring the first argument, the program name
    argc = argc - 1; 
    
    // if no arguments entered by user
    if(argc == 0)
    {
        printf("You have not entered any arguments.\n");
    // check if the number of arguments is 1 ignoring the program name, then print the statement
      else if(argc == 1) 
    {
        // there will always be 1 argument which the the first argument argv[0] or the program name itself, which is passed to execute the program
		printf("You only have one argument. You suck.\n");
    // if the number of arguments is between 1 and 4 then print the arguments
	} else if(argc > 2 && argc < 4) {
		printf("Here's your arguments:\n");
        
        // using a loop to iterate over argv and print the arguments stored in it
		for(i = 0; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
     // if every other condition is false or 0 then execute else, if 4 or more 4 arguments are passed then print the statement
	} else {
		printf("You have too many arguments. You suck. \n");
	}
    // exit with return value 0
	return 0;
}
