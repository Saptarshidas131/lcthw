// import standard input/output header i/o operations
#include <stdio.h>

// main function
int main(int argc, char *argv[])
{
    // variable declaration and assignment
	int  distance = 100;
	float  power = 2.345f;
	double super_power = 566789.4532;
	char initial = 'S';
    // assign the variable the character array
	char first_name[] = "Saptarshi";
	char last_name[] = "Das";

    // print out the statements and the variable values
	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n",super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s.\n",last_name);
	printf("My whole name is %s %c.  %s.\n", first_name, initial, last_name);

    // make some fake bug data
	int bugs = 100;
	double bug_rate = 1.2;

    // print it out
	printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);

    // assign some large data with the long type modifier
	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
    // print it out
	printf("The entire universe has %ld bugs. \n", universe_of_defects);

    // do some calculation and print it on next line
	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n",expected_bugs);

    // calculate the rate of bugs compared to bugs in universe
	double part_of_universe = expected_bugs / universe_of_defects;
    // print it
	printf("That is only a %e portion of the universe.\n", part_of_universe);

	// this make no sense, just a demo of something weird
    // null character \0 or 0 is assigned to nul_byte
	char nul_byte = '\0';
    // multiply with bugs to get 0
	int care_percentage = bugs * nul_byte;
    // print it, %% is used to print %
	printf("Which means you should care %d%%. \n", care_percentage);

	return 0;

}
