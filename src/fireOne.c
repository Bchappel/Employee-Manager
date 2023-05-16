#include "../include/headerA3.h"

//Funcion 8: remove one employee
void fireOne (a3Emp ** headLL, int whichOne){

    int i = 0;
    a3Emp *currentEmp = *headLL; //Sets the head = to current employee
    a3Emp *previousEmp = NULL; //previous = to null

    //Move to the index of the employee that is to be fired
    while (currentEmp != NULL && i < whichOne-1){
        previousEmp = currentEmp;
        currentEmp = currentEmp->nextEmployee;
        i++;
    }   

    //checks if the linked list is null. if it is then return.
    if (currentEmp == NULL) {
        return;
    }

    //Updates the head if the head is the employee that is to be removed
    if (previousEmp == NULL) {
        *headLL = currentEmp->nextEmployee;
    } else {
        previousEmp->nextEmployee = currentEmp->nextEmployee;
    }

    // Free the memory allocated for the node to be removed
    for (int i = 0; i < currentEmp->numDependents; i++) {
        free(currentEmp->dependents[i]); //frees the dynamically allocated part of the dependents 2d array
    }
    free(currentEmp->dependents); //frees dependents
    free(currentEmp); // free the current node (employee that is being fired)
}