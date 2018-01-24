/***********************
 ** File:    Player.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the function definitions for the Player Class.
 **
 ************************/

#include <iostream>
#include <fstream>
using namespace std;

#include "Player.h"

// Default Constructor
Player::Player()
{
  m_sName = "";
  m_playerScore = 0;
}

// Non-Default Constructor
Player::Player(string name)
{
  m_sName = name;
  m_playerScore = 0;
}

// getName
// Returns the string of the Player, format "Player #"
string Player::getName() const
{
  return m_sName;
}

// getScore
// Returns the score received for each player
int Player::getScore() const
{
  return m_playerScore;
}

// addCard
// Adds a given card to the players hand
void Player::addCard(Card* card)
{
  m_cards.push(card);
}

// calculateScore 
// Processes the players hand using the given strategy
//  and stores and returns the score.
int Player::calculateScore(Player::STRATEGY strategy)
{
  Objective* objective;
  queue<Card*> copyHand = m_cards;
  Card* gameCard;

  for (copyHand = m_cards; !copyHand.empty(); copyHand.pop())
    {
      gameCard = copyHand.front();
      
      switch (strategy)
	{
	case 0:
	  objective = gameCard->getBestPayoff();
	  break;
	case 1:
	  objective = gameCard->getFirstAlphaDestination();
	  break;
	case 2:
	  objective = gameCard->getByColor(Commodity::PURPLE);
	  break;
	case 3:
	  objective = gameCard->getByColor(Commodity::RED);
	  break;
	case 4:
	  objective = gameCard->getByColor(Commodity::ORANGE);
	  break;
	case 5:
	  objective = gameCard->getByColor(Commodity::BLACK);
	  break;
	case 6:
	  objective = gameCard->getByColor(Commodity::GREEN);
	  break;
	default:
	  objective = gameCard->getByColor(Commodity::BROWN);
	  break;
	}

      m_playerScore += objective->getPayoff();
      
      m_objectives.push(objective);
    }

  return m_playerScore;
}

// printResult
// Prints the resulting objectives selected by the player from each
//  card and the player's final score.
void Player::printResult(ofstream& fileStream)
{
  queue<Objective*> copyPile;
  Objective* currentObject;


  fileStream << "--------" << m_sName << "------------" << endl;
  
  for (copyPile = m_objectives; !copyPile.empty(); copyPile.pop())
    {
      currentObject = copyPile.front();
      currentObject->printObjective(fileStream);
    }
  
  fileStream << "Score: " << m_playerScore << endl;
}

