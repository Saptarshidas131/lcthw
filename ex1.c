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

    // 5 more lines complex than hello world
    // print the value of argc, the number of command line arguments given
    printf("Value of argc is %d\n", argc);
    // print the value of first command line argument, which is the program name itself
    printf("value of argv0 is %s\n", argv[0]);
    // print a line
    printf("Hello World is usually the first program\n");
    // print the statement, evaluate expression and replace %d with the value
    printf("adding 2 + 2 is %d\n", 2 + 2);
    // print the statement and then do the multiplication and replace %d by its value
    printf("multiplying is repeated addition, multiplying 2 x 3 is actually 2 times we add 3 to get %d\n", 2 * 3);
    // return value of 0 to the OS that tells that it exited successfully
	return 0;	
}
