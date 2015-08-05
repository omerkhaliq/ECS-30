//
//  main.c
//  fracAdd.c
//
//  Created by Haaris Mirza on 1/11/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

#include <stdio.h>

//This program prompts the user to enter two fractions
//Both fractions are added and the result is displayed

int main() {
  int numerator1 = 0; //Initializes all variables used in this program to 0
  int denominator1 = 0;
  int numerator2 = 0;
  int denominator2 = 0;
  int resultNum1 = 0;
  int resultNum2 = 0;
  int numFinal = 0;
  int resultDenFinal = 0;
  
  printf("Please enter the first fraction to be added: "); //Asks the user to input the first fraction in the required format
  scanf("%d / %d", &numerator1, &denominator1);
  
  printf("Please enter the second fraction to be added: "); //Asks the user to nput the second fraction in the required format
  scanf("%d / %d", &numerator2, &denominator2);
  
  printf("%d/%d + %d/%d = ", numerator1, denominator1, numerator2, denominator2); //Displays a formula that adds both fractions
  
  resultNum1 = numerator1 * denominator2; //Calculates the first number that will be added to get the final numerator
  resultNum2 = numerator2 * denominator1; //Calculates the second number that will be added to get the final numerator
  
  numFinal = resultNum1 + resultNum2; //This formula adds both numerator calculations to get the final numerator of both added fractions
  
  resultDenFinal = denominator1 * denominator2; //This formula calculates the final Denominator of both added fractions
  
  printf("%d/%d\n", numFinal, resultDenFinal); //This formula displays the result of both added fractions
  
  return 0;
}
