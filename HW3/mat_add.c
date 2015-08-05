//
//  main.c
//  hw3number3
//
//  Created by Haaris Mirza on 2/5/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

//This program asks the user for 2 matrices A, and B, and displays their sum, C.

#include <stdio.h>

//The below function reads in the values of 2 matrices and calculates its sum
//It has two parameters which are numRows and numColumns which the user inputs


void sumAB(int numRows, int numColumns) {
    
    int i = 0; //Initialized variable to use in loops down below
    int j = 0; //Initialized variable to use in loops down below
    int matrixA[100][100]; //Initializes an array to get the first Matrix
    int matrixB[100][100]; //initializes an array to get the second Matrix
    int sumAB[100][100]; //Initializes an array to get the sum of the first and second matrix
    
    printf("Enter Matrix A\n"); //Prompts user to enter MatrixA
    
    for (i = 0; i < numRows; i++) //This nested for loop reads in what the user entered into an array for matrixA
      for(j = 0; j < numColumns; j++) {
        scanf("%d", &matrixA[i][j]);
      }
    
    printf("Enter Matrix B\n"); //Prompts user to enter MatrixB
    
    for ( i = 0; i < numRows; i++) //This nested for loop reads in what the user entered into an array for matrixB
      for ( j = 0; j < numColumns; j++) {
        scanf("%d", &matrixB[i][j]);
      }
    
    for (i = 0; i < numRows; i++) //This nested for loop adds both MatrixA and MatrixB calculates its sum
      for (j = 0; j < numColumns; j++) {
        sumAB[i][j] = matrixA[i][j] + matrixB[i][j];
      }
    
    printf("A + B =\n"); //Prints this before sumAB is displayed
    
    for (i = 0; i < numRows; i++) { //This nested for loop displays the sum of MatrixA and MatrixB
      for (j = 0; j < numColumns; j++)
        printf("%d ", sumAB[i][j]);
      printf("\n");
    }
    return;
  }
  
  
  
  int main() {
    int numRows = 0; //Initializes variable
    int numColumns = 0; //Initializes variable
    
    printf("Please enter the number of rows: ");
    scanf("%d", &numRows); //Asks the user to enter the number of rows and stores the value in variable numRows
    
    printf("Please enter the number of columns: ");
    scanf("%d", &numColumns); //Asks the user to enter the number of columns and stores the value in variable numColumns
    
    sumAB(numRows, numColumns); //Calls function to calculate the sum of Matrix A and Matrix B
    
    return 0;
  }
