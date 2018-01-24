/***********************
 ** File:    Objective.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the prototypes and member variables
 **  for the Objective Class.
 **
 ************************/

#ifndef OBJECTIVE_H
#define OBJECTIVE_H

using namespace std;

#include "Commodity.h"

class Objective
{
 public:

  // Default Constructor
  Objective();

  // Non-Default Constructor
  Objective(string destin, Commodity* commodity, int payoff);

  //-------------------------------------------------------
  // Name: getDestination
  // PreCondition:  none
  // PostCondition: Returns a string
  //---------------------------------------------------------
  string getDestination() const;

  //-------------------------------------------------------
  // Name: getCommodity
  // PreCondition:  none
  // PostCondition: Returns a pointer to a commodity
  //---------------------------------------------------------
  Commodity* getCommodity() const;

  //-------------------------------------------------------
  // Name: getPayoff
  // PreCondition:  none
  // PostCondition: Returns a integer value
  //---------------------------------------------------------
  int getPayoff() const;

  //-------------------------------------------------------
  // Name: printObjective
  // PreCondition:  none
  // PostCondition: Prints out objective
  //---------------------------------------------------------
  void printObjective(ofstream& fileStream);

 private:

  string m_sDestination;    // name of the destination
  Commodity* m_pCommodity;  // pointer to instance in the commodity store 
  int m_iPayoff;            // amount player will recieve 

};

#endif
