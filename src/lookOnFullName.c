#include "../include/headerA3.h"

//Function 5: search based on full name
int lookOnFullName (struct employee * headLL, char whichName [100]){

    a3Emp* temp = headLL; //sets the head == to a temp variable
    int indexOfMatch = 0;
    char *names[2];
    char delimiter[2] = " "; //space delimiter
    char *token = strtok(whichName, delimiter); //initializes the token
    int index = 0;

    //Tokenizes the input string into an array with the delimiter set as a space
    while(token != NULL){
        names[index++] = token;
        token = strtok(NULL, delimiter);
    }

    //checks for the match while temp head is ! null
    while(temp != NULL){
        indexOfMatch++;
        if(strcmp(temp->fname, names[0]) == 0 && strcmp(temp->lname, names[1]) == 0){ //checks if the first and last names are matches, if this is the case strcmp == 0
            return indexOfMatch; //returns the index of the matched employee
        }
        temp = temp->nextEmployee; //advances the employee
    }
    
    return -1; //returns -1 if issue
} 