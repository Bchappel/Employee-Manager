#include "../include/headerA3.h"

//Function 7: sort based on ID
void sortEmployeesId (struct employee * headLL){

    //if the head is null return to main with error
    if(headLL == NULL){
        printf("\t[ERROR] There are no employees\n");
        return;
    }

    a3Emp* temp = headLL;
    int numEmp = 0;
    int x = 0;
    int counter = 0;
    
    //creates a new array of the size of the employees (for each employee number)
    numEmp = countEmployees(headLL);
    int * array = malloc(sizeof(int)*numEmp);

    //Loads the employee ids into the array
    for(int k = 0; k < numEmp; k++){
        array[k] = temp->empId;
        temp = temp->nextEmployee; 
    }

    int holder;
    //sorting algorithim (bubble sort) to sort the IDs of the employees
    for (int i = 0; i < numEmp - 1; i++) {
        for (int j = 0; j < numEmp - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                holder = array[j];
                array[j] = array[j + 1];
                array[j + 1] = holder;
            }
        }
    }

    temp = headLL; //resets the position of temp

    while(temp != NULL && x < numEmp){

        //checks for a match against the ordered array and prints it
        if(temp->empId == array[x]){
            counter++;
            //prints the info of the employee
            printf("\nEmployee number: [%d]\n", counter);
            printf ("\tEmployee ID: %d\n", array[x]);
            printf ("\tFirstName: %s\n", temp->fname);
            printf ("\tLastName: %s\n", temp->lname);
            printf ("\tDepenedants: [%d] ", temp->numDependents);
            
            for (int i = 0; i < temp->numDependents; i++) {
                printf ("%s ", temp->dependents[i]);
            }
            temp = headLL; //if match is found, reset the position of the head back to the start
            x++; //increments x which moves to the next number
        }
        else{
            temp = temp->nextEmployee; //if no match detected move to next employee
        }
    }

    printf("\n");
    free(array); //frees the array
}