//
//  main.c
//  crash.c
//
//  Created by Haaris Mirza on 1/11/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

#include <stdio.h>
//This program prompts the user to enter starting positions and speeds for 2 trains that will travel towards each other
//The location of collision and amount of time until collision is calculated
int main() {
  //variables used throughout the program that require decimals (double) are all initialized to 0
  double posTrain1 = 0;
  double speedTrain1 = 0;
  double posTrain2 = 0;
  double speedTrain2 = 0;
  double hours = 0;
  double milesDownTrack = 0;
  
  
  printf("Please enter the starting position of train 1: "); //Reads in the position of Train 1 from the user
  scanf("%lf", &posTrain1);
  
  printf("Please enter the speed of train 1: "); //Reads in the speed of Train 1 from the user
  scanf("%lf", &speedTrain1);
  
  printf("Please enter the starting position of train 2: "); //Reads in the position of Train 2 from the user
  scanf("%lf", &posTrain2);
  
  printf("Please enter the speed of train 2: "); //Reads in the speed of Train 2 from the user
  scanf("%lf", &speedTrain2);
  
  hours = (posTrain2 - posTrain1)/(speedTrain1 + speedTrain2); //Calculates the time in which the trains will collide in hours
  
  milesDownTrack = (posTrain2 - ((speedTrain2 * hours))); //Calculates the location of the collision in miles
  
  printf("The two trains will collide in %.2lf hours %.2lf miles down the track.\n", hours, milesDownTrack); //Prints the location and time of collision
  
    return 0;
}
