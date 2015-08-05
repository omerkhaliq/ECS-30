//Masood Mawlwavizada
//Haaris Mirza


//The purpose of the program is to complete a binary number
//binary number is made up of 0's and 1's but the input strings you will receive can also contain 'x''s.
//An x represents a digit that can be either a 0 or a 1. Your program should display all the possible binary digits that can be formed.
//For example the string x1x0 could represent either 0100, 0110, 1100, or 1110.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void bin(char* string, int index, int len);

void bin(char* string, int index, int len){ // Bin function that takes in arguements char string, int index, int len
  
  
  
  if(string[index] == '1' || string[index] == '0'){ //If the string contains 1 or 0
    
    if((len - 1) < index){
    
      printf("%s\n", string); //print the orginal string
    
    }
    
    else{
    
      ++index; //incrament index
      
      bin(string, index, len); //Calls bin recursively
    }
  }
  
  else{
  
    if((len - 1) < index){
    
      printf("%s\n", string); //Prints original string
    
    }
    else{
      char str1[len]; //Initializes string array to size len
      strcpy(str1, string); //makes a copy of the string to str1
      string[index] = '0'; // = 0
      str1[index] = '1'; // = 1
      
      ++index; //Increment index
      bin(string, index, len); //Calls bin function
      bin(str1, index, len); //Calls bin function
    }
  }
  
}

int main(int argc, char* argv[]) { //Command line arguements
  
  int index = 0; //Sets the index to 0
  
  int len; //Initializes len variable to 0 type int
  
  len = strlen(argv[1]); //Gets the string length of 2nd command line arguement
  
  char string[len]; //initializes array to size of strlen
  
  strcpy(string, argv[1]); // makes a copy of 2nd command line to a new string
  
  bin(string, index, len); //Calls bin function
  
  return 0;
}
