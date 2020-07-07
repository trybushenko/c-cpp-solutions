#include <stdio.h>
#define EOL '\n'

/*
pointer is a variable that contains an adress of another variable and can instantly get the access to the value of this variable using the adress
*/

/*
Here I am learning  what pointers are and how to work with them
*/
void  main (void) 
{
    // declaring and initializing variables
  char one = 1;
  char two = 2;
  char three = 3;
  char four = 4;
  char five = 5;  
  // declaring and initializing ponters to variables
  char* onePointer = NULL;
  char* twoPointer = NULL;
  char* threePointer = NULL;
  char* fourPointer = NULL;
  char* fivePointer = NULL;
  //assigning adresses of 1-5 variables to pointers declaread and initialized above
  onePointer = &one;
  twoPointer = &two;
  threePointer = &three;
  fourPointer = &four;
  fivePointer = &five;
  //declaring and initializing variables to store data of dereferenced pointers
  char oneResult = 0;
  char twoResult = 0;
  char threeResult = 0;
  char fourResult = 0;
  char fiveResult = 0;
    //dereferencing pointers and assigning their values to initialized variables above
  oneResult = *onePointer;
  twoResult = *twoPointer;
  threeResult = *threePointer;
  fourResult = *fourPointer;
  fiveResult = *fivePointer;
  //set new values to value of pointers variables
  *onePointer = 10;
  *twoPointer = 20;
  *threePointer = 30;
  *fourPointer = 40;
  *fivePointer = 50;
  //getting to know the result variables(according to logic they seem to be changed because of altering value of pointers)
  printf(" *onePointer = %i\r\n *twoPointer = %i\r\n *threePointer = %i\r\n *fourPointer = %i\r\n *fivePointer = %i\r\n", one, two, three, four, five);
  printf(" 0x%x%c 0x%x%c 0x%x%c", onePointer, EOL, twoPointer, EOL, threePointer, EOL);
}