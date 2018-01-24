/***********************
 ** File:    Country.cpp
 ** Project: CMSC 341 Project 0, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    9/13/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the definitions for the functions
 ** in the Country Class
 ************************/

#include <iostream>
using namespace std;

#include "Country.h"

// Default constructor
Country::Country()
{

}

// Non_Default Constructor
Country::Country(string name, long population, float litRate, float primFem,\
		 float primMale, float primTotal, float eduGDPSpent,\
		 float youthFem, float youthMale)
{
  m_name = name;
  m_population = population;
  m_literacyRate = litRate;
  m_primaryCompletionFemale = primFem;
  m_primaryCompletionMale = primMale;  
  m_primaryCompletionTotal = primTotal;
  m_educationGDPSpent = eduGDPSpent;
  m_youthLitRateFem = youthFem;
  m_youthLitRateMale = youthMale;
}

// Getters

// GetName
// Returns the name for the Country
string Country::GetName()
{
  return m_name;
}

// GetPopulation
// Returns the population for the Country
long Country::GetPopulation()
{
  return m_population;
}

// GetLitRate
// Returns the literacy rate for the Country
float Country::GetLitRate()
{
  return m_literacyRate;
}

// GetPrimFem
// Returns the primacy completion rate for females
float Country::GetPrimFem()
{
  return m_primaryCompletionFemale;
}

// GetPrimMale
// Returns the primary completion rate for males
float Country::GetPrimMale()
{
  return m_primaryCompletionMale;
}

// GetPrimTotal
// Returns the primary completion total 
float Country::GetPrimTotal()
{
  return m_primaryCompletionTotal;
}

// GetEduGDPSpent
// Returns the education GDP Spent
float Country::GetEduGDPSpent()
{
  return m_educationGDPSpent;
}

// GetYouthLitRateFem
// Returns the youth literacy rate for females
float Country::GetYouthLitRateFem()
{
  return m_youthLitRateFem;
}

// GetYouthLitRateMale
// Returns the youth literacy rate for males
float Country::GetYouthLitRateMale()
{
  return m_youthLitRateMale;
}

// Setters

// SetName
// Sets the Country's name
void Country::SetName(string name)
{
   m_name = name;
}

// SetPopulation
// Sets the Country's population
void Country::SetPopulation(long population)
{
  m_population = population;
}

// SetLitRate
// Sets the literacy rate 
void Country::SetLitRate(float literacyRate)
{
  m_literacyRate = literacyRate;
}

// SetPrimFem
// Sets the primary completion for females
void Country::SetPrimFem(float primFem)
{
  m_primaryCompletionFemale = primFem;
}

// SetPrimMale
// Sets the primary completion for males
void Country::SetPrimMale(float primMale)
{
  m_primaryCompletionMale = primMale;
}

// SetPrimTotal
// Sets the primary completion total
void Country::SetPrimTotal(float primTotal)
{
  m_primaryCompletionTotal = primTotal;
}

// SetEduGDPSpent
// Sets the education GDP spent
void Country::SetEduGDPSpent(float eduGDPSpent)
{
  m_educationGDPSpent = eduGDPSpent;
}

// SetYouthLitRateFem
// Sets the youth literacy rate for females
void Country::SetYouthLitRateFem(float youthLitRateFem)
{
  m_youthLitRateFem = youthLitRateFem;
}

// SetYouthLitRateMale
// Sets the youth literacy rate for males
void Country::SetYouthLitRateMale(float youthLitRateMale)
{
  m_youthLitRateMale = youthLitRateMale;
}
