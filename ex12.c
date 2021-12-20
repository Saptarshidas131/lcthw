// include standard input/output header
#include <stdio.h>

// main function
int main(int argc, char *argv[])
{

    // declare and initilize an array of intergers
	int areas[] = {10, 12, 13, 14, 20};
    // initilize a character array
	char name[] = "Saptarshi";
    // initialize another character array
	char full_name[] = {'S', 'a', 'p', 't', 'a', 'r', 's', 'h', 'i', ' ', 'D', 'a', 's'};

	// WARNING: On some systems you may have to change the
	//  %ld in this code to a %u since it will use unisigned ints
    //  print the size of different data types using sizeof operator
	printf("The size of int: %ld\n", sizeof(int));
    // divide the size of areas by size of int to get the total integers
	printf("The size of areas (int[]): %ld\n", sizeof(areas) / sizeof(int));
    // print the areas element by array indexing
	printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1]);
    // character size
	printf("The size of char: %ld\n", sizeof(char));
    // size of the name array
	printf("The size of name (char[]): %ld\n", sizeof(name));
    // get the total characters in the characte array
	printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));
    // prints the size of full_name array
	printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
    // prints the number of charactes in full_name
	printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));
    // pirints name and full_name
	printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

	return 0;
}
