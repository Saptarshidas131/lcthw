// include standard input/output header
#include <stdio.h>

// main function with command line parameters
int main(int argc, char *argv[])
{
    // set i to 0
	int i = 0;

	// go through each string in argv
	// argv[0] is the name of the program
	for(i = 1; i < argc; i++)
	{
        // print the 1 to to end the number of command line arguments and the string given as arguments
		printf("arg %d: %s\n", i, argv[i]);
	}

	// let's make our own array of strings
	char *states[] = {"Delhi", "Maharastra", "Kernataka","Assam"};
    // assign 4 to num_states
	int num_states = 4;

    // loop over the array of strings and print
	for(i = 0; i < num_states; i++)
	{
		printf("state %d: %s\n", i, states[i]);
	}

	return 0;
}
