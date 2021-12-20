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
        // convert uppercase to lowercase letter
        if (letter >= 65 && letter <= 90)
           letter += 32; 

        // the letter checked against the cases and if a match is found then it is printed otherwise not a vowel is printed
		switch(letter) {
			case 'a':
				printf("%d: 'a'\n", i);
				break;
			
			case 'e':
				printf("%d: 'e'\n", i);
				break;

			case 'i':
				printf("%d: 'i'\n", i);
				break;

			case 'o':
				printf("%d: 'o'\n", i);
				break;

			case 'u':
				printf("%d: 'u'\n", i);
				break;

			case 'y':
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
