/** employee.c
 * @author Laurentiu Pavel
 */

#include<stdio.h>
#include <string.h>
//#include <readline/readline.h>
//#include <readline/history.h>
//#include <curses.h>
//#include <term.h>

#include "employee.h"

void printEmployee(Employee *employee)
{
  fprintf(stdout, "Employee. Name = %s, Salary = %d, Department = %s\n",
	  employee->name, employee->salary, employee->department);
}

void outputEmployee(FILE *stream, Employee *employee)
{


    fprintf(stream, "Employee. Name = %s, Salary = %d, Department = %s\n",
	  employee->name, employee->salary,employee->department); // prints in the file
}

/** prints a message if DEBUG was defined from preprocesor
 * no parameters, no return
 */

void message()
{
#ifdef DEBUG
  fprintf(stdout,"\na message\n");
#endif
}

Employee* make_employee(int s, char* n, char* dep)
{
    Employee* emp=(Employee*) malloc(sizeof(Employee));  // allocate memory first

    emp->salary = s;        // introduce salary
    emp->name = strdup(n);  // make a dynamic copy of name
    emp->department = strdup(dep); // make a dynamic copy of department

    return emp;     //return pointer to the new created employee
}

/*
Employee* manually_create()
{
    Employee* emp=(Employee*) malloc(sizeof(Employee));
    char *inputline;

    inputline=readline("introduce a name: "); // read the name
    emp->name=strdup(inputline);   // create the name the name

    for( ; ; )
    {
      inputline=readline("introduce salary: ");  // reads the salary
      sscanf(inputline,"%d",&emp->salary); //converts the salary into an int
      if( emp->salary < 0 )
	printf("Wrong salary added. Try again\n");
      else
	break;
    }

    inputline=readline("introduce department: ");    // reads the salary
    emp->department=strdup(inputline); // creates employee's department

    free(inputline); // free readline memory
    return emp;
}
*/
void f_create(FILE* f, Employee* emp)
{
    char m[20];
    fgets(m, 20, f);  // get the line as char maximum 20 chars
    emp->name = strdup(m); // dynamic copy into name

    fgets(m, 20, f);   // get the line as char
    sscanf(m,"%d",&emp->salary); //converts the salary into an int


    fgets(m, 20, f);  // get the line as char maximum 20 chars
    emp->department = strdup(m); // dynamic copy into department

}

