/** stest.c
 * @author Laurentiu Pavel
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "employee.h"

void message();


int main()
{
    printf("Starting program stest.\n");

    Employee harry; // Declare a local variable (a struct).
    harry.salary = 5000;
    harry.name = strdup("Harry Palmer"); // Make a dynamic copy.
    harry.department = strdup("poor people"); // Make a dynamic copy

    Employee bluejay; // Declare a local variable (a struct).
    bluejay.salary = 10000;
    bluejay.name = strdup("Erik Grantby"); // Make a dynamic copy.
    bluejay.department= strdup("rich people"); // make a dynamic copy

    // Output the employees to stdout.
    printEmployee(&harry);
    printEmployee(&bluejay);

    //  Output the employees to a file.
    printf("About to write to file.\n");
    FILE *outfile = fopen("stest.txt", "w"); // Open or create file for writing

    if( outfile==NULL )    // if stream is not created
    {
      // prints the error and return 1
        fprintf(stderr,"in stest.c - cannot create the file: %s\n",strerror(errno) );
        return 1;
    }

    outputEmployee(outfile, &harry);
    outputEmployee(outfile, &bluejay);
    fclose(outfile); // Close the file


    message();


    printf("\n----- Part 2 -----\n\n");

    Employee* john; Employee* mike;
    john = make_employee(22000,"John","Computer Science");        //construct john
    mike = make_employee(21000,"Mike","Electrical Engineering");  //construct mike

    printEmployee(john);
    printEmployee(mike);

    printf("\n------- Part 3 ------\n\n");

    Employee* misu;

    misu=manually_create();  // create misu manually;

    printf("Ending program stest.\n");
    return 0;
}
