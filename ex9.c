// include standard input/output header
#include <stdio.h>

// main function with command line arguments
int main(int argc, char *argv[])
{
    // assign 0 to i
    int i = 0;
    
    // start a  while loop and iterate as long as i is less than 25
    while(i < 25)
    {
        // print the value of i
        printf("%d ",i);
        // increment i by 1, post increment
        i++;
    }
    // return 0 from main
    return 0;
}
