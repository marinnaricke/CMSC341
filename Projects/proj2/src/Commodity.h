/***********************
 ** File:    Commodity.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the prototypes and member variables
 **  for the Commodity Class.
 **
 ************************/

#ifndef COMMODITY_H
#define COMMODITY_H

using namespace std;

class Commodity
{
 public:

  enum COLOR {
    PURPLE,
    RED,
    ORANGE,
    BLACK,
    GREEN,
    BROWN,
    COLORLESS
  };

  // Default constructor
  Commodity();

  // Non-Default Constructor
  Commodity(string name, COLOR color);

  //-------------------------------------------------------
  // Name: getName
  // PreCondition: none
  // PostCondition: Returns a string
  //---------------------------------------------------------
  string getName() const;

  //-------------------------------------------------------
  // Name: getColor
  // PreCondition:  none
  // PostCondition: Returns enum COLOR
  //---------------------------------------------------------
  COLOR getColor();

 private:

  string m_sName; // stores the commodity name 
  COLOR m_eColor; // stores the commodity color index

};

#endif
