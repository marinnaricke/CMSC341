/***********************
 ** File:    Card.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the function definitions for the Card Class
 **
 ************************/

#include <iostream>
#include <fstream>
using namespace std;

#include "Card.h"

// Default Constructor
Card::Card()
{
  // left blank
}

// addObjective
// Inserts an objective into the card
void Card::addObjective(Objective* objective)
{
  m_objectives.push_back(objective);
}

// getBestPayoff
// Returns a pointer to the objective that has the best payoff
// on the card
Objective* Card::getBestPayoff()
{
  Objective* bestPay = m_objectives[0];
  Objective* tieObject;

  // Compare the payoff on each objective to one another
  for (unsigned int i = 1; i < m_objectives.size(); i++)
    {
      if (m_objectives[i]->getPayoff() > bestPay->getPayoff())
	{
	  bestPay = m_objectives[i];
	}
      else if (m_objectives[i]->getPayoff() == bestPay->getPayoff())
	{
	  tieObject = m_objectives[i];
	}
    } 

  // check if the objective that tied is still tied 
  // if so then bestPay becomes first objective on the card
  if (tieObject->getPayoff() == bestPay->getPayoff())
    {
      bestPay = m_objectives[0];
    }

  return bestPay;
}

// getFirstAlphaDestination
// Returns a pointer to the objective that has the first 
// alphabetic destination name
Objective* Card::getFirstAlphaDestination()
{
  Objective* firstAlpha = m_objectives[0];
  Objective* tieAlpha;
  
  // Compares each destination of each objective
  for (unsigned int i = 1; i < m_objectives.size(); i++)
    {
      if (m_objectives[i]->getDestination() > firstAlpha->getDestination())
	{
	  firstAlpha = m_objectives[i];
	}
      else if (m_objectives[i]->getDestination() == \
	       firstAlpha->getDestination())
	{
	  tieAlpha = m_objectives[i];
	}
    } 

  // check if the objective that tied is still tied 
  // if so that firstAlpha becomes first objective on the card
  if (tieAlpha->getDestination()  == firstAlpha->getDestination())
    {
      firstAlpha = m_objectives[0];
    }

  return firstAlpha;
}

// getByColor
// Returns a pointer to the obective with a commodity who color 
// matches the requested color.
Objective* Card::getByColor(Commodity::COLOR color)
{
  // stores the objective that will be choosen
  Objective* currentPick;

  // used to keep track of how many cards match the color
  int count = 0; 

  for (unsigned int i = 0; i < m_objectives.size(); i++)
    {
      if (m_objectives[i]->getCommodity()->getColor() == color && (count == 0))
	{
	  currentPick = m_objectives[i];
	  count++;
	}
      // if there is more than one card with the color
      else if (m_objectives[i]->getCommodity()->getColor() == color \
	       && (count != 0))
	{
	  if (m_objectives[i]->getPayoff() > currentPick->getPayoff())
	    {
	      currentPick = m_objectives[i];
	      count++;
	    }
	}
    }   

  // objective with highest should be choosen if no card matched color
  if (count == 0)
    {
      currentPick = getBestPayoff();
    }

  return currentPick;
}

// printCard
// Prints the card with its objectives in the order they 
// were read in from the file to the given output stream
void Card::printCard(ofstream& fileStream)
{
  Objective* currentObj;

  fileStream << "---------- CARD ----------" << endl;
  for (unsigned int i = 0; i < m_objectives.size(); i++)
    {
      currentObj = m_objectives[i];
      currentObj->printObjective(fileStream);
    }
  
  fileStream << "--------------------------" << endl;

}
