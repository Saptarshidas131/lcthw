// include standard input/output header
#include <stdio.h>

// main function with command line arguments
int main(int argc, char *argv[])
{
    // assign 25 to i
    int i = 25;
    
    // start a  while loop and iterate as long as i is greater than or equal to 0
    while(i >= 0)
    {
        // print the value of i
        printf("%d ",i);
        // decrement i by 1, post decrement
        i--;
    }
    // return 0 from main
    return 0;
}
