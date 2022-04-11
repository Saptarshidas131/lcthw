// include the stdio header to perform standard input/output functions, to use printf here
#include <stdio.h>

// main function with integer return type
int main()
{
    // assign 10 to integer vriable age 
	int age = 10;
    // assign 72 to height
	int height = 72;

    // print age and height using formatted string %d which is replaced by the variable value
	printf("I am %d years old.\n",age);
	printf("I am %d inches tall.\n",height);

    // return 0 to OS to successful program exit
	return 0;
}
