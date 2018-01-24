/***********************
 ** File:    Continent.cpp
 ** Project: CMSC 341 Project 0, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    9/13/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the .cpp file for the Continent class and 
 ** contains the definitions for the functions of the class.
 **
 ************************/

#include <iostream>
using namespace std;

#include "Continent.h"

// Default Constructor
Continent::Continent()
{
  // left blank
}

// Non-default Constructor
Continent::Continent(string name)
{
  SetName(name);
}

// Getters

// GetHighestPop
// Looks at the population for each country within the continent
// and returns the country with the highest population
Country Continent::GetHighestPop()
{
  m_highestPopulation = m_countriesInContinent[0];

  for (unsigned int i = 0; i < m_countriesInContinent.size(); i++)
    {
      if (m_countriesInContinent[i].GetPopulation() > 
	  m_highestPopulation.GetPopulation())
	{
	  m_highestPopulation = m_countriesInContinent[i];
	}
    }

  return m_highestPopulation;
}

// GetHighestGDPSpent
// Looks at the GDP Spent for each country 
// and returns the country with the highest GDP spent
Country Continent::GetHighestGDPSpent()
{
  m_highestGDPSpent = m_countriesInContinent[0];

  for (unsigned int i = 0; i < m_countriesInContinent.size(); i++)
    {
      if (m_countriesInContinent[i].GetEduGDPSpent() > 
	  m_highestGDPSpent.GetEduGDPSpent())
	{
	  m_highestGDPSpent = m_countriesInContinent[i];
	}
    }

  return m_highestGDPSpent;
}

// GetHighestLitRate
// Looks at the literacy rate for each country
// and returns the country with the highest
Country Continent::GetHighestLitRate()
{
  m_highestLiteracyRate = m_countriesInContinent[0];

  for (unsigned int i = 0; i < m_countriesInContinent.size(); i++)
    {
      if (m_countriesInContinent[i].GetLitRate() > 
	  m_highestLiteracyRate.GetLitRate())
	{
	  m_highestLiteracyRate = m_countriesInContinent[i];
	}
    }

  return m_highestLiteracyRate;
}

// GetCountryVec
// Returns the vector of countries
vector<Country> Continent::GetCountryVec()
{
  return m_countriesInContinent;
}

// Setters

// SetHighestPop
// Sets the country with the highest population
void Continent::SetHighestPop(Country highestPop)
{
  m_highestPopulation = highestPop;
}

// SetHighestGDPSpent
// Sets the country with the highest GDP Spent
void Continent::SetHighestGDPSpent(Country highestGDPSpent)
{
  m_highestGDPSpent = highestGDPSpent;
}

// SetHighestLitRate
// Sets the country with the highest literacy rate
void Continent::SetHighestLitRate(Country highestLitRate)
{
  m_highestLiteracyRate = highestLitRate;
}

// SetCountryVec
// Sets the vector of countries for the continent
void Continent::SetCountryVec(vector<Country> countries)
{
  m_countriesInContinent = countries;
}

// totalPopulation
// Adds up the population of each country in the continent
// and the total is returned
long Continent::totalPopulation()
{
  long totalPopulation = 0;

  for (unsigned int i = 0; i < m_countriesInContinent.size(); i++)
    {
      totalPopulation += m_countriesInContinent[i].GetPopulation();
    }
  
  return totalPopulation;
}

// addCountry
// Adds a country to the vector of countries for the continent
void Continent::addCountry(Country country)
{
  m_countriesInContinent.push_back(country);
}

// Overloaded Operator <<
// Used to print out the continent object 
ostream& operator<<(ostream &outStream, Continent continent)
{
  Country highestLitRate = continent.GetHighestLitRate();
  Country highestGDPSpent = continent.GetHighestGDPSpent();
  Country highestPop = continent.GetHighestPop();

  outStream << continent.GetName() << "\n" << " Population: " 
	    << continent.totalPopulation() 
	    << "\n Country with highest literacy rate: " 
	    << highestLitRate.GetName() << " with a population of " 
	    << highestLitRate.GetPopulation() << " and a literacy rate of " 
	    << highestLitRate.GetLitRate()
	    << "\n Country with highest GDP expenditure on education: "
	    << highestGDPSpent.GetName()<< " with a population of "
	    << highestGDPSpent.GetPopulation() << " and a literacy rate of "
	    << highestGDPSpent.GetLitRate() 
	    << "\n Country with highest population: " 
	    << highestPop.GetName() << " with a population of "
	    << highestPop.GetPopulation() << " and a literacy rate of " 
	    << highestPop.GetLitRate() << endl;

  return outStream;
}
