//
//  main.c
//  leapyear2
//
//  Created by Haaris Mirza on 1/17/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

#include <stdio.h>


//This program asks the user to enter a year and reads in the value. The program outputs whether or not the year inputted is a leap year or not.
int main() {
  
  int inputYear = 0; //Initialized the user inputted integer
  
  printf("Please enter a year: "); //Asks the user to input a number and reads in the value
  scanf("%d", &inputYear);
  
  
  if (inputYear % 4 == 0 && inputYear % 100 != 0) { //Prints that the integer is a leap year because it is divisble by 4 and not divisble by 100
    printf("%d is a leap year.\n", inputYear);
  }
  
  else if (inputYear % 100 == 0 &&  inputYear % 400 == 0) { //Prints that the integer is a leap year if it is divisble by 100 and 400
    printf("%d is a leap year.\n", inputYear);
  }
  
  else {
    printf("%d is not leap year.\n", inputYear); //Prints that the integer is not a leap year if the previous if statements are not satisfied
  }
    return 0;
  }
