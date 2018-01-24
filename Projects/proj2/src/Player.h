/***********************
 ** File:    Player.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the prototypes and member variables
 **  for the Player Class.
 **
 ************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <queue>

using namespace std;

#include "Card.h"

class Player
{
 public:

  enum STRATEGY {
    BEST_PAYOFF,
    FIRST_ALPHA_DESTINATION,
    COLOR_PURPLE,
    COLOR_RED,
    COLOR_ORANGE,
    COLOR_BLACK,
    COLOR_GREEN,
    COLOR_BROWN
  };
  
  // Default Constructor
  Player();

  // Non-Default Constructor
  Player(string name);

  //-------------------------------------------------------
  // Name: getName
  // PreCondition:  none
  // PostCondition: Returns the player's name
  //---------------------------------------------------------
  string getName() const;

  //-------------------------------------------------------
  // Name: getScore
  // PreCondition: none
  // PostCondition: Returns the player's score
  //---------------------------------------------------------
  int getScore() const;

  //-------------------------------------------------------
  // Name: addCard
  // PreCondition: card must be a pointer to a card
  // PostCondition: Given card is added to players hand
  //---------------------------------------------------------
  void addCard(Card* card);

  //-------------------------------------------------------
  // Name: calculateScore
  // PreCondition: none
  // PostCondition: Processes the players with given strategy
  //---------------------------------------------------------
  int calculateScore(Player::STRATEGY strategy);

  //-------------------------------------------------------
  // Name: printResults
  // PreCondition: none
  // PostCondition: Prints results objectives and final score
  //---------------------------------------------------------
  void printResult(ofstream& fileStream);

 private:

  string m_sName;    // player's name 
  int m_playerScore; // stores the final score for the player
  queue<Card*> m_cards; // holds the cards for the player
  queue<Objective*> m_objectives; // holds the selected objectives
};

#endif
