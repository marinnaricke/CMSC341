/***********************
 ** File:    Game.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the prototypes and member variables 
 **  for the Game Class.
 **
 ************************/

#ifndef GAME_H
#define GAME_H

#include <stack>
#include <map>

using namespace std;

#include "Player.h"
#include "CommodityStore.h"

class Game
{
 public:
  
  // Default constructor
  Game();

  // Non-Default Constructor
  Game(CommodityStore bank);

  //-------------------------------------------------------
  // Name: runSimulation
  // PreCondition: none
  // PostCondition: Runs through the simulation of the game
  //---------------------------------------------------------
  void runSimulation(int players,Player::STRATEGY strategy);

  //-------------------------------------------------------
  // Name: printDrawPile
  // PreCondition: none 
  // PostCondition: Prints the current state of the drawPile
  //---------------------------------------------------------
  void printDrawPile(ofstream& fileStream);

  //-------------------------------------------------------
  // Name: printResults
  // PreCondition: none
  // PostCondition: Prints the result of the simulation
  //---------------------------------------------------------
  void printResults(ofstream& fileStream);


  //-------------------------------------------------------
  // Name: setDrawPile
  // PreCondition: filename must be of type string
  // PostCondition: Sets the drawPile for the game
  //---------------------------------------------------------
  void setDrawPile(string filename);

 private:

  stack<Card*> m_drawPile;     // stores the deck of cards 
  vector<Player*> m_players;   // stores the list of players
  CommodityStore m_bank;      // stores all known commodities
  vector<int> m_playerScores; // stores the final score for each player
  Player* m_gameWinner;      // stores the pointer to the winner
};

#endif
