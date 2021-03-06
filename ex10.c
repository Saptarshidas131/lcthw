// include standard input/output header
#include <stdio.h>

// prints the vowels in a input command line argument

// main function with command line arguments
int main(int argc, char *argv[])
{
    // if number of arguments is not 2 print the error
	if(argc != 2){
		printf("ERROR: You need one argument.\n");
		// this is how you abort a program
		return 1;
	}

    // set i to 0
	int i = 0;
    // goto through each letter of the command line argument
	for(i = 0; argv[1][i] != '\0'; i++){
        // assign each letter to variable letter
		char letter = argv[1][i];

        // the letter checked against the cases and if a match is found then it is printed otherwise not a vowel is printed
		switch(letter) {
			case 'a':
			case 'A':
				printf("%d: 'A'\n", i);
				break;
			
			case 'e':
			case 'E':
				printf("%d: 'E'\n", i);
				break;

			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
				break;

			case 'o':
			case 'O':
				printf("%d: 'O'\n", i);
				break;

			case 'u':
			case 'U':
				printf("%d: 'U'\n", i);
				break;

			case 'y':
			case 'Y':
				if(i > 2) {
					// it's only somtimes Y
					printf("%d: %c is not a vowel\n", i, letter);
				}
				break;
            
             // if no other cases match this is executed
			default:
				printf("%d: %c is not vowel\n", i, letter);
		}
	}

	return 0;
}
