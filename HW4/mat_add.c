//This program asks the user for 2 matrices A, and B, and displays their sum, C.

#include <stdio.h>

#include <stdlib.h>


//The below function reads in the values of 2 matrices and calculates its sum

//It has two parameters which are numRows and numColumns which the user inputs


void sumAB (int numRows, int numColumns) {
  int i;
  int j;
  
  printf("Enter Matrix A\n");
  
  int* matA = (int*)malloc(sizeof(int)*numRows*numColumns);
  
  for (i = 0; i < numRows; i++) //This nested for loop reads in what the user entered into an array for matrixA
    
    for(j = 0; j < numColumns; j++) {
      
      scanf("%d", matA + i * numColumns + j);
      
    }
  
  printf("Enter Matrix B\n");
  
  
  int* matB = (int*)malloc(sizeof(int)*numColumns*numRows);
  
  for ( i = 0; i < numRows; i++) {
    
    for ( j = 0; j < numColumns; j++) {
      
      scanf("%d", matB + i * numColumns + j);
      
    }
  }
  
  printf("A + B =\n");
  
  
  for (i = 0; i < numRows; i++) {
    
    for(j = 0; j < numColumns; j++) {
      
      
      if(j == (numColumns -1)) {
        printf("%d\n", (*(matA + i * numColumns + j) + *(matB + i * numColumns + j)));
      }
      else {
        printf("%d ", (*(matA + i * numColumns + j) + *(matB + i * numColumns + j)));
      }
      
    }
    
  }
}






int main() {
  int numRows = 0; //Initializes variable
  int numColumns = 0;
  
  //Initializes variable
  
  printf("Please enter the number of rows: ");
  
  scanf("%d", &numRows); //Asks the user to enter the number of rows and stores the value in variable numRows
  
  printf("Please enter the number of columns: ");
  
  scanf("%d", &numColumns); //Asks the user to enter the number of columns and stores the value in variable numColumns
  
  sumAB(numRows, numColumns);
  
  return 0;
  
}