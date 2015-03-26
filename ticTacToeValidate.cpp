

//
// CST 126 - Assignment 1
//
// Author: Leander Rodriguez
//
// File: ticTacToeValidate.cpp
//
// Validate routines for the Tic-Tac-Toe game.
//


#include  <iostream>
#include  "ticTacToe.h"


using  namespace  std;


//
// Local functions
//


//
// Returns true if CELLS_PER_SIDE cells in the grid contain the
// the same player identifier based on a pattern.
//
// Parameters:
//
//   board - specifies the grid to analyze
//
//   player - specifies the player
//
//   startRow, startCol (both zero-based) - specify the starting
//      location of the grid positions to analyze
//
//   rowInc - specifies what to add to the row during each iteration to
//   get to the next cell to analyze.
//
//   colInc - specifies what to add to the col during each iteration to
//   get to the next number to be summed.
//
static  bool  win( Board  board, Player  player, int  startRow, int  startCol, int  rowInc, int  colInc )
{
  //
  // Continues looping through CELLS_PER_SIZE cells in the pattern unless
  // a cell that doesn't match the player is found.
  //
  for( int  count = 0,
            row  =  startRow,
            col  =  startCol;    count < CELLS_PER_SIDE;   row += rowInc,
                                                           col += colInc,
                                                           ++count )
  {
    if  ( board[row][col] != player )  return  false;
  }

  return  true;
}


//
// Global functions
//


//
// Returns true if a specified player has won.
//
bool  isWinner( Board  board, Player  player )
{
  //
  // Check for a row win
  //
  for( int  row = 0;  row < NUM_ROWS;  ++row )
    if  ( win( board, player, row, 0, 0, 1 ) )  return  true;


  //
  // Check for a column win
  //
  for( int  col = 0;  col < NUM_COLS;  ++col )
    if  ( win( board, player, 0, col, 1, 0 ) )  return  true;


  //
  // Check for a diagonal win
  //
  return  win( board, player, 0, 0, 1, 1 )  ||
          win( board, player, CELLS_PER_SIDE-1, 0, -1, 1 );
}


//
// Returns true if all game board cells are occupied
// by either player.
//
bool  boardFull( Board  board )
{
  int  nCellsOccupied  =  0;

  for( int  row = 0;  row < NUM_ROWS;  ++row )
    for( int  col = 0;  col < NUM_COLS;  ++col )
    {
      if  ( board[row][col] !=  playerNone_ )
        ++nCellsOccupied;
    }

  return  nCellsOccupied == NUM_ROWS * NUM_COLS;
}


//
// Validates that a cell is available. This includes row/col
// bounds checking and checking for the cell already being
// occupied. A descriptive error message is displayed if the
// cell is not available and false is returned. True is returned
// if the cell is available.
//
bool  availableCell( Board  board, int  row,  int  col )
{
  bool  available  =  true;


  //
  // Check row boundries
  //
  if  ( row < 0  ||  row >= NUM_ROWS )
  {
    cout  <<  "*** Invalid row number!"  <<  endl;
    available  =  false;
  }


  //
  // Check column boundries
  //
  if  ( col < 0  ||  col >= NUM_COLS )
  {
    cout  <<  "*** Invalid column number!"  <<  endl;
    available  =  false;
  }


  //
  // Return now if there is a bounds error. Don't want to check
  // availability with out-of-bound index values.
  //
  if  (! available)  return  false;


  //
  // Check cell availability
  //
  if  ( board[row][col]  !=  playerNone_ )
  {
    cout  <<  "*** Cell is already occupied!"  <<  endl;
    available  =  false;
  }


  return  available;
}
