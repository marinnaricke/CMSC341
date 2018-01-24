/***********************
 ** File:    Continent.h
 ** Project: CMSC 341 Project 0, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    9/13/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the .h files for the Continent class and
 ** inherits from the Country class.
 ************************/

#ifndef Continent_H
#define Continent_H

#include <iostream>
#include <vector>
using namespace std;

#include "Country.h"

class Continent : public Country
{
 public:

  // Default Constructor
  Continent();

  // Non-default Constructor
  Continent(string name);

  // Getters

  //------------------------
  // Name: GetHighestPop
  // PreCondition: N/A
  // PostCondition: Returns the country with highest population
  //------------------------
   Country GetHighestPop();

   //------------------------
   // Name: GetHighestGDPSpent
   // PreCondition: N/A
   // PostCondition: Returns the country with highest GDP spent
   //------------------------
   Country GetHighestGDPSpent();

   //------------------------
   // Name: GetHighestLitRate
   // PreCondition: N/A
   // PostCondition: Returns the country with highest literacy rate
   //------------------------
   Country GetHighestLitRate();

   //------------------------
   // Name: GetCountryVec
   // PreCondition: N/A
   // PostCondition: Returns the vector of country objects
   //------------------------
   vector<Country> GetCountryVec();

   // Setters

   //------------------------
   // Name: SetHighestPop
   // PreCondition: N/A
   // PostCondition: Sets the variable m_highestPopulation
   //------------------------
   void SetHighestPop(Country highestPop);

   //------------------------
   // Name: SetHighestGDPSpent
   // PreCondition: N/A
   // PostCondition: Sets the variable m_highestGDPSpent
   //------------------------
   void SetHighestGDPSpent(Country highestGDPSpent);

   //------------------------
   // Name: SetHighestLitRate
   // PreCondition: N/A
   // PostCondition: Sets the variable m_highestLiteracyRate
   //------------------------
   void SetHighestLitRate(Country highestLitRate);

   //------------------------
   // Name: SetCountryVec
   // PreCondition: N/A
   // PostCondition: Sets the vector of country objects
   //------------------------
   void SetCountryVec(vector<Country> countries);

   //------------------------
   // Name: totalPopulation
   // PreCondition: N/A
   // PostCondition: Returns the calculated totalPopulation
   //------------------------
   long totalPopulation();

   //------------------------
   // Name: addCountry
   // PreCondition: N/A
   // PostCondition: Adds a country to the vector<Country>
   //------------------------
   void addCountry(Country country);

   //------------------------
   // Name: operator<<
   // PreCondition: N/A
   // PostCondition: Prints the Continent with its statistical data
   //------------------------
   friend ostream& operator<<(ostream &outStream, Continent continent);

 private:

  Country m_highestPopulation;
  Country m_highestGDPSpent;
  Country m_highestLiteracyRate;
  
  vector<Country> m_countriesInContinent;

};

#endif
