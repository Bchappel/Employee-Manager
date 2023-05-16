#include "../include/headerA3.h"

//Function 6: Counts the total number of employees
int countEmployees (a3Emp * headLL){
    
    //counts the number of employees
	int count = 0;
    a3Emp *tempNode = headLL;
    while(tempNode != NULL) { //runs while the linked list is not at the end (NULL)
        tempNode = tempNode->nextEmployee; //traverses through the linked list
        count++; //increments count
    }
	return count; //returns the number of employees
} 