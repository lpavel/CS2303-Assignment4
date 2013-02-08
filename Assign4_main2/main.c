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
    Employee *emp = (Employee*) malloc(MAXARRAY*sizeof(Employee));

    int i;
    for(i=0; i<MAXARRAY ; i++)
    {
        f_create(infile, (emp+i));  // read from file
        if( feof(infile) && i<MAXARRAY )   // if we reach the end too soon
        {
            fprintf(stderr," in stest2 the file is too small \n");
            break;
        }
    }

    char* m; fgets(m,20,infile);
    if( m == eof(infile) )      // check how the input file is
        fprintf(stderr,"in stest2- the file is too big \n");
    else
        fprintf(stderr,"in stest2- the file is too big \n");

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
