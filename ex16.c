// include standard I/O header file for printing
#include <stdio.h>
// include assert header fiel for assert function
#include <assert.h>
// add standard library header file for malloc and free functions
#include <stdlib.h>
// add string header for strdup function
#include <string.h>

// create a Person structure with 4 attributes to describe a person
struct Person{
    char *name;
    int age;
    int height;
    int weight;
};

// define function Person_create of type Person to actually take parameters from the function call and set them to the attributes in the Person structure
struct Person *Person_create(char *name, int age, int height, 
        int weight)
    {
        // sizeof calculates the total memory required for the structure Person and allocates memory using malloc which is pointed to the pointer who of type struct Person
        struct Person *who = malloc(sizeof(struct Person));
        // checking if a valid piece of memory block is returned means the pointer returned is not NULL or invalid, if no memory is allocated or there some memory problem then a NULL pointer is returned
        assert(who != NULL);

        // strdup duplicates the string in name and set the name attribute in the structre Person, it allocates memory for the name somewhat like malloc by copying the original string into the memory it creates
        // -> is used to access individual elements within a structure using pointer and who->name is same as (*who).name
        who->name = strdup(name);
        // all the attributes in struct Person are set to the values of the parameters passed in function call
        who->age = age;
        who->height = height;
        who->weight = weight;

        // return the pointer who of type struct Person
        return who;
    }

// define a function Person_destroy which destroys the Person structures
void Person_destroy(struct Person *who)
{
    // check if the pointer returned is not NULL or invalid, memory has been allocated successfully without errors
    assert(who != NULL);

    // free the memory allocated for name by strdup
    free(who->name);
    // free the memory allocated by malloc
    free(who);
}

// function to print the structures created, the attribute values
void Person_print(struct Person *who)
{
    // prints out the each attribute or element for a Person
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

// main function
int main(int argc, char *argv[])
{
    // make two people structures
    // create a Person joe of type struct Person with the following parameters passed by calling the function Person_create
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    
    // create another person frank with different parameters
    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

    // print them out and where they are in memory, %p prints the memory location of the Person joe, which is the memory location pointed by pointer joe
    printf("Joe is in memory location %p:\n", joe);
    Person_print(joe);

    // print the memory location of frank by %p, actually it is the memory location pointed by the pointer frank
    printf("Frank is in memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 and print them again
    // change the attributes for joe, -> is used to access elements within a structure using pointer
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    // print the updated attributes for joe by calling Person_print with the pointer joe of type struct Person
    Person_print(joe);

    // update attributes for frank
    frank->age += 20;
    frank->weight += 20;
    // print the updated attributes for frank
    Person_print(frank);

    // destroy them both so we can clean up
    // call Person_destroy with pointer of type struct Person which frees up the space allocated for the structure Person
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
