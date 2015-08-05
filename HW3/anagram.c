//
//  main.c
//  hw34
//
//  Created by Haaris Mirza on 2/07/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

//This program asks the user for 2 words and tells the user if those 2 words are anagreams.
//A word is an anagram of anotherword if the letters in that word can be reaarranged to form the other word.


#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*This below function takes the first user entered
 word and converts it to lower case*/

void lower1(char word1[100]) {
  int k = 0;
  long wordLength = 0;
  
  wordLength = strlen(word1); //Store the string's length value to wordLength
  
  for (k = 0; k<wordLength; ++k){ 
    word1[k] = tolower(word1[k]); //Changes all letters in string to lower case
  }
  return;
}


/*This below function takes the second user entered
 word and converts it to lower case*/

void lower2(char word2[100]) {
  int l =0;
  long wordLength = 0;
  
  wordLength = strlen(word2); //Stores the string's length value to wordLength
  
  for (l = 0; l < wordLength; ++l) {
    word2[l] = tolower(word2[l]); //Changes all letters in to lower case
  }
  return;
}

/*The below function takes the first user entered
 word and converts it to lower case*/

int check_anagram(char word1[], char word2[]) {
  
  int array1[26] = {0}; //initializes array to use in the below while loops
  int array2[26] = {0};
  int c = 0;
  
  while (word1[c] != '\0') //Check string for any null characters. If there are none, string will proceed. 
  {
    array1[word1[c]-'a']++;
    c++; //Increases c value by 1 after each loop executes
  }
  
  c = 0;
  
  while (word2[c] != '\0')
  {
    array2[word2[c]-'a']++;
    c++; //Increases c value by 1 after each loop executes
  }
  
  for (c = 0; c < 26; c++)
  {
    if (array1[c] != array2[c]) //Checks if letters in first string matches letters in second string.
      return 0; //If the two strings do not match, return value is 0, false
  }
  
  return 1; //Function returns the value of 1 if letters from both strings match
}

/*The below function calls the above function and if it returns 1, then it will print that it is an anagram.
 If it doesn't return 1, then it will print that it is not an anagram. This function also makes sure that the
 cases  of the characters are restored to the original format that they were entered*/

void checkAndPrint (int a, char word1[100], char word2[100], char temp1[100], char temp2[100]) {
  int check;
  
  check = check_anagram(word1, word2); //Calls the check_anagram function
  
  if (check == 1) //Checks if return value was 1 to signify the two strings are anagrams
    printf("%s is an anagram of %s\n", temp1, temp2);
  else //Checks if return value was not 1 to signify two strings are not anagrams
    printf("%s is NOT an anagram of %s\n", temp1, temp2);
  return;
  
}



int main()
{
  char word1[100]; //Initializes 4 arrays and check variable
  char word2[50];
  char temp1[100];
  char temp2[100];
  int check;
  
  
  printf("Please enter the first word: "); //Asks user to input a word
  scanf("%s", word1); //Program scans user's first input
  
  printf("Please enter the second word: "); //Asks user to input a word
  scanf("%s", word2); //Program scans user's second input
  
  strcpy(temp1, word1); //Copy letters in word1 to the string, temp1, to make an 'original' copy of word1
  strcpy(temp2, word2); //Copy letters in word2 to the string, temp2, to make an 'original' copy of word2
  
  lower1 (word1); //Calls function to make letters in word1 lower case
  lower2 (word2); //Calls function to make letters in word2 lower case
  
  check = check_anagram(word1, word2); //Calls function and stores the return value into check to use in next function
  
  checkAndPrint (check, word1, word2, temp1, temp2); //Calls function and pritns whether the two words are anagrams or not
  
  return 0;
}
