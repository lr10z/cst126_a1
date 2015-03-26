
//
// CST 126 - Assignment 1
//
// Author: Leander Rodriguez
//
// File: main.cpp
//
// Sample program to illustrate the usage of the consoleGraphics.h
// character graphics constants.
//


#include  <iostream>
#include  "consoleGraphics.h"


#define LENGTH  10
#define HEIGHT  3


using  namespace  std;


//
// Main program
//
int  main()
{
  int  i;


  //
  // Draw a horizontal line, vertical line, and cross
  //

  cout  <<  CG_LINE_HOR  <<  CG_LINE_VERT  <<  CG_CROSS  <<  endl  <<  endl;

  cout  <<  endl;


  //
  // Draw a horizontal line that is LENGTH characters wide
  //
  for( i = 0;  i < LENGTH;  ++i )
    cout  <<  CG_LINE_HOR;

  cout  <<  endl  <<  endl;


  //
  // Draw a vertical line that is HEIGHT characters high
  //
  for( i = 0;  i < HEIGHT;  ++i )
    cout  <<  CG_LINE_VERT  <<  endl;

  cout  <<  endl;


  //
  // Draw a cross that is 5 characters high and 5 characters wide
  //
  cout  <<  "  "  <<  CG_LINE_VERT  <<  endl;
  cout  <<  "  "  <<  CG_LINE_VERT  <<  endl;

  cout  <<  CG_LINE_HOR  <<  CG_LINE_HOR
        <<  CG_CROSS
        <<  CG_LINE_HOR  <<  CG_LINE_HOR  <<  endl;

  cout  <<  "  "  <<  CG_LINE_VERT  <<  endl;
  cout  <<  "  "  <<  CG_LINE_VERT  <<  endl;

  return  0;
}
