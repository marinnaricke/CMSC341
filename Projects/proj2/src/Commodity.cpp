/***********************
 ** File:    Commodity.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the function definitions for the Commodity Class.
 **
 ************************/

#include <iostream>
using namespace std;

#include "Commodity.h"

// Default Constructor
Commodity::Commodity()
{
  m_sName = "";
  m_eColor = COLORLESS;
}

// Non-Default Constructor
Commodity::Commodity(string name, COLOR color)
{
  m_sName = name;
  m_eColor = color;

}

// getName
// Returns the name of the commodity
string Commodity::getName() const
{
  return m_sName;
}

// getColor
// Returns the color index of the commodity
Commodity::COLOR Commodity::getColor() 
{
  return m_eColor;
}
