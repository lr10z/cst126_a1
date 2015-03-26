
//
// CST 126 - Assignment 1
//
// Author: Leander Rodriguez
//
// File: ticTacToe.h
//
// Constants, type definitions, and function prototypes for
// the Tic-Tac-Toe game.
//


#ifndef  ticTacToeDisplay_H
#define  ticTacToeDisplay_H


//
//  Constant values
//


  //
  // Grid, row, column values
  //
#define  CELLS_PER_SIDE  3            // # of cells on one side of the grid

#define  NUM_ROWS  CELLS_PER_SIDE     // NOTE: NUM_ROWS must be equal to NUM_COLS
#define  NUM_COLS  CELLS_PER_SIDE     //       in a Tic-Tac-Toe game


//
// Type definitions used within this file
//

  //
  // Player character values
  //
enum  Player  {
                playerNone_  =  ' ',
                player1_     =  'X',
                player2_     =  'O'
              };


  //
  // The game board
  //
typedef Player  Board[NUM_ROWS][NUM_COLS];



//
// External prototypes
//

  //
  // From ticTacToeDisplay.cpp
  //
void  displayBoard( Board  board, int  numRows, int  numCols );

  //
  // From ticTacToeValidate.cpp
  //
bool  isWinner( Board  board, Player  player );
bool  boardFull( Board  board );
bool  availableCell( Board  board, int  row,  int  col );

#endif
