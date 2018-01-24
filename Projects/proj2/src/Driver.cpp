/***********************
 ** File:    Driver.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** 
 ** 
 ************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

#include "CommodityStore.h"
#include "Game.h"

const int ARG_COUNT = 5; // expected number of arguments

using namespace std;

//-------------------------------------------------------
// Name: printGreeting
// PreCondition:  none
// PostCondition: Prints out information to results file
//---------------------------------------------------------
void printGreeting(ofstream& fileStream);

//-------------------------------------------------------
// Name: convertToStrat
// PreCondition: number must be of type int
// PostCondition: Returns a enum type of Player::STRATEGY
//---------------------------------------------------------
Player::STRATEGY convertToStrat(int number);

int main (int argc, char const *argv[])
{
  if (argc != ARG_COUNT)
    {
      exit(1);
    }

  CommodityStore CS;
  Player::STRATEGY strat;
  ofstream outputFile;

  outputFile.open("results.txt");

  // Reading the commoditites file
  CS.loadCommodities(argv[2]);

  Game g1(CS);

  // Reading in card file
  g1.setDrawPile(argv[1]);

  printGreeting(outputFile);

  // Printing deck 
  g1.printDrawPile(outputFile);  
  
  // Convert the value of argv[4] to a Player::Strategy
  strat = convertToStrat(atoi(argv[4]));

  g1.runSimulation(atoi(argv[3]), strat);

  g1.printResults(outputFile);

  outputFile.close();
  return 0;
}


// printGreeting
// Prints out name and section number
void printGreeting(ofstream & fileStream)
{
  fileStream << "Marinna Ricketts-Uy, Section 02" << endl;
}

// convertToStrat
// Converts the given number to a enumerated type
Player::STRATEGY convertToStrat(int number)
{
  Player::STRATEGY strat;

  switch (number)
    {
    case 0:
      strat = Player::BEST_PAYOFF;
      break;
    case 1:
      strat = Player::FIRST_ALPHA_DESTINATION;
      break;
    case 2:
      strat = Player::COLOR_PURPLE;
      break;
    case 3:
      strat = Player::COLOR_RED;
      break;
    case 4:
      strat = Player::COLOR_ORANGE;
      break;
    case 5:
      strat = Player::COLOR_BLACK;
      break;
    case 6:
      strat = Player::COLOR_GREEN;
      break;
    default:
      strat = Player::COLOR_BROWN;
      break;
    }

  return strat;
}
