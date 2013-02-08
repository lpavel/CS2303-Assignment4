/** employee.h
 * @author Laurentiu Pavel
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

/** Defines an employee struct
 * @param salary
 * @param name
 */

struct _Employee // Define some structures
{
  int salary; // Monthly salary in UK pounds sterling
  char* name; // Pointer to character string holding name of employee.
  char* department; //Pointer to the string with the name of the department
              // MUST be dynamically allocated from the heap.
};

typedef struct _Employee Employee; // For convenience

// function prototypes

/** prints on executabile an employee struct
 * @param employee A pointer to a struct employee
 */
void printEmployee(Employee *employee);

/** Creates an employee struct copy into a fiel
 * @param stream - the file in which to print
 * @param eployee - a pointer to a struct employee
 */
void outputEmployee(FILE *stream, Employee *employee);

/** creates a new employee structure and fills
 * @param s - the salary of the employee
 * @param n - pointer to the name of the employee
 * @param dep - pointer to the name of the department
 */


Employee* make_employee(int s, char* n, char* dep);


#endif
