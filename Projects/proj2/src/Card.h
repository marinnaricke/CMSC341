/***********************
 ** File:    Card.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the prototypes for the Card Class and declares
 **  the member variables.
 **
 ************************/

#ifndef CARD_H
#define CARD_H

#include <vector>
using namespace std;

#include "Objective.h"

class Card
{
 public:

  // Default Constructor
  Card();

  //-------------------------------------------------------
  // Name: addObjective
  // PreCondition: objective must be a pointer to an objective
  // PostCondition: An objective is inserted into the card
  //---------------------------------------------------------
  void addObjective(Objective* objective);

  //-------------------------------------------------------
  // Name: getBestPayoff
  // PreCondition: none
  // PostCondition: Returns a pointer to the objective with
  //                 highest payoff
  //---------------------------------------------------------
  Objective* getBestPayoff();

  //-------------------------------------------------------
  // Name: getFirstAlphaDestination
  // PreCondition: none
  // PostCondition: Returns a pointer to the objective with
  //                 the first alphabetic destination name 
  //---------------------------------------------------------
  Objective* getFirstAlphaDestination();

  //-------------------------------------------------------
  // Name: getByColor
  // PreCondition: none
  // PostCondition: Returns a pointer to the objective with
  //                 a commodity of that color
  //---------------------------------------------------------
  Objective* getByColor(Commodity::COLOR color);

  //-------------------------------------------------------
  // Name: printCard
  // PreCondition: none
  // PostCondition: Prints the card to given output stream
  //---------------------------------------------------------
  void printCard(ofstream& fileStream);

 private:

  vector<Objective*> m_objectives; // stores the objectives for the card
};

#endif
