//
//  main.c
//  qformula
//
//  Created by Haaris Mirza on 1/17/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

#include <stdio.h>
#include <math.h>

//This program asks the user to input coefficients of the quadratic formula and then solves the quadratic formula based on the user input

int main() {
  
  double a = 0; //Initializes all the variables used throughout the program
  double b = 0;
  double c = 0;
  double solution1 = 0;
  double solution2 = 0;
  
  printf("Given a quadratic equation of the form a*x^2 + b * x + c\n"); //Prints the following statement showing what the quadratic formula looks like
  
  printf("Please enter a: "); //Asks the user to input variable a and reads in the value
  scanf("%lf", &a);
  
  printf("Please enter b: "); //Asks the user to input variable b and reads in the value
  scanf("%lf", &b);
  
  printf("Please enter c: "); //Asks the user to input variable c and reads in the value
  scanf("%lf", &c);
  
  solution1 = (((-b + (sqrt((b*b) -(4 * a *c))))) / (2 * a)); //This formula calculates the quadratic formula and solves for X(solution1) when -b is added
  
  solution2 = (((-b - (sqrt((b*b) -(4 * a *c))))) / (2 * a)); //This formula calculates the quadratic formula and solves for X(solution2) when -b is subtracted
  
  
  if (solution1 == solution2) { //If both solutions are equal in value, one real solution is printed
    printf("There is one real solution: %.2lf\n", solution2);
  }
  
  if isnan(solution1) { //If solution 1 is not a number, there are no real solutions are printed
    printf("There are no real solutions\n");
  }
  
  
  else if ((solution1 != solution2)) { //If solution1 and solution2 are not equal, it will print both solutions and state that there are 2 real solutions
    printf("There are 2 real solutions\n");
    printf("Solution 1: %.2lf\n", solution1);
    printf("Solution 2: %.2lf\n", solution2);
  }
      return 0;
}
