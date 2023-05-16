#include "../include/headerA3.h"


//Remove all employees
void fireAll (a3Emp ** headLL){

   /*variables*/
   a3Emp* currentEmp = *headLL;
   a3Emp* nextEmp;

   //Runs through the linked list
   while (currentEmp != NULL) {
      nextEmp = currentEmp->nextEmployee;
      for (int i = 0; i < currentEmp->numDependents; i++) {
         free(currentEmp->dependents[i]); // free each dependent's name
      }
      free(currentEmp->dependents); //free the dependent itself
      free(currentEmp); //free the current node
      currentEmp = nextEmp; //moves onto the next node
   }

   *headLL = NULL; // set the head pointer to NULL
}


    