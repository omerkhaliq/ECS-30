//
//  main.c
//  HW5.1
//
//  Created by Haaris Mirza on 3/1/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

//This program counts all the words in a given text file

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* The below functions goes through the text
 file and counts up all the words.       */

int get_Word_Count (FILE* inFile) {
  
  int count = 0; //Serves as a counter
  
  int previous_Character = 0; //Sets previous character variable type int to 0
  
  char current_char; //initializes
  
  current_char = fgetc(inFile); //sets current_char to characters in the infile
  
  while ((current_char != EOF)) {
    
    if (isspace(current_char)) { //If the current character is a space
      
      if (previous_Character == 0) { //If the previous character == 0
        
        count++; //Add 1 to counter
        
        previous_Character = 1; //sets previous character to 1
        
      }
    }
    else {
      
      previous_Character = 0; //if none of the if statements are true, setes the previous character to 0
    }
    
    current_char = (char)fgetc(inFile); //gets the characters from inFIle
  }
  
  return count; //Returns all the added up words as an int
  
}


int main(int argc, char** argv) { //Command line parameters
  
  FILE* inFile = NULL; // File pointer
  
  int count = 0; //initializes count to 0
  
  inFile = fopen(argv[1], "r"); //opens the file for reading
  
  count = get_Word_Count(inFile); //Calls function and returns the word count
  
  printf("There are %d word(s).", count); //prints the number of words in the text file
  
  fclose(inFile); //closes the opened file
  
  return 0;
  
}
















