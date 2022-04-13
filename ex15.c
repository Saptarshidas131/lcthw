#include <stdio.h>

int main(int argc, char *argv[])
{
	// create two arrays we care about
	// initialize ages with 5 integers
    int ages[] = {23, 43, 12, 89, 2};
    // intialize an pointer to an array of characters pointers with 5 names, each index in the names array points to a memory location holding the actual name or which is a character array so names is 1-d and it holds the adress or reference to the actual name
	char *names[] = {
		"Alan", "Frank",
        "Mary", "John", "Lisa"
	};

	// safely get the sizes of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	// first way using indexing
	for(i = 0; i < count; i++) {
		printf("%s has %d years alive. \n", names[i], ages[i]);
	}

	printf("---\n");

	// setup the pointers to the start of the arrays
    // declare a integer pointer to point to ages
	int *cur_age = ages;
    // declare a character pointer to point to names, two * are used since cur_name is 2-d and names which is 1-d is holds pointers to individual character arrays and to access that 2-d pointer is needed
	char **cur_name = names;

	// second way using pointers
    // iterate from 0 to untill less than count, print names and ages using pointer arithmatic
	for(i = 0; i < count; i++) {
		printf("%s is %d years old. \n",
                *(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	// third way, pointers are just arrays
    // print the names and ages using array syntax
	for(i = 0; i < count; i++) {
		printf("%s is %d years old again.\n",  cur_name[i], cur_age[i]);
	}

	printf("---\n");

	// fourth way with pointers in a stupid complex way
    // set cur_name to point to the first index of names and cur_age to point to first index of ages, calculate the distance from ages to the cur_age and loop until less than count, increment the cur_name and cur_age to point to next name and age respectively
	for(cur_name = names, cur_age = ages; 
            (cur_age - ages) < count; cur_name++, cur_age++){
        // print the name and age by pointer dereferencing
		printf("%s lived %d years so far. \n", *cur_name, *cur_age);
	}

	return 0;
}
