#include "../include/headerA3.h"

//Function 1: adds a new employee
void recruitEmployee (struct employee ** headLL){

    /*Variables*/
    char firstName[MAX_LENGTH]; //first names
    char lastName[MAX_LENGTH]; //last names
    int rnd = 0; //Random Number 
    srand(time(NULL));
    rnd = (rand() % 999) + 1; //Select a random number between 1 and 999
    int employeeId = 0;
    a3Emp* tempNode = *headLL;

    //User Input code
    printf("\t[INPUT] Enter the first name of employee: ");
    fgets(firstName, MAX_LENGTH, stdin); //First Name
    firstName[strlen(firstName) - 1] = '\0'; //Removes the '\n' and replaces it with '\0' 
    printf("\t[INPUT] Enter the last name of employee: ");
    fgets(lastName, MAX_LENGTH, stdin);
    lastName[strlen(lastName) - 1] = '\0'; //Removes the '\n' and replaces it with '\0' 

    //creates temp heads for input
    a3Emp* newNode = *headLL;
    a3Emp* last = malloc(sizeof(a3Emp));
    last->nextEmployee = NULL;

    //Copies over the names for fname and lname
    strcpy(last->lname, lastName);
    strcpy(last->fname, firstName);
    
    int lnameLen = strlen(lastName); //last name length

    //runs through the linked
    for(int k = 0; k < strlen(firstName); k++){
        employeeId = employeeId + (int)firstName[k]; //Casts int to get the ascii value of each character of the first name
    }
    
    employeeId = employeeId + lnameLen; //adds the length of the last name

    //checks if the employee number is a duplicate then adds a random value
    while(tempNode != NULL){

        if(tempNode->empId == employeeId){
            employeeId = employeeId + rnd;
            tempNode = *headLL; //resets the position to the head to check again
        }
        tempNode = tempNode->nextEmployee; //moves to the next employee
    }

    //dependencies
    int initialRows = 5; 
    char ** depNames = malloc(sizeof(char*) * initialRows); // allocate memory for rows (horizontal)
    // initialize each column of the 2D array
    for (int i = 0; i < initialRows; i++) {
        depNames[i] = malloc(sizeof(char)* 30); //allocates for string space -> (vertical)
    }

    int rowNumber = 0;
    char input = 'y'; //user input

    while (input == 'y'){

        //if the number of dependent entered exceeds the inital values malloc'd then it will realloc more values as needed in increments of 5
        if (rowNumber >= initialRows) {
            initialRows += 5;
            depNames = realloc(depNames, sizeof(char*) * initialRows); // reallocates memory for the number of name that can be entererd.
            for (int i = rowNumber; i < initialRows; i++) {
                depNames[i] = malloc(sizeof(char) * 30); //allocates space for the names
            }
        }

        //fgets the names of the dependency and stores it in the dynamic array
        printf("\t[INPUT] Enter the name of the depenancy: ");
        fgets(depNames[rowNumber], 30, stdin);
        rowNumber++; //increments the number of rows

        //asks the user if they want to continue
        printf("\t[INPUT] Do you want to continue [y or n]: ");
        scanf("%s", &input);
        getchar(); //grabs the \n from the buffer
    }

    //Removes the newline character from the end of the string(s) (entered dependants)
    for(int j = 0; j < rowNumber; j++){
        depNames[j][strlen(depNames[j])-1] = '\0';
    }

    //Populates the last entered employee
    last->empId = employeeId;
    last->dependents = malloc(sizeof(char*)*rowNumber);
    for(int i = 0; i < rowNumber; i++){
        last->numDependents = rowNumber;
        last->dependents[i] = malloc(sizeof(strlen(depNames[i])));
        strcpy(last->dependents[i], depNames[i]);
    }

    //if empty linked list
    if(*headLL == NULL){
        *headLL = last;
        newNode = last; 
    }
    else{
        while(newNode->nextEmployee != NULL){
            newNode = newNode->nextEmployee;
        }
        newNode->nextEmployee = last; //loads last into newNode
    }

    //frees the dynamic array used to load dependencies
    for (int i = 0; i < initialRows; i++) {
        free(depNames[i]);
    }
    free(depNames);
}    