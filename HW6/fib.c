//Haaris Mirza
//Masood Mawlwavizada

#include <stdio.h> //include libraries
#include <stdlib.h>
#include <string.h>

int Fib (int userInput) { //parameter for function
  
  int value[userInput]; //initial for use later in function
  int i; //initiailize for use in 'for loop'
  
  
  
  
  if (userInput == 0) { //part of fibonacci's number to equal 0
    return 0; //0 will be returned
  }
  
  if (userInput == 1) { //it is part of fibonacci's number to equal 1 when userInput = 1
    return 1;
  }
  
  
  if (userInput >1) { //If userInpt is greater than 1, it'll enter the if statement
    for(i=2; i<=userInput; ++i){
      value[1] = 1; //stores 1 into value[1]
      value [0] = 0; //stores 0 into value[0]
      value[i] = value [i-1] + value [i - 2]; //Fibonnaci's theorem
    }
    
    
    return Fib(userInput-1)+value[userInput - 2]; //Recursive function
    
  }
  
  return 0;
  
  
  
  
  
}

int main(int argc, char *argv[]) { //reads command line
  
  printf("The %dth fibanocci number is %d.", atoi(argv[1]), Fib(atoi(argv[1]))); //print statement that calls the fibonnaci function
  
  
  return 0;
  
}