// include standard input/output header
#include <stdio.h>

// prints the vowels in a input command line argument

// main function with command line arguments
int main(int argc, char *argv[])
{
    // handle all the command line arguments
    for(int j = 1; j < argc; j++)
    {

     char letter;
    // goto through each letter of the command line argument
	for(int i = 0; argv[j][i] != '\0', letter = argv[j][i]; i++){

        // convert to lowercase
        if(letter >= 65 && letter <=90)
            letter += 32;

        // the letter checked against the characters and if a match is found then it is printed otherwise not a vowel is printed
		if(letter == 'a')		
            printf("%d: 'a'\n", i);
        
        else if(letter == 'e')
            printf("%d: 'e'\n", i);

        else if(letter == 'i')
            printf("%d: 'i'\n", i);

        else if(letter == 'o')
            printf("%d: 'o'\n", i);

        else if(letter == 'u')
            printf("%d: 'u'\n", i);

        // if no other cases match this is executed
        else
            printf("%d: %c is not vowel\n", i, letter);
	}
  }
	return 0;
}
