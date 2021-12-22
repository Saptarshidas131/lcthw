#include <stdio.h>

int main(int argc, char *argv[])
{
    // initialize the first element with 0 and the rest of array is filled with 0
	int numbers[4] = {0};
    // initialize the first element with 'a' and the rest of array is filled with 0
	char name[4] = {'a'};

	// first, print them out raw
    // print the numbers array element by element
	printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
    // print the name array element by element
	printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
    // print name
	printf("name: %s\n", name);

	// setup the numbers
    // assign each integer to the array index separately
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

	// setup the name
    // assign each character to the name array index seperately followed by the null character
	name[0] = 'S';
	name[1] = 'd';
	name[2] = 'a';
	name[3] = 's';
	name[4] = '\0';

	// then print them out initialized
	printf("numbers: %d %d %d %c\n", numbers[0], numbers[1],numbers[2],numbers[3]);
	printf("name of each: %c %c %c %c\n", name[0], name[1], name[2], name[2]);

	// print the name like a string
	printf("name: %s\n", name);

	// another way to use name
    // use character pointer to intialize a character array
	char *another = "SDas";

    // print the array
	printf("another: %s\n", another);

    // print the array element wise
	printf("another each: %c %c %c %c\n", another[0], another[1], another[2], another[3]);

	return 0;

}
