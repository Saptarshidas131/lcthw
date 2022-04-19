// include standard input output header for i/o operations
#include <stdio.h>
// include assert header for 
#include <assert.h>
// include standard library header for malloc and exit
#include <stdlib.h>
// include errno header for errno and perror
#include <errno.h>
// include string header for strncpy
#include <string.h>

// use c preprocessor for creating constants
// MAX_DATA is the maximum data required for the entire database
#define MAX_DATA 700
// MAX_ROWS is the maximum rows that will be required for the rows in the database
#define MAX_ROWS 100

// create a structure Address of two integers and two char arrays, the piece of data created will be of fixed size
struct Address {
    // id stores the id of individual record
    int id;
    // used to check if a particular record is set or not
    int set;
    // name char array used to store name
    char name[MAX_DATA];
    // email char array is used to store email
    char email[MAX_DATA];
};

// create a Database made up of records where each record is of type struct Address
struct Database {
    // create an array rows of type struct Address which will be used to hold a record and each row is of size MAX_ROWS
    struct Address rows[MAX_ROWS];
};

// create a struct Connection of a file pointer and a Database pointer for Connecting to the database
struct Connection {
    // create a file pointer, for file handling
    FILE *file;
    // create a database pointer, for database handling
    struct Database *db;
};

// kill the program with and error if there's anything wrong
void die(const char *message)
{
    // if there's an error then external variable errno will be set
    if (errno) {
        // perror is used to print the error message
        perror(message);
    } else {
        // if no errno is not set
        printf("ERROR: %s\n", message);
    }
    // exit with return value 1, which represent an error or unsuccesful termination
    exit(1);
}

// prints the details of each individual Address or record
void Address_print(struct Address *addr)
{
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// loading the Database in memory, takes conn as a parameter
void Database_load(struct Connection *conn)
{
    // read the database by passing fread with the pointer returned by malloc, sizeof the struct Database , the number of members to read which is 1 and a pointer to the file
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    // on successful operation completion 1 is returned, otherwise a short item count(or zero) is returned, on error call die with error message
    if (rc != 1)
        die("Failed to load database.");
}

// open Database takes a pointer filename which is a pointer to a file and the mode of opening
struct Connection *Database_open(const char *filename, char mode)
{
    // allocate memory of the size of the struct Connection on heap and the pointer is assigned to conn
    struct Connection *conn = malloc(sizeof(struct Connection));
    // if no memory is allocated or there is some error then a NULL pointer is returned, if NULL is returned then die is called with error message
    if (!conn)
        die("Memory error.");

    // allocate memory for the Database and the pointer returned is assigned to db
    conn->db = malloc(sizeof(struct Database));
    // incase a NULL pointer is returned call die with the message Memory error
    if (!conn->db)
        die("Memory error.");

    // if mode is 'c' then open file in write mode othewise open in 'r+' mode and assign the pointer to file, fopen takes a file pointer and write mode
    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");
        
        // if the file has been opened successfully then call Database_load with the pointer conn
        if (conn->file) {
            Database_load(conn);
        }
    }

    // if NULL is returned then call die with the error message
    if (!conn->file)
        die("Failed to open the file");

    // return the pointer conn
    return conn;
}

// close the connection to the Database, the database and the file opened, takes conn as a parameter
void Database_close(struct Connection *conn)
{
    // if conn is not NULL 
    if (conn) {
        // if the file pointer is not NULL then close the file, here fclose takes a pointer to a file
        if (conn->file)
            fclose(conn->file);
        // if the db pointer is not NULL then free the memory allocated
        if (conn->db)
            free(conn->db);
        // free the memory allocated
        free(conn);
    }
}

// write to database, takes conn as a parameter
void Database_write(struct Connection *conn)
{
    // sets the file pointer to the beginning of the file 
    rewind(conn->file);

    // fwrite is called with a pointer to db, size of the Database, 1 item, and a pointer to file 
    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    // if unsuccessful then call die with error message
    if (rc != 1)
        die("Failed to write database.");

    // force a write of all user-space buffered data
    rc = fflush(conn->file);
    // if EOF or -1 is returned then call die with message, if fflush is not successful then EOF is returned and errno is set
    if (rc == -1)
            die("Cannot flush database");
}

// create database takes pointer conn as parameter
void Database_create(struct Connection *conn)
{
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        // set id to i and set to 0
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

// set the database, takes conn, id and a pointer name as parameters
void Database_set(struct Connection *conn, int id, const char *name,
        const char *email)
{
    // get the id element of rows which is in db, which is in conn then get the address & of it
    struct Address *addr = &conn->db->rows[id];
    // if set is 1 then call die with error message
    if (addr->set)
        die("Already set, delete it first");
    
    // set to 1 
    addr->set = 1;
    // WARNING: bug, read the "How to break it" and fix this
    // copy from name to addr->name
    char *res = strncpy(addr->name, name, MAX_DATA);
    // demonstrate the strncpy bug
    if (!res)
        die("Name copy failed");

    // copying MAX_DATA length of data from email to addr->email
    res = strncpy(addr->email, email, MAX_DATA);
    // if not copied successfully then NULL pointer is returned
    if (!res)
        die("Email copy failed");   
}

// get the records from Database
void Database_get(struct Connection *conn, int id)
{
    // get the id element of rows which is in db which is in conn then get the address of it
    struct Address *addr =  &conn->db->rows[id];

    // if the address is set then call Address_print with the address, othewise call die with error message
    if (addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

// delete a record in database, takes pointer conn and id as parameters
void Database_delete(struct Connection *conn, int id)
{
    // setting id and set
    struct Address addr = {.id = id, .set = 0};
    // get id of rows which is in db which is in conn and then assign to it
    conn->db->rows[id] = addr;
}

// list the records in Database, takes conn as a parameter 
void Database_list(struct Connection *conn)
{
    int i = 0;
    // get db which is in conn and assign to pointer db
    struct Database *db = conn->db;

    // iterate over the rows and if the record is set then print it by calling Address_print with pointer cur
    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];
        
        // if set is 1 which is withing cur then call Address_print with cur
        if (cur->set) {
            Address_print(cur);
        }
    }
}

// main function, takes command line arguments, argc counts the number of commandline arguments and argv stores the arguments
int main(int argc, char *argv[])
{
    // if number of command line arguments passed is less than 3 then call die with the message
    if (argc < 3)
        die("USAGE: ex17 <dbfile> <action> [action params]");

    // assign the filename pointer the second command line argument which is the database file
    char *filename = argv[1];
    // assign action the first character of the third command line argument
    char action = argv[2][0];
    // create connection by calling the Database_open with the database file and the action then assigning it to the pointer conn
    struct Connection *conn = Database_open(filename, action);
    // assign id 0
    int id = 0;

    // when the command line arguments is more than 3 then convert the fourth argument to integer and assign to id
    if (argc > 3) id = atoi(argv[3]);
    // if id is more or equal to MAX_ROWS then call die with message
    if (id >= MAX_ROWS) die("There's not that many records.");

    // switch statement with the action passed in, performs corresponding operation
    switch(action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':
            if (argc != 4)
                die("Need an id to get");

            Database_get(conn, id);
            break;

        case 's':
            if (argc != 6)
                die("Need   id, name, email to set");

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if (argc != 4)
                die("Need id to delete");

            Database_delete(conn, id);
            Database_write(conn);
            break;

       case 'l':
            Database_list(conn);
            break;
       // when no other case applies this will call die with the message
       default:
            die("Invalid action: c=create, g=get, s=set, d=delete, l=list");
    }

        // close the connection by calling Database_close by passing conn
        Database_close(conn);

        return 0;
    }
