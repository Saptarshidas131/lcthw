// include the headers
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
// incase of an error prints the message and exits
void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR : %s\n", message);
    }
      
    exit(1);
}

// a typedef creates a fake type in this
// case for a function pointer
typedef int (*compare_cb) (int a, int b);

/**
 * A classic bubble sort function that uses the
 * compare_cb function to do the sorting
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    // declare 3 variables to store numbers and perform swap
    int temp = 0;
    int i = 0;
    int j = 0;
    // allocate memory for the target array
    int *target = malloc(count * sizeof(int));

    // if memory not allocated and NULL is returned
    if (!target)
        die("Memory error.");

    // copy numbers to target, allocate memory equivalent to the count of numbers
    memcpy(target, numbers, count * sizeof(int));

    // do the swapping
    for (i = 0; i < count; i++) {
        for (j = 0; j < count - 1; j++) {
            if (cmp(target[j], target[j + 1]) > 0) {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }

    // return the target array after sorting
    return target;
}

// sorts in ascending order
int sorted_order(int a, int b)
{
    return a - b;
}

// sorts in descending order
int reverse_order(int a, int b)
{
    return b - a;
}

// sorts in weird order
int strange_order(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/** 
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    // call bubble_sort with the pointer numbers, count of the numbers and cmp
    int *sorted = bubble_sort(numbers, count, cmp);

    // if there is some error
    if (!sorted)
        die("Failed to sort as requested.");

    // print the sorted array
    for (i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    // free the memory allocated
    free(sorted);
}

int main(int argc, char *argv[])
{
    // if the command line arguments passed in is less than 2
    if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

    // exclude the filename from the count
    int count = argc - 1;
    int i = 0;
    // point the char double pointer to the second command line argument
    char **inputs  = argv + 1;

    // allocate memory for numbers eqivalent to the count for the size of int
    int *numbers = malloc(count * sizeof(int));
    // if a valid pointer is no returned then call die with message
    if (!numbers) die("Memory error.");

    // convert the numbers given as command line arguments to integers
    for (i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    // calling the functions with the parameters
    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    // free the memory allocated for numbers
    free(numbers);

    return 0;
}
