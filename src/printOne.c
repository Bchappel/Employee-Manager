#include "../include/headerA3.h"

//Function3: prints one employee
void printOne (struct employee * headLL, int whichOne){

    a3Emp* temp = headLL;

    //if the head is null return to main with error
    if(headLL == NULL){
        printf("\t[ERROR] There are no employees\n");
        return;
    }

    //runs trough the list of employees until the selceted index
    for(int i = 0; i < whichOne-1; i++){
        temp = temp->nextEmployee;
    }

    //prints each values
    printf("Employee number [%d]\n", whichOne);
    printf ("\tEmployee ID: %d\n", temp->empId);
    printf ("\tFirstName: %s\n", temp->fname);
    printf ("\tLastName: %s\n", temp->lname);
    printf ("\tDepenedant(s) [%d] ", temp->numDependents);
        
    //Prints each of the dependents
    for (int k = 0; k < temp->numDependents; k++) {
        printf ("%s ", temp->dependents[k]);
    }

    printf("\n");
}