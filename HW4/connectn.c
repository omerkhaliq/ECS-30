#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "connectn.h"



int main(int argc, char* argv[]){
  
  
  
  int numRows = 0;
  
  int numColumns = 0;
  
  int amountToWin = 0;
  
  char** game_Board = NULL;
  
  int continue_To_Play = 0;
  
  
  
  
  
  continue_To_Play = check_arguments(argc); //Call function
  
  
  
  accept_arguments(argc, argv, &numRows, &numColumns, &amountToWin); //Call function
  
  
  
  game_Board = make_board(numRows, numColumns); //Call function
  
  
  
  print_board(numRows, numColumns, game_Board); //Call function
  
  
  
  secondMain(numRows, numColumns, amountToWin, game_Board); //Call function
  
  
  
  return 0; //Return interger
  
  
  
  
  
}