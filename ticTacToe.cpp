
//
// CST 126 - Assignment 1
//
// Author: Leander Rodriguez
//
// File: ticTacToe.cpp
//
// This file contains the implementation of a TicTacToe
// game routines other than board display and validation.
//
// The grid size (3x3, 4x4, ...) can be set by changing
// the value of CELLS_PER_SIDE (defined in ticTacToe.h)
// before compiling/linking.
//


#include  <iostream>
#include  <cctype>
#include  "ticTacToe.h"


using  namespace  std;


//
// Local functions
//


//
// Given the current player, this function determines and
// returns the next player.
//
static Player  nextPlayer( Player  currentPlayer )
{
  return  currentPlayer == player1_  ?  player2_  :  player1_;
}


//
// Prompt the user to play again and validates their response.
// Returns true if the user wants to play again, otherwise false.
//
static bool  playAgain()
{
  cout  <<  endl;

  char  userInput;

  while(true)
  {
    cout  <<  "Another game (y/n): ";

    cin  >>  userInput;

    userInput  =  tolower(userInput);
    if  (userInput == 'y'  ||  userInput == 'n')  break;
  }

  return  userInput == 'y';
}


//
// Initialize all grid cells such that no player
// has made a move yet.
//
static  void  initialize( Board  board )
{
  for( int  row = 0;  row < NUM_ROWS;  ++row )
    for( int  col = 0;  col < NUM_COLS;  ++col )
      board[row][col]  =  playerNone_;
}


//
// Prompt the user for a row/col cell check choice, adjust the user
// values to zero-based array index values, and validate the
// user's values. As long as the user enters invalid values,
// they will be reprompted. Once valid values are entered,
// the row and column values are put in the memory specified
// by the userRow and userCol pointer parameters.
//
static void  getUsersCellChoice( Board  board, Player  player, int  &userRow, int  &userCol )
{
  while( true )
  {
    //
    // Prompt the user
    //
    cout  <<  char(player)  <<  " - enter row,col: ";

    char  dummyComma;

    cin  >>  userRow  >>  dummyComma  >>  userCol;


    //
    // Adjust values so they can be used as zero-based array indexes
    //
    userRow--;
    userCol--;


    //
    // Validate the values
    //
    if  ( availableCell( board, userRow, userCol ) )
      break;
  }
}


//
// Get the user's grid location choice and update the grid
// appropriately.
//
static void  processPlayerChoice( Board  board, Player  player )
{
  int  userRow;
  int  userCol;

  getUsersCellChoice( board, player, userRow, userCol );

  board[userRow][userCol]  =  player;
}


//
// Returns the character of the player that has won. If
// no-one has one, playerNone_ is returned.
//
static char  determineWinner( Board  board )
{
  if  ( isWinner( board, player1_ ) )  return  player1_;

  if  ( isWinner( board, player2_ ) )  return  player2_;

  return  playerNone_;
}


//
// The main loop for the game.
//
static void  play()
{
  Player  curPlayer  =  player2_;


  //
  // Create an initialize the game board
  //

  Board  board;

  initialize( board );


  //
  // Loop until there's a winner or a tie game is detected.
  //
  while( true )
  {
    //
    // Determine the current player and display the game board.
    //
    curPlayer  =  nextPlayer( curPlayer );

    displayBoard( board, NUM_ROWS, NUM_COLS );



    //
    // See if there's a winner. If so, report this and break out
    // of the game loop.
    //
    char  winner  =  determineWinner( board );
    if  ( winner != playerNone_ )
    {
      cout  <<  "*** "  <<  winner  <<  "'s have won"  <<  endl;
      break;
    }



    //
    // See if there's a tie game. If so, report this and break out
    // of the game loop.
    //
    if  ( boardFull( board ) )
    {
      cout  <<  "*** Tie game"  <<  endl;
      break;
    }


    //
    // Process the current player's move
    //
    processPlayerChoice( board, curPlayer );
  }
}


//
// Main program
//
int  main()
{
  //
  // Due to a bug in the Visual C++ 2005 compiler, the following
  // line of code must be done to enable comma-separated integer
  // input.
  //
  cin.imbue(locale("C"));


  //
  // Loop for as long as the user wants to continue playing.
  //
  do
  {
    play();

  }  while( playAgain() );


  return  0;
}
