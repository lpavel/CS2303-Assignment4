#include <stdio.h>
#include <stdlib.h>

#include "employee.h"

#define MAXARRAY 5

int main()
{
    int n;

    FILE* infile=fopen("indata.txt","r");

    if( infile==NULL )    // if stream is not created
    {
      // prints the error and return 1
        fprintf(stderr,"in stest.c - cannot create the file: \n" );
        return 1;
    }

    // offer MAXARRAY spaces for emp
    Employee *emp = (Employee*) malloc( ( MAXARRAY+1 )*sizeof(Employee));

    int i;
    for(i=0; !feof(infile) ; i++)
    {
        f_create(infile, (emp+i));  // read from file

        if(i==MAXARRAY+1)
        {
            fprintf(stderr,"in stest2- the file is too big \n");
            break;
        }
    }

   if(i<=MAXARRAY)
   {
       fprintf(stderr,"in stest2 - the file is too small \n");
   }

    fclose(infile);  // close the input file

    FILE* outfile=fopen("stest2.txt","w");
    if( outfile==NULL )    // if stream is not created
    {
      // prints the error and return 1
        fprintf(stderr,"in stest.c - cannot create the file:\n");
        return 1;
    }

    for( i=0; i<MAXARRAY; i++)
        outputEmployee( outfile, emp+i );  // prints in outfile

    return 0;
}
