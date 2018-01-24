/***********************
 ** File:    Country.h
 ** Project: CMSC 341 Project 0, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    9/13/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the .h file for the country class
 **
 ************************/

#ifndef Country_H
#define Country_H

class Country
{
 public:

  // Default Constructor
  Country();

  // Non-Default Constructor
  Country(string name, long population, float litRate, float primFem,\
	  float primMale, float primTotal, float eduGDPSpent,\
	  float youthFem, float youthMale);

  //------------------------
  // Name: GetName
  // PreCondition: N/A
  // PostCondition: Returns the name of the country
  //------------------------
  string GetName();

  
  //------------------------
  // Name: GetPopulation
  // PreCondition: N/A
  // PostCondition: Returns the population
  //------------------------
  long GetPopulation();


  //------------------------
  // Name: GetLitRate
  // PreCondition: N/A
  // PostCondition: Returns the literacy rate
  //------------------------
  float GetLitRate();

  //------------------------
  // Name: GetPrimFem
  // PreCondition: N/A
  // PostCondition: Returns the primary completion for females
  //------------------------
  float GetPrimFem();

  //------------------------
  // Name: GetPrimMale
  // PreCondition: N/A
  // PostCondition: Returns the primary completion for males
  //------------------------
  float GetPrimMale();

  //------------------------
  // Name: GetPrimTotal
  // PreCondition: N/A
  // PostCondition: Returns the primary completion total
  //------------------------
  float GetPrimTotal();

  //------------------------
  // Name: GetEduGDPSpent
  // PreCondition: N/A
  // PostCondition: Returns the education GDP spent
  //------------------------
  float GetEduGDPSpent();

  //------------------------
  // Name: GetYouthLitRateFem
  // PreCondition: N/A
  // PostCondition: Returns the youth literacy rate for females
  //------------------------
  float GetYouthLitRateFem();

  //------------------------
  // Name: GetYouthLitRateMale
  // PreCondition: N/A
  // PostCondition: Returns the youth literacy rate for males
  //------------------------
  float GetYouthLitRateMale();
   
  // Setters for all variables

  //------------------------
  // Name: SetName
  // PreCondition: the name variable must be a string
  // PostCondition: Sets the private variable
  //------------------------
  void SetName(string name);

  //------------------------
  // Name: SetPopulation
  // PreCondition: the population must be of type long
  // PostCondition: Sets the private variable
  //------------------------
  void SetPopulation(long population);

  //------------------------
  // Name: SetLitRate
  // PreCondition: the literacy rate must be of type float
  // PostCondition: Sets the private variable
  //------------------------
  void SetLitRate(float literacyRate);

  
  //------------------------
  // Name: SetPrimFem
  // PreCondition: N/A
  // PostCondition: Sets the private varaible
  //------------------------
  void SetPrimFem(float primFem);


  //------------------------
  // Name: SetPrimMale
  // PreCondition: N/A
  // PostCondition: Sets the private variable
  //------------------------
  void SetPrimMale(float primMale);

  //------------------------
  // Name: SetPrimTotal
  // PreCondition: N/A
  // PostCondition: Sets the private variable
  //------------------------
  void SetPrimTotal(float primTotal);

  //------------------------
  // Name: SetEduGDPSpent
  // PreCondition: N/A
  // PostCondition: Sets the private variable
  //------------------------
  void SetEduGDPSpent(float eduGDPSpent);

  //------------------------
  // Name: SetYouthLitRateFem
  // PreCondition: N/A
  // PostCondition: Sets the private variable
  //------------------------
  void SetYouthLitRateFem(float youthLitRateFem);

  //------------------------
  // Name: SetYouthLitRateMale
  // PreCondition: N/A
  // PostCondition: Sets the private variable
  //------------------------
  void SetYouthLitRateMale(float youthLitRateMale);

 private:
  
  string m_name;       
  long m_population;
  float m_literacyRate;
  float m_primaryCompletionFemale;
  float m_primaryCompletionMale;
  float m_primaryCompletionTotal;
  float m_educationGDPSpent;
  float m_youthLitRateFem;
  float m_youthLitRateMale;

};

#endif
