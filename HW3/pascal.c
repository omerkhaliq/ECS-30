//
//  main.c
//  hw3number2
//
//  Created by Haaris Mirza on 2/4/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

//The purpose of this program is to print out Pascal's Triangle up to a user entered level

#include <stdio.h>

//The purpose of the below function is to calculate the formula used to produce Pascal's formula and display the results in the correct format

void calculatePascal (int numLevels) { //The number of levels is used as a parameter in this function
  int i = 0; //Initialized variables used for the loops and formulas below
  int j = 0;
  int num = 0;
 
  
  for ( i = 0; i < numLevels; i++) //This loop iterates through numLevels and assigns 1 to num through out the loop
  {
    num = 1;
    
    for (j = 0; j <= i; j++)
    {
      printf ("%d ", num); //Since pascal's triangle has 1's on the outside, the loop will always begin printing 1 then calculate the below formula
      num = (num * ( i - j )/( j + 1)); // Formula given to us on the assignment
    }
    printf("\n");
  }
  
}


int main()
{
  int numLevels = 0;
  
  printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
  scanf("%d", &numLevels); //Reads in a user-entered value called numLevels
  
  calculatePascal(numLevels); //Calls the function in order to Calculate and display Pascal's triangle
  
  
  
}