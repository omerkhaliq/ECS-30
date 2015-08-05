//
//  connectn.h
//  ConnectN
//
//  Created by Haaris Mirza on 3/10/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

#ifndef __ConnectN__connectn__
#define __ConnectN__connectn__

#include <stdio.h>

#endif /* defined(__ConnectN__connectn__) */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>



void player_input(int* player_Move, int number_rows, int number_columns, char** game_Board);

char** make_board(int numRows, int numColumns);

int check_arguments(int argc);

void print_board(int numRows, int numColumns, char** game_Board);

void play_game(int* player_Move, int numRows, int numColumns, char** game_Board, int* tallyAmount);

void accept_arguments(int argc, char* argv[], int* numRows, int* numColumns, int* amountToWin);

void row_winner(int amountToWin, int numRows, int numColumns, char** game_Board);

void column_winner(int amountToWin, int numRows, int numColumns, char** game_Board);

void right_diagonal_winner(int amountToWin, int numRows, int numColumns, char** game_Board);

void left_diagonal_winner(int amountToWin, int numRows, int numColumns, char** game_Board);

void secondMain(int numRows, int numColumns, int amountToWin, char** game_Board);