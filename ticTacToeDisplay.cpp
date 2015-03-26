
//
// CST 126 - Assignment 1
//
// Author: Leander Rodriguez
//
// File: ticTacToeDisplay.cpp
//
// Game board routines for the Tic-Tac-Toe game.
//


#include  <iostream>
#include  "ticTacToe.h"
#include  "consoleGraphics.h"


using  namespace  std;


//
// Local functions
//


//
// Display the column headers for the grid.
//
static void  displayTitleRows( int  numCols )
{
  int  col;


  cout  <<  "   ";

  for( col = 0;  col < numCols;  ++col )
    cout  <<  "  "  <<  col+1  <<  ' ';

  cout  <<  endl;
}


//
// Display a solid-line grid row
//
static void  displayBorderRow( int  numCols )
{
  cout  <<  "    ";

  for( int  col = 0;  col < numCols;  ++col )
  {
    cout  <<  CG_LINE_HOR
          <<  CG_LINE_HOR
          <<  CG_LINE_HOR;

    if  (col != numCols-1)
      cout  <<  CG_CROSS;
  }

  cout  <<  endl;
}


//
// Display a hollow-line grid row
//
static void  displayBlankRow( int  numCols )
{
  cout  <<  "    ";

  for( int  col = 0;  col < numCols;  ++col )
  {
    cout  <<  "   ";

    if  (col != numCols-1)
      cout  <<  CG_LINE_VERT;
  }

  cout  <<  endl;
}


//
// Display a hollow-line grid row that has cell data in
// incorporated.
//
static void  displayDataRow( Board  board, int  rowNum, int  numCols )
{
  cout  <<  "  "  <<  rowNum+1  <<  ' ';

  for( int  col = 0;  col < numCols;  ++col )
  {
    cout  <<  ' '  <<  char( board[rowNum][col] )  <<  ' ';

    if  (col != numCols-1)
      cout  <<  CG_LINE_VERT;
  }

  cout  <<  endl;
}


//
// Global functions
//


//
// Display the game board
//
void  displayBoard( Board  board, int  numRows, int  numCols )
{
  cout  <<  endl;

  displayTitleRows( numCols );

  cout  <<  endl;

  for( int  row = 0;  row < numRows;  ++row )
  {
    displayBlankRow( numCols );
    displayDataRow(board, row, numCols);
    displayBlankRow( numCols );

    if  (row == numRows-1)
      cout  <<  endl;
    else
      displayBorderRow( numCols );
  }

  cout  <<  endl;
}
