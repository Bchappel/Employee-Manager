#include "../include/headerA3.h"

//Function 4: search based on ID
int lookOnId (struct employee * headLL, int whichEmpId){

	int index = 0;
	a3Emp* temp = headLL;
	//runs while the linked list is not null
	while(temp != NULL){
		index++;
		//if the employee id matchs which employee id then it returns the index of the match
		if(temp->empId == whichEmpId){
			return index;
		}

		temp = temp->nextEmployee; //advances to next employee
	}

	return -1;
}
