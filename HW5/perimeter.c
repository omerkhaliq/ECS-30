//
//  main.c
//  5.2M
//
//  Created by Haaris Mirza on 3/6/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

//#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void second_main(FILE* inFile, int* file_point, int num_pair, int num_point){
  
  int i; //Initialize interger i to use for 'for loop'
  int j; //Initialize interger j to use for 'for loop'
  int k; //Initialize interger k to use for 'for loop'
  
  double inside_first; //Initialize double to use it later in function to find the difference in x's
  double inside_second; //Initialize double to use it later in function to find the difference in y's
  double polygon_perimetermeter; //Initialize to find the perimter of the polygon later in the function
  
  
  for(i = 1; i <= num_point; ++i){ //Will grab intergers from binary file
    
    fread(&file_point[i], sizeof(int), 1, inFile); //Reads the file
    
  }
  
  
  typedef struct points_struct { //This will give each point a pair of an x and y coordinate
    
    int x; //X-Axis
    
    int y; //Y-Axis
    
  } point;
  
  point coordinate[num_pair];
  
  
  j = -1;
  
  for(i = 0; i< num_pair; ++i){ //The points from the file will then be stored into the structs
    
    coordinate[i].x = file_point[j = j + 2];
    
  }
  
  k = 0;
  
  for(i = 0; i < num_pair; ++i){
    
    coordinate[i].y = file_point[k = k + 2];
    
  }
  
  
  typedef struct length_struct{ //Helps later to find the length between the points entered
    
    double length;
    
  } measure;
  
  measure distance[num_pair];
  
  for(i = 0; i < num_pair - 1; ++i){
    
    inside_first = pow((coordinate[i].x - coordinate[i + 1].x), 2); //Squares each (X1 -X2)
    
    inside_second = pow((coordinate[i].y - coordinate[i + 1].y), 2); //Squares each (Y1 -Y2)
    
    distance[i].length = sqrt(inside_first + inside_second); //Distance formula
    
  }
  
  double inner_one, inner_two; //Will get distance from first point to last point
  
  inner_one = (coordinate[num_pair - 1].x - coordinate[0].x); //Gets difference
		
		inside_first = pow(inner_one, 2); //Squares the value
		
		inner_two = (coordinate[num_pair - 1].y - coordinate[0].y); //Gets difference
		
		inside_second = pow(inner_two, 2); //Squares the value
		
		distance[num_pair - 1].length = sqrt(inside_first + inside_second);  //Find the distance using the distance formula
  
  
  
  for(i = 0; i < num_pair; ++i){ //used to find perimeter by adding the different distances
    
    polygon_perimetermeter = polygon_perimetermeter + distance[i].length;
    
  }
  
  printf("The perimeter is %.2f\n", polygon_perimetermeter); //Prints the perimeter's distance
}


int main(int argc, char* argv[]){ //Gets how many points there are going to be from the first number on the command line
  
  FILE* inFile = NULL; //File pointer
  char file_name[100]; //Will be used to read the file name
  int num_point = 0;
  int num_pair = 0;
  long num_bytes = 0;
  
  
  strcpy(file_name, argv[1]); //argv[1] is inputted into file_name so it can be used to open the file in the next call
  
  inFile = fopen(file_name, "rb"); //Open the file
  
  num_bytes = fread(&num_pair, sizeof(int), 1, inFile); //Read file
  
  num_point = num_pair * 2;
  
  int file_point[num_point]; //create array to store points
  
  second_main(inFile, file_point, num_pair, num_point); //Call the 'second_main' function
  
  fclose(inFile); //Close the file
  
  return 0;
}