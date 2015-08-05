//
//  main.c
//  HW3Number1
//
//  Created by Haaris Mirza on 2/4/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

//This program asks the user for a noun and prints out its plural form
//This program adheres to the rules Matthew Butnewr specified

#include <stdio.h>
#include <string.h>

//The function below makes the necesarry 

void printPlural(char userWord[10]) {
  
  long wordLength = 0;
  
  wordLength = strlen(userWord); //Stores how many letters are in userWord into wordLength
  
  printf("The plural from of %s is", userWord); //Prints plural form of userWord

  if ((userWord[wordLength - 2]) == ('s') && (userWord[wordLength - 1]) == ('h')) { //Runs if the word ends with sh
    
    (userWord[wordLength]) = 'e'; //The last letter of the original word will now end with an 'e'
    
    (userWord[wordLength + 1]) = 's'; //Then a 's' is added to complete the plural form
    
    (userWord[wordLength+2]) = '\0'; //Makes the charachter after the 's' a null character
    
    printf(" %s.\n", userWord); //Prints the words plural form after converting it
    
  }

  
  else if ((userWord[wordLength - 2]) == ('c') && (userWord[wordLength - 1]) == ('h')) { //Runs if the word ends with 'ch'
    
    (userWord[wordLength]) = 'e'; //Changes last letter to 'e'
    
    (userWord[wordLength + 1]) = 's'; //Adds 's' following the 'e' to complete plural form
    
    (userWord[wordLength+2]) = '\0'; //Makes the character after the 's' a null character
    
    printf(" %s.\n", userWord); //Prints the word's plural form after converting it
    
  }
  
 
  
  else if ((userWord[wordLength - 1]) == ('x') || (userWord[wordLength - 1]) == ('s') || (userWord[wordLength - 1]) == ('z'))  { //Runs if word ends in s, x, or z
    
    
    userWord[wordLength] = 'e'; //Changes last letter to 'e'
    
    (userWord[wordLength+1]) = 's'; //Adds 's' following 'e'
    
    (userWord[wordLength+2]) = '\0'; //Adds null character following 's'
    
    printf(" %s.\n", userWord); //Prints the words plural form after converting it
    
  }
  
  ///* Ending in a,e,i,o,u and y -> + s*/
  
  else if (((userWord[wordLength - 2]) == ('a') || (userWord[wordLength - 2]) == ('e') || (userWord[wordLength - 2]) == ('i') ||
            
            (userWord[wordLength - 2]) == ('o') || (userWord[wordLength - 2]) == ('u')) && userWord[wordLength - 1] == ('y')) { //Runs if words ends with an a,e,i,o,u with a y
    
    
    
    userWord[wordLength] = 's'; //Adds the letter 's' to the end of te word
    
    userWord[wordLength+1] = '\0'; //Adds a null character following the 's'
    
    printf(" %s.\n", userWord); //Prints the plural version of the original word
    
  }
  
 
  
  else if (((userWord[wordLength - 2]) != ('a') || (userWord[wordLength - 2]) != ('e') || (userWord[wordLength - 2]) != ('i') ||
            
            (userWord[wordLength - 2]) != ('o') || (userWord[wordLength - 2]) != ('u')) && userWord[wordLength - 1] == ('y')) {  //Runs if words ends with any letter except a,e,i,o,u with a y
    
    
    
    userWord[wordLength - 1] = 'i'; //Changes the second to last letter to an 'i'
    
    userWord[wordLength] = 'e'; //Changes last letter to 'e'
    
    userWord[wordLength + 1] = 's'; //Adds the letter 's' to complete the plural form of the word
    
    userWord[wordLength + 2] = '\0'; //Adds a null character following the 's'
    
    printf(" %s.\n", userWord); //Prints the plurfal version of the original word
    
  }
  

  
  else if ((userWord[wordLength - 1]) == ('f')) { //Runs if word ends with a 'f'
    
    userWord[wordLength - 1] = 'v'; //Changes second to last letter to 'v'
    
    userWord[wordLength] = 'e'; //Changes last letter to 'e'
    
    userWord[wordLength + 1] = 's'; //Adds an 's' to complete the plural form of the word
    
    userWord[wordLength + 2] = '\0'; //Adds a null character following the 's'
    
    printf(" %s.\n", userWord); //Prints the plural version of the original word
    
  }
  
  ///* Ending in fe ->  becomes ves */
  
  else if ((userWord[wordLength - 1]) == ('e') && userWord[wordLength - 2] == 'f') { //Runs if word ends with 'fe'
    
    userWord[wordLength - 2] = 'v'; //Changes third to last letter to 'v'
    
    userWord[wordLength - 1] = 'e'; //Changes second to last letter to 'e'
    
    userWord[wordLength] = 's'; //Changes last letter to 's'
    
    userWord[wordLength + 1] = '\0'; //Adds null character after 's'
    
    printf(" %s.\n", userWord); //Prints the plural version of the original word
    
  }
  

  
  else { //For all other words, add 's' at the end of the original word
    
    userWord[wordLength] = 's'; //Replaces last letter with 's'
    
    userWord[wordLength + 1] = '\0'; //Adds null character after 's'
    
    printf(" %s.\n", userWord); //Prints plural version of the original word
    
  }


  return;
}

int main() {
  
  char userWord[10];
  
  printf("Please enter a word: "); //Asks user to enter a word
  
  scanf("%s", userWord); //Scans user's input
  
  printPlural(userWord); //Uses user's input in the function printPlural
  
  return 0;
}





