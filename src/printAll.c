#include "../include/headerA3.h"

//Function 2: print data of all employees
void printAll (struct employee * headLL){

    int counter = 0;
    a3Emp *tempNode = headLL;

    //if the head is null return to main with error
    if(headLL == NULL){
        printf("\t[ERROR] There are no employees\n");
        return;
    }

    //Runs while the temp node is not null
    while(tempNode != NULL) {
        
        counter++; //increments the counter
        //prints all the info
        printf("\nEmployee Number: [%d]\n", counter);
        printf("\tEmployee ID: %d\n", tempNode->empId);
        printf("\tFirstName: %s\n", tempNode->fname);
        printf("\tLastName: %s\n", tempNode->lname);
        printf("\tDepenedants: [%d] ", tempNode->numDependents);
        
        //Prints the dependents
        for (int i = 0; i < tempNode->numDependents; i++) {
            printf("%s ", tempNode->dependents[i]); //prints the dependents
        }
        tempNode = tempNode->nextEmployee; //Advances to the next employee after printing the previous one
        printf("\n");
    }
} 