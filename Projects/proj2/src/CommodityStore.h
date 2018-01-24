/***********************
 ** File:    CommodityStore.h
 ** Project: CMSC 341 Project 2, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/18/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the prototypes and member variables
 **  for the CommodityStore Class.
 **
 ************************/

#ifndef COMMODITYSTORE_H
#define COMMODITYSTORE_H

#include <map>
#include <string>

using namespace std;

#include "Commodity.h"

class CommodityStore
{
 public:
 
  // Default Constructor
  CommodityStore();

  //-------------------------------------------------------
  // Name: loadCommodities
  // PreCondition:  filename must be of type string
  // PostCondition: Reads from the file and creates an instance
  //---------------------------------------------------------
  void loadCommodities(string filename);

  //-------------------------------------------------------
  // Name: getCommodity
  // PreCondition:  none
  // PostCondition: Returns the commodity name
  //---------------------------------------------------------
  Commodity* getCommodity(string name);

 private:
  
  map<string, Commodity*> m_store; // maps an instance of each commodity

};

#endif
