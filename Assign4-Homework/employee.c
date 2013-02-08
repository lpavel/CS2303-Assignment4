/** employee.h
 * @author Laurentiu Pavel
 */

#include<stdio.h>
#include <string.h>
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


Employee* manually_create()
{
    Employee* emp=(Employee*) malloc(sizeof(Employee));
    char *inputline;

    printf("\nintroduce name: ");
    inputline=readline(inputline,100);
    emp->name=inputline;   //reads the name
    printf("%s\n",emp->name);

    printf("\nintroduce salary: ");
    inputline=readline(inputline);
    sscanf(inputline,"%d",emp->salary); //converts the salary into an int

    printf("\nintroduce department: ");
    inputline=readline(inputline);    // reads the salary
    emp->department=inputline;

    return emp;
}
