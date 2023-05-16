//./bin/proFile
#include "../include/headerA3.h"

int main(){

	/*Variables*/
	int whichTask = 0;
	int whichOne = 0;
	int numEmp = 0;
	int empNumInput = 0;
	int flag = 0;
	int searchNamesReturn = 0;
	char name[100];
	char fire;
	int indexOfFire = 0;
	
    printf("[PROGRAM START] Function: main()\n");
	a3Emp * headLL = NULL;
    loadEmpData(&headLL, "proFile.txt"); //Calls prequisite function (givenA3.c)

    do{ 
		//Menu Options
		printf("\n[MAIN]: Request for user input.\n");
		printf("\t[Function 1]: Add a new employee.\n");
		printf("\t[Function 2]: Print data of all employees.\n");
		printf("\t[Function 3]: Print data of the nth employee.\n");
		printf("\t[Function 4]: Search for employee based on empId.\n");
		printf("\t[Function 5]: Search for employee based on full name.\n");
		printf("\t[Function 6]: Count the total number of employees.\n");
		printf("\t[Function 7]: Sort the employees based on their empId.\n");
		printf("\t[Function 8]: Remove the nth employee in the current LL.\n");
		printf("\t[Function 9]: Remove all employees in the current LL.\n");
		printf("\t[Function 10]:Exits program.\n");
		printf("[MAIN]: Enter a value [1 -> 10]: ");
		scanf("%d", &whichTask);
		getchar();

		//Switch Statement that selects menu options
		switch (whichTask){
            case 1:
				printf("\t[CALL] Called Function 1 \n");
				recruitEmployee(&headLL); //Function 1 call
				break;
			case 2:
				printf("\t[CALL] Called Function 2 \n");
				printAll(headLL); //function 2 call
				break;
			case 3:
				printf("\t[CALL] Called Function 3 \n");
				printf("[INPUT] Enter a position of an employee you want to search ");
				scanf("%d", &whichOne); //function 3 call

				numEmp = countEmployees (headLL); //calls function to find out the number of employees for input validation

				//validates input
				if(whichOne > numEmp){
					printf("[ERROR] Number entered too large\n"); //error message if the number entered exceeds the number of employees in the system
					whichOne = 0;
				}else{
					printOne (headLL, whichOne); //Prints the employee at the found index
				}	
				break;
			case 4:
				printf("\t[CALL] Called Function 4 \n");
				printf("\t[INPUT] Enter a employee number: ");
				scanf("%d", &empNumInput); //user input for function 4
				flag = lookOnId (headLL, empNumInput); //Function call

				if(flag == -1){
					printf("\t[ERROR] Employee Not Found in System\n"); //if error occurs
				}
				else{
					printOne(headLL, flag); //prints the employee at the index that it is found at
				}
				break;
			case 5:
				printf("\t[CALL] Called Function 5 \n");
				printf("\t[INPUT] Enter the full name of the employee: ");
				fgets(name, 100, stdin);
				name[strlen(name) - 1] = '\0'; //removes the \n
				searchNamesReturn = lookOnFullName (headLL, name); //function 5 call

				if(searchNamesReturn > -1){
					printOne(headLL, searchNamesReturn); //prints the correct name based on the query
				}
				else{
					printf("\t[ERROR] Employee Not Found in System\n"); //if there is a problem or employee doesnt exist
				}
				break;
			case 6:
				printf("\t[CALL] Called Function 6 \n");
				numEmp = countEmployees (headLL); //function 6 call
				printf("\t[OUTPUT] Number of employees is: %d\n", numEmp);
				break;
			case 7:
				printf("\t[CALL] Called Function 7 \n");
				sortEmployeesId(headLL); //function 7 call
				break;
			case 8:
				printf("\t[CALL] Called Function 8 \n");
				numEmp = countEmployees (headLL); //function 8 call
				printf("\t[INPUT] Enter a employee number from [1->%d] ", numEmp);
				scanf("%d", &indexOfFire);
				//Inputverification
				if(indexOfFire <= numEmp){
					fireOne (&headLL, indexOfFire);
				}
				else{
					printf("\t[ERROR] Enter a valid employee number to fire");
				}
				break;
			case 9:
				printf("\t[CALL] Called Function 9 \n");
				printf("\t[INPUT] Are you Sure you want to fire everyone [y or n]? ");
				scanf("%c", &fire); //gets input y or n for fireAll

				if(fire == 'y'){
					printf("\t[OUTPUT] All employees are fired, Linked list is now empty");
					fireAll(&headLL); //calls the function to fire everyone
				}
			
				break;
			case 10:
				printf("\t[PROGRAM TERMINATED]\n");
				//frees head and returns 0 (similar to function 9)
			    a3Emp* temp = NULL;
    			while (headLL != NULL){

        			for (int i = 0; i < headLL->numDependents; i++) {
            			free(headLL->dependents[i]);
        			}
        			free(headLL->dependents);
        			temp = headLL;
        			headLL = headLL->nextEmployee;
        			free(temp);
    			}
				
				return 0;
		}
			   
	}while(whichTask >= 1 && whichTask <= 10); //for loop that runs when valid menu option are entered

	return  0;
}