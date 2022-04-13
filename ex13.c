// include standard input/output header
#include <stdio.h>

// main function with command line parameters
int main(int argc, char *argv[])
{
    // assign 0 to i
	int i = 0;

	// go through each string in argv
	// argv[0] is the name of the program, so skipping it and starting from 1
	for(i = 1; i < argc; i++)
	{
        // print the ith number of command line argument and the string passed as argument
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
