/***********************
 ** File:    Game.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the function definitions for 
 **  the Game Class.
 **
 ************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <map>
using namespace std;

#include "Game.h"

// Default Constructor
Game::Game()
{
  //left blank
}

// Non-Default Constructor
Game::Game(CommodityStore bank)
{
  m_bank = bank;
}

// runSimulation
// Runs through the simulations of playing the game using the
//  given strategy with the given number of players
void Game::runSimulation(int players, Player::STRATEGY strategy)
{
  Player* player;
  string playerNum;
  int numCards;
  Card* gameCard;

  // Create the players
  for (int i = 0; i < players; i++)
    {
      // Converts the int to a string
      ostringstream convert;
      convert << (i + 1);
      playerNum = convert.str();

      player = new Player("Player " + playerNum);
      m_players.push_back(player);
    }

  // Equally divide the cards amongst the players
  int perPlayer = (m_drawPile.size() / players);
  numCards = (perPlayer * players);

  if (players > numCards)
    {
      cerr << "Too many players and not enough cards!" << endl;
      exit(1);
    }

  // Deal the cards to the players
  while ( numCards != 0)
    {
      for (int i = 0; i < players; i++)
	{
	  gameCard = m_drawPile.top();

	  m_players[i]->addCard(gameCard);
	  
	  m_drawPile.pop();
	}

      numCards -= players;
    }

  // Calculate the scores for each player, store the scores for each
  for (int i = 0; i < players; i++)
    {
      m_playerScores.push_back(m_players[i]->calculateScore(strategy));
    }

  // Determine the winner
  int currentWinner = 0;

  for (int i = 0; i < players; i++)
    {
      if (m_playerScores[i] > m_playerScores[currentWinner])
	{
	  currentWinner = i; 
	}
    }

  // Winner of the game with the highest score
  m_gameWinner = m_players[currentWinner];
}

// printDrawPile
// Prints the current state of the drawPile to a given
//  output stream
void Game::printDrawPile(ofstream& fileStream)
{
  //make a copy of the stack to use for printing
  stack<Card*> copyPile;
  Card* currentCard;

  fileStream << "---------- Draw Pile ----------" << endl;

  for (copyPile = m_drawPile; !copyPile.empty(); copyPile.pop())
    {
      currentCard = copyPile.top();
      currentCard->printCard(fileStream);
    }
}

// printResults
// Prints the result of the simulation to a given output stream
void Game::printResults(ofstream& fileStream)
{
  fileStream << "---------- RESULTS ----------" << endl;

  for (unsigned int i = 0; i < m_players.size(); i++)
    {
      m_players[i]->printResult(fileStream);      
    }

  fileStream << "--------------------------" << endl;
  fileStream << "--------------------------" << endl;

  fileStream << "Winner: " << m_gameWinner->getName() 
	     << " Score: " << m_gameWinner->getScore() << endl;
}

// setDrawPile
// Creates the drawPile for the game
void Game::setDrawPile(string filename)
{
  ifstream infile;
  string destin1, commodity1, payoff1, destin2, commodity2, payoff2, destin3, \
    commodity3, payoff3, oneLine;
  Objective *object1, *object2, *object3;

  // Opening the cards file
  infile.open(filename.c_str(), ios_base::in);

  // Checking if file can be opened
  if (infile.fail())
    {
      cerr << "File could not be successfully opened." << endl;
      exit(1);
    }
  else
    {
      //parse the data, create and store objectives
      while (true)
        {
          getline(infile, oneLine);

          //Checks if it reached end of file
          if (infile.eof())
            {
              break;
            }
          // Reads in one line at a time
          istringstream istrm(oneLine);

          istrm >> destin1;
          istrm >> commodity1;
          istrm >> payoff1;

          istrm >> destin2;
          istrm >> commodity2;
          istrm >> payoff2;

          istrm >> destin3;
          istrm >> commodity3;
          istrm >> payoff3;

          // Create Objectives
          object1 = new Objective(destin1,m_bank.getCommodity(commodity1), \
                                  atoi(payoff1.c_str()));
          object2 = new Objective(destin2, m_bank.getCommodity(commodity2), \
                                  atoi(payoff2.c_str()));
          object3 = new Objective(destin3, m_bank.getCommodity(commodity3), \
                                  atoi(payoff3.c_str()));

          Card* gameCard = new Card();

          gameCard->addObjective(object1);
          gameCard->addObjective(object2);
          gameCard->addObjective(object3);

          m_drawPile.push(gameCard);
        }
    }
  infile.close();
}
