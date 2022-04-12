/* include the contents of standard input/output (stdio) header file for using printf function */
#include <stdio.h>

/* This is a comment , mulitline*/
/* main function with integer return type, argc counts the number of command line arguments and argv takes a list of command line arguments */
int main(int argc, char *argv[])
{

    /* declaring and assigning 100 to a integer type variable distance */
    int distance = 100;

    // this is also a comment, single line
    // print the statement within quotes and replace %d format specfier by the value of the variable distance and then goto newline
    printf("You are %d miles away.\n", distance);

    // return value of 0 to the OS that tells that it exited successfully
	return 0;	
}
