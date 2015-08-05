#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

void accept_arguments(int argc, char* argv[], int* numRows, int* numColumns, int* amountToWin){ //Get the different arguments
  
  *numRows = atoi(argv[1]); //Create pointer of the number of rows by converting command line to interger
  *numColumns = atoi(argv[2]); //Command line is converter to interger and storeed for number of columns
  *amountToWin = atoi(argv[3]); //Command line is converted into interger for how many peices in a row is needed to win the game.
}


char** make_board(int numRows, int numColumns){ //This function creates the board to play on.
  
  int i; //Used later in 'for loop'
  int j; //Used later in 'for loop'
  
  char** game_Board; //Create double pointer of game board
  
  game_Board = (char**)malloc(numRows * sizeof(char*)); //Part 1 of allocating space for game board since its a double pointer
  
  for(i = 0; i < numRows; ++i){
    
    game_Board[i] = (char*)malloc(numColumns * sizeof(char*)); //Part 2 for allocating space for game board since its a double pointer
    
  }
  
  //This for loop will make the board
  
  for(i = 0; i < numRows; ++i){
    
    for(j = 0; j < numColumns; ++j){
      
      game_Board[i][j] = '*'; //A '*' character is placed in each postion of game board
      
    }
    
  }
  
  return game_Board; //Returns the value of the game board.
  
}

void print_board(int numRows, int numColumns, char** game_Board){ //This function will print the game board
  
  int i; //Used later in the for loop
  int j; //Used later in the for loop
  
  
  //This for loop is used to print out the board
  
  for (i = 0; i < numRows; i++) {
    
    printf("%d ", numRows - i - 1); //This will print the number of each row on the y axis of the board
    
    for (j = 0; j < numColumns; j++) {
      
      printf(" %c", game_Board[i][j]); //This will print the actual characters or for now the '*' characters of the board
      
    }
    
    printf("\n"); //A new line is printed after each set of a number and '*'s
    
  }
  
  printf("  ");
  
  //This loop is used to print out the numbers of each column on the x-axis of the board
  for (i = 0; i < numColumns; i++) {
    
    printf(" %d", i); //Prints each value of 'i'
    
  }
  
  printf("\n");
  
}

int check_arguments(int argc){ //This function is used in the beginning to check how many arguments were inputted so we know if we can play or not
  
  int continue_To_Play = 0;
  
  if(argc == 4){ //There need to be a total of 4 arguments to play and this will check that
    
    continue_To_Play = 1; //The value of 1 will be stored if the if statement runs
    
  }
  
		else if (argc < 4) { //Will run if there are less than 4 arguments
      
      printf("Not enough arguments entered\n"); //Will be shown to the user so they know why program is not working.
      
      printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
      
      continue_To_Play = 0; //0 will be stored as its value
      
      exit(0);
    }
    else { //If there are more than 4 arguments than this will run
      
      printf("Too many arguments entered\n"); //This will be shown to the user
      
      printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
      
      continue_To_Play = 0; //0 is stored as its value
      
      exit(0);
    }
  return continue_To_Play;
}


void player_input(int* player_Move, int numRows, int numColumns, char** game_Board) { //This function checks if the column entered works
  
  do{ //Do-While loop works keeps on going if the value is less than 0 or more than the number of columns there are
    
    printf("Enter a column between 0 and %d to play in: ", numColumns-1); //Print statement
    
    scanf("%d", player_Move);
    
  } while ( (*player_Move < 0) || (*player_Move > numColumns - 1)); //Checks if point is within these conditions
}


void play_game(int* player_Move, int numRows, int numColumns, char** game_Board, int* tallyAmount){ //This function plays the game
  
  int i; //Used for 'for loop'
  int full = 0; //Will be used later to check if row is full
  
  for(i = numRows - 1; i >= 0 ; i--){ //Will input the value at the next empty space in that column chosen
    
    
    if((game_Board[i][*player_Move]) == 'X' || game_Board[i][*player_Move] == 'O'){ //Checks if position is already taken by a 'X' or 'O'
      
      ++full; //full value is increased each time this statement runs
      
    }
    
  }
  
  if (full != numRows){ //Runs when it is not full
    
    for(i = numRows - 1; i >= 0 ; i--){ //Will input the value at the next empty space in that column chosen
      
      if((game_Board[i][*player_Move]) == '*'){ //Checks from the bottom of the board and occupies the first empty space
        
        if (((*tallyAmount) % 2) == 0){ //This helps determine who's turn it is. Player with 'X' is even
          
          game_Board[i][*player_Move] = 'X'; //Prints 'X'
          
          break;	//Will break out of loop once it executes
          
        }
      }
      
      if((game_Board[i][*player_Move]) == '*'){ //Checks from the bottom of the board and occupies the first empty space
        
        if(((*tallyAmount) % 2) != 0){ //When help determine who's turn it is, Player 'O' will have a remainder after turn and therefore will not equal 0
          
          game_Board[i][*player_Move] = 'O'; //Prints 'O' into the position chosen
          
          break; //Breaks out of for loop
          
        }
        
      }
      
    }
    
    print_board(numRows, numColumns, game_Board); //Board will reprint after either an 'X' or 'O' is inputted
    
    ++(*tallyAmount);
    
  }
  
}


void row_winner(int amountToWin, int numRows, int numColumns, char** game_Board){ //This function checks when there will be a winner by checking the rows.
  
  int i; //Used in for loop
  int j; //Used in for loop
  int countX = 1; //Counts how many 'X's there are
  int countO = 1; //Counts how many 'O's there are in a row
  
  for(i = 0; i < numRows; ++i){
    
    for(j = 0; j < numColumns; ++j){
      
      if(game_Board[i][j] == game_Board[i][j+1]){ //Will check each point next to each other
        
        if(game_Board[i][j] == 'X'){ //Checks if the point is an 'X'
          
          ++countX; //'X' count is increased if true
          
          if(countX == amountToWin){ //'X' counter will continue to increase until it reaches number to win
            
            printf("Player 1 Won!\n"); //Player 1 has 'X' so they will win if they have the number to win in a row
            
            exit(0);
            
          }
          
        }
        
        if(game_Board[i][j] == 'O'){ //This checks if there is an 'O'
          
          ++countO; //'O' count is increased if true
          
          if(countO == amountToWin){ //'O' count will increase until it reaches the number to win
            
            printf("Player 2 Won!\n"); //Player 2 uses 'O' so they will win if they have the number to win in a row
            
            exit(0);
            
          }
          
        }
        
      }
      
      else{
        
        countX = 1;
        
        countO = 1;
        
      }
      
    }
    
  }
}





void column_winner(int amountToWin, int numRows, int numColumns, char** game_Board){ //This function will check the columns to see how many are in a row
  
  
  
  int i; //Use in for loop
  int j; //Use in for loop
  
  int countX = 1; //Counts how many 'X's there are
  
  int countO = 1; //Counts how many 'O's there are
  
  
  
  
  
  for(i = 0; i < numColumns; ++i){
    
    for(j = 0; j < (numRows - 1); ++j){
      
      if(game_Board[j][i] == game_Board[j+1][i]){ //Checks if the adjacent letters are the same
        
        if(game_Board[j][i] == 'X'){ //Checks if the letter is 'X'
          
          ++countX; //X counter is increased
          
          if(countX == amountToWin){ //Checks if number of 'X's in a row matches the number to win
            
            printf("Player 1 Won!\n"); //Printed statement
            
            exit(0);
            
          }
          
        }
        
        if(game_Board[j][i] == 'O'){ //Checks if the letter is an 'O'
          
          ++countO; //'O' counter is increased
          
          if(countO == amountToWin){ //Checks if number of 'X's in a row matches number to win
            
            printf("Player 2 Won!\n"); //Printed statement
            
            exit(0);
            
          }
        }
        
      }
      
      else{
        
        countX = 1;
        
        countO = 1;
        
      }
      
    }
    
  }
  
}





void right_diagonal_winner(int amountToWin, int numRows, int numColumns, char** game_Board){ //Checks who the winnder is by checking diagonally
  
  
  
  int i; //Used in for loop
  int j; //Used in for loop
  int k; //Used in for loop
  
  int countX = 1;
  
  int countO = 1;
  
  
  
  if(amountToWin > numRows){
    
    return; //This will make us break out of the funcion if the 'if' statement is true
    
  }
  
  
  
  for(i = (numRows - 1); i >= 0; --i){
    
    for(j = (numColumns - 1); j >= 0; --j){
      
      k = 1;
      
      while((i - k) >= 0 && (j - k) >= 0){ //Used so it doesn't go out of board
        
        if(game_Board[i][j] == game_Board[i - k][j - k]){
          
          ++k; //increases k if if-statement is true
          
          if(game_Board[i][j] == 'X'){
            
            ++countX; //increases 'X' count
            
            if(countX == amountToWin){
              
              printf("Player 1 Won!\n"); //print statement
              
              exit(0);
              
            }
            
          }
          
          if(game_Board[i][j] == 'O'){ //Checks if the peice is an 'O'
            
            ++countO; //Increases 'O' counter
            
            if(countO == amountToWin){
              
              printf("Player 2 Won!\n");
              
              exit(0);
              
            }
            
          }
          
        }
        
        else{
          
          countX = 1;
          
          countO = 1;
          
          break; //Breaks out of this loop and goes into the j loop
          
        }
        
      }
      
    }
    
  }
  
}





void left_diagonal_winner(int amountToWin, int numRows, int numColumns, char** game_Board){ //This is similar to the above function but it checks from the bottom left to top right
  
  int i; //Used in for loop
  int j; //Used in for loop
  int k;
  
  int countX = 1;
  
  int countO = 1;
  
  
  
  if(amountToWin > numRows){
    
    return; //Is used to break out of the function
    
  }
  
  
  
  for(i = (numRows - 1); i >= 0; --i){
    
    for(j = 0; j < numColumns; ++j){
      
      k = 1;
      
      while((i - k) >= 0 && (k + j) < numColumns){
        
        if(game_Board[i][j] == game_Board[i-k][j+k]){ //Checks the next diagonal point
          
          ++k; //Increase k
          
          if(game_Board[i][j] == 'X'){ //Checks if the peice is an 'X'
            
            ++countX; //Increases the x count each time 
            
            if(countX == amountToWin){
              
              printf("Player 1 Won!\n");
              
              exit(0);
              
            }
            
          }
          
          if(game_Board[i][j] == 'O'){
            
            ++countO;
            
            if(countO == amountToWin){
              
              printf("Player 2 Won!\n");
              
              exit(0);
              
            }
            
          }
          
        }
        
        
        
        else{
          
          countX = 1;
          
          countO = 1;
          
          break; //Breaks out of loop and goes to j loop
          
        }
        
      }
      
    }
    
  }	
  
}



void secondMain(int numRows, int numColumns, int amountToWin, char** game_Board){ //Functions is the secondary main function
  
  int player_Move;
  
  int tallyAmount = 0;
  
  
  
  while (tallyAmount != numRows * numColumns){
    
    //Here is a list of functions being called
    
    player_input(&player_Move, numRows, numColumns, game_Board); 
    
    
    
    play_game(&player_Move, numRows, numColumns, game_Board, &tallyAmount); 
    
    
    
    row_winner(amountToWin, numRows, numColumns, game_Board);
    
    
    column_winner(amountToWin, numRows, numColumns, game_Board);
    
    
    
    right_diagonal_winner(amountToWin, numRows, numColumns, game_Board); 
    
    
    
    left_diagonal_winner(amountToWin, numRows, numColumns, game_Board); 
    
    
  }
  
  
  
  printf("Tie game!\n"); //prints if game ends up being a tie game
  
}
