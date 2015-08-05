//
//  main.c
//  tail
//
//  Created by Haaris Mirza on 3/7/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

//
//  main.c
//  tail
//
//  Created by Haaris Mirza on 3/7/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//This program prints the last N lines of a given text file


/*The below functions gets the number of lines in the file*/


int get_number_of_lines(FILE* input_file, char *argv[]){
  
  input_file = fopen(argv[1], "r"); //Opens file for reading
  
  char all_characters; //Initializes all characters variable
  
  int lines = 0; // Initializes lines variable type int - serves as a counter
  
  while (1) {
    
    all_characters = fgetc(input_file); //gets the characters from the file
    
    if (feof(input_file)){
      
      break;}
    
    if (all_characters == '\n'){ //If characters are equal to new line
      
      ++lines; // Increase the lines variable by 1
      
    }
    
  }
  
  fclose(input_file); //closes the input file
  
  return lines; //returns lines
  
}

/* The below function prints the lines in a given file*/

void printlines(FILE* input_file, char* argv[], int lines, int numlines){
  
  input_file = fopen(argv[1], "r"); // Opens file for reading
  
  int counter = 0; // Serves as a counter
  
  int skip = lines - numlines;
  
  char all_characters; // initializes variable for all characters type char
  
  while (1){
    
    all_characters = fgetc(input_file); //Gets the characters from the input file
    
    if (counter >= skip){ //If the counter is greater than or equal to skip (lines - numlines)
      
      if (feof(input_file)){ // If
        
        break;
        
      }
      
      printf("%c", all_characters); //Prints the characters
      
    }
    
    if (all_characters == '\n'){ //If the character is equal to new line
      
      ++counter; //Increases the counter by 1
      
    }
    
  }
  
  fclose(input_file); // Closes file
  
  return;
  
}

int main(int argc, char* argv[]){
  
  FILE* input_file = NULL; //File pointer
  
  int lines = 0; // Initializes lines variable type int to 0
  
  int numlines = atoi(argv[2]); //Converts command line arguement to type integer
  
  lines = get_number_of_lines (input_file, argv); //Calls the get_number_of_lines function to get the number of lines in a file
  
  printlines(input_file, argv, lines, numlines); // Calls the printlines function to print the N number of lines
  
  return 0;
}