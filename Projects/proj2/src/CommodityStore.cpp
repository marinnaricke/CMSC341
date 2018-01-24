/***********************
 ** File:    CommodityStore.cpp
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the function definitions for
 **  the CommodityStore Class.
 **
 ************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <map>
using namespace std;

#include "CommodityStore.h"
#include "Commodity.h"
#include "Game.h"

// Default Constructor
CommodityStore::CommodityStore()
{
  //left blank
}

// loadCommodities
// Reads in the provided commodities text file and creates
//  an instance for each commodity which it stores in m_store.
void CommodityStore::loadCommodities(string filename)
{
  Commodity* commodObject;
  Commodity::COLOR commodColor;
  ifstream infile;
  string oneLine, name, color;

  // opening the file
  infile.open(filename.c_str(),ios_base::in);

  // Checking if file can be opened
  if (infile.fail())
    {
      cerr << "File could not be successfully opened." << endl;
      exit(1);
    }
  else
    {
      // parse the data, grab commodity name and color
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
          istrm >> color;

          if (color == "Purple")
            {
              commodColor = Commodity::PURPLE;
            }
          else if (color == "Red")
            {
              commodColor = Commodity::RED;
            }
          else if (color == "Orange")
            {
              commodColor = Commodity::ORANGE;
            }
          else if (color == "Black")
            {
              commodColor = Commodity::BLACK;
            }
	  else if (color == "Green")
	    {
	      commodColor = Commodity::GREEN;
	    }
	  else if (color == "Brown")
	    {
	      commodColor = Commodity::BROWN;
	    }
	  else
	    {
	      commodColor = Commodity::COLORLESS;
	    }

	  commodObject = new Commodity(name,commodColor);

	  // Store commodity object in m_store map
	  m_store[name] = commodObject;
	}
    }
  infile.close();
}

// getCommodity
// Returns a commodity instance given the commodities name
Commodity* CommodityStore::getCommodity(string name)
{
  Commodity* commod = m_store[name];

  return commod;
}
