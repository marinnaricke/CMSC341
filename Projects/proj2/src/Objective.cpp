/***********************
 ** File:    Objective.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the function definitions for the Objective Class.
 **
 ************************/

#include <iostream>
#include <fstream>
using namespace std;

#include "Objective.h"
#include "Commodity.h"

// Default Constructor
Objective::Objective()
{
  //left blank
}

// Non-Default Constructor
Objective::Objective(string destin, Commodity* commodity, int payoff)
{
  m_sDestination = destin;
  m_pCommodity = commodity;
  m_iPayoff = payoff;
}

// getDestination
// Returns the name of the destination
string Objective::getDestination() const
{
  return m_sDestination;
}

// getCommodity
// Returns a reference to the commodity
Commodity* Objective::getCommodity() const
{
  return m_pCommodity;
}

// getPayoff
// Returns the payoff of the objective
int Objective::getPayoff() const
{
  return m_iPayoff;
}

// printObjective
// Prints an objective to given output stream
void Objective::printObjective(ofstream& fileStream)
{
  fileStream << m_pCommodity->getName() 
	     << " to " << m_sDestination << " for " << m_iPayoff << endl;
}
