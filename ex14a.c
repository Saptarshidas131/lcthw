// include standard input/output header
#include <stdio.h>
// include ctype header for isalpha and isblank
#include <ctype.h>
// include string header for strlen function
#include <string.h>

// forward declarations
// declare the functions before use
int can_print_it(char ch);
void print_letters(char arg[], int slength);

// print_arguments function takes two arguments which are command line arguments to main
void print_arguments(int argc, char *argv[])
{
	int i = 0;
	
    // go through all the arguments call print_letters on it
	for(i = 0; i < argc; i++) {
        int slen = strlen(argv[i]);
		print_letters(argv[i], slen);
	}
}

// print_letters takes one argument and  prints ASCII code of it if it is a alphabet of blank 
void print_letters(char arg[], int slength)
{
	int i = 0;

    // go through the argument till the length of the argument
	for(i = 0; i < slength; i++) {
        // assign each character of the argument to a character variable ch
		char ch = arg[i];

        // check if it is printable by passing it to can_print_it function
		if(can_print_it(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}
    //  print newline after printing a string
	printf("\n");
}

// check if the the character is an alphabet or blank
int can_print_it(char ch)
{
	return isalpha(ch) || isblank(ch);
}

// main with command line arguments
int main(int argc, char *argv[])
{
    // call print_arguments by passing the two arguments
	print_arguments(argc, argv);
	return 0;
}
