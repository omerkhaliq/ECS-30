//
//  main.c
//  change
//
//  Created by Haaris Mirza on 1/8/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

#include <stdio.h>

int main() {
  //Asks the user how much money they would like to withdraw from the bank
  //and outputs the types of bills they will recieve
  
  
  int moneyLeft = 0;
  printf("Please enter the amount of money you wish to withdraw: "); //Prompts user to enter amount to withdraw
  scanf("%d", &moneyLeft);
  
  int Hundreds = moneyLeft/100;
  printf("You received %d hundred(s)\n", Hundreds); //outputs 100's recieved
  
  moneyLeft = moneyLeft - Hundreds * 100;
  int Fifties = moneyLeft/50;
  printf("You received %d fifty(s)\n", Fifties); //outputs 50's recieved
  
  moneyLeft = moneyLeft - Fifties * 50;
  int Twenties = moneyLeft/20;
  printf("You received %d twenty(s)\n", Twenties); //outputs 20's recieved
  
  moneyLeft = moneyLeft - Twenties * 20;
  int Tens = moneyLeft/10;
  printf("You received %d ten(s)\n", Tens); //outputs 10's recieved
  
  moneyLeft = moneyLeft - Tens * 10;
  int Fives = moneyLeft/5;
  printf("You received %d five(s)\n", Fives); //outputs 5's recieved
  
  moneyLeft = moneyLeft - Fives * 5;
  int Ones = moneyLeft;
  printf("You received %d one(s)\n", Ones); //outputs 1's recieveds

    return 0;


}