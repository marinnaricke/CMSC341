/***********************
** File:    Driver.cpp
** Project: CMSC 341 Project 0, Fall 2016
** Author:  Marinna Ricketts-Uy 
** Date:    9/13/16
** Section: 02
** E-mail:  pd12778@umbc.edu
**
**  This file contains the main driver program for Project 0.
** This program reads in the two text files, stores the information for the 
** contients and countries, and prints the statistical data for each continent.
**
************************/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;

#include "Continent.h"
const int NUM_CONTINENTS = 6;   // total number of continents
const int NO_DATA_VALUE = -1.0; // the integer value for N/A

// readFromFiles
vector<Continent> readFromFiles(string file1,string file2);

// Helper IO Functions

// notApplicable
float notApplicable(string data);

int main()
{
  vector<Continent> world; // stores the continents

  world = readFromFiles("CountriesContinents.txt", "2013WorldBankEducationCensusData.txt");

  // Uses the overloaded operator to print out the continent objects

  for (int i = 0; i < NUM_CONTINENTS; i++)
    {
      cout << world[i] << endl;
    }

  return 0;
}

vector<Continent> readFromFiles(string file1,string file2)
{
  string oneLine, info;
  ifstream infile;
  long population;
  float litRate, primFem, primMale, primTotal, eduGDPSpent, youthFem, youthMale;
  string name,stats1,stats2,stats3,stats4,stats5,stats6,stats7,stats8;
  int numParse = 0;
  int counter = 0;
  vector<string> token;      // stores the information from first file
  vector<Continent> world;   // stores the continents
  vector<unsigned int> numInContinent; // stores the number of countries in continent plus the 3 header tokens (ex. Africa -- 51)
  vector<Country> countries; // stores the countries with data

  // Opening the CountriesContinents.txt file
  infile.open(file1.c_str(),ios_base::in);

  // Checking if file can be open
  if (infile.fail())
    {
      cout << "File 1 was not successfully open." << endl;
      exit(1);
    }
  else
    {
      // parse the data, done 6 times for each continent
      while (numParse != NUM_CONTINENTS)
	{
	  getline(infile,info,' ');
	  token.push_back(info);

	  // Store the name of the continent
	  world.push_back(Continent(info));

	  getline(infile,info,' ');
	  token.push_back(info);

	  getline(infile,info);
	  token.push_back(info);

	  // Use the number of countries in each continent to store
	  // the countries for each continent
	  counter = atoi(info.c_str());
	  numInContinent.push_back(counter + 3);
	  while (counter != 0)
	    {
	      getline(infile,info);
	      token.push_back(info);
	      counter--;
	    }

	  numParse++;
	}
    }

  infile.close();

  // Opening the 2013WorldBankEducationCensusData.txt file
  infile.open(file2.c_str(),ios_base::in);

  if (infile.fail())
    {
      cout << "File 2 was not successfully open." << endl;
      exit(1);
    }
  else
    {
      while(infile.good())
	{
	  // Grabs the line of headings that aren't needed
	  getline(infile,oneLine);

	  while(true)
	    {
	      getline(infile,oneLine);
	      
	      // Checks if it reached end of file
	      if (infile.eof())
		{
		  break;
		}

	      // Reads in one line at a time
	      istringstream istrm(oneLine);

	      istrm >> name;
	      istrm >> stats1;
	      istrm >> stats2;
	      istrm >> stats3;
	      istrm >> stats4;
	      istrm >> stats5;
	      istrm >> stats6;
	      istrm >> stats7;
	      istrm >> stats8;

	      // Convert the population to type long
	      population = atol(stats1.c_str());

	      litRate = notApplicable(stats2);
	      eduGDPSpent = notApplicable(stats3);
	      primTotal = notApplicable(stats4);
	      primMale = notApplicable(stats5);
	      primFem = notApplicable(stats6);
	      youthFem = notApplicable(stats7);
	      youthMale = notApplicable(stats8);
	      
	      // Store the information for each country into a Country object
	      countries.push_back(Country(name,population,litRate,primFem,\
					  primMale, primTotal, eduGDPSpent,\
					  youthFem, youthMale));	      
	    }
	}
    }

  // Mapping the countries to the correct continents
  // Using the token vector to place each country into the correct continent
  for (unsigned int x = 0; x < token.size(); x++)
    {
      for (unsigned int y = 0; y < countries.size(); y++)
	{
	  if (countries[y].GetName() == token[x])
	    {
	      if (x < (numInContinent[0]))
		{
		  world[0].addCountry(countries[y]);
		}
	      else if (x < (numInContinent[0] + numInContinent[1]))
		{
		  world[1].addCountry(countries[y]);
		}
	      else if (x < (numInContinent[0] + numInContinent[1] + numInContinent[2]))
		{
		  world[2].addCountry(countries[y]);
		}
	      else if (x < (numInContinent[0] + numInContinent[1] + numInContinent[2] + numInContinent[3]))
		{
		  world[3].addCountry(countries[y]);
		}
	      else if (x < (numInContinent[0] + numInContinent[1] + numInContinent[2] + numInContinent[3] + numInContinent[4]))
		{
		  world[4].addCountry(countries[y]);
		}
	      else 
		{
		  world[5].addCountry(countries[y]);
		}
	    }
	}
    }

  infile.close();
    
  return world;
}


// Helper IO Functions

// notApplicable
// Checks if the data is N/A, which is then read as a -1.0
float notApplicable(string data)
{
  if (data == "N/A")
    {
      return NO_DATA_VALUE;
    }
  else
    {
      return atof(data.c_str());
    }
}
