/***********************
 ** File:    AVLForest.h
 ** Project: CMSC 341 Project 3, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/1/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 **
 **
 ************************/

#include "AVLForest.h"
#include "AVLTreeBase.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

// Default Constructor
AVLForest::AVLForest()
{
  // Left Blank
}

// Destructor
AVLForest::~AVLForest()
{
  // Left Blank
}

// insert
// Inserts the tree if not already in the vector 
// or adds the data to the tree 
void AVLForest::insert(std::string line)
{
  istringstream ss(line);
  string token, data, number;
  int treeId, dataType, numType, printInt, numInt;
  float numFloat;
  std::vector<int>::iterator it;

  getline(ss,token,',');
  treeId = atoi(token.c_str());

  //Checking if tree is in vector
  it = find(m_treeIdVector.begin(), m_treeIdVector.end(), treeId);

  // check if tree not already in vector
  if(it == m_treeIdVector.end())
    {
      // Store treeId
      m_treeIdVector.push_back(treeId);

      // create a new tree and add it to the vector
      getline(ss,token, ',');
      printInt = atoi(token.c_str());
      AVLTreeBase::PrintOrder printOrder; 

      if (printInt == 0)
	{
	  printOrder = AVLTreeBase::IN;
	}
      else if (printInt == 1)
	{
	  printOrder = AVLTreeBase::PRE;
	}
      else if (printInt == 2)
	{
	  printOrder = AVLTreeBase::POST;
	}
      else
	{
	  printOrder = AVLTreeBase::LEVEL;
	}

      getline(ss,token,',');
      dataType = atoi(token.c_str());

      getline(ss,token,',');
      numType = atoi(token.c_str());

      // character and integer
      if(dataType == 0 && numType == 0)
     	{
	  AVLTreeBase *treeBase = new AVLTree<char,int>(treeId,printOrder);
	  m_treeVector.push_back(treeBase);
	  m_treeTypes.push_back("char & int");
     	}
      // character and float
      else if(dataType == 0 && numType == 1)
     	{
	  AVLTreeBase *treeBase = new AVLTree<char,float>(treeId,printOrder);
	  m_treeVector.push_back(treeBase);
	  m_treeTypes.push_back("char & float");
     	}
      // string and integer
      else if(dataType == 1 && numType == 0)
      	{
	  AVLTreeBase *treeBase = new AVLTree<string,int>(treeId,printOrder);
	  m_treeVector.push_back(treeBase);
	  m_treeTypes.push_back("string & int");
      	}
      // string and float
      else if(dataType == 1 && numType == 1)
      	{
	  AVLTreeBase *treeBase = new AVLTree<string,float>(treeId,printOrder);
	  m_treeVector.push_back(treeBase);
	  m_treeTypes.push_back("string & float");
     	}
      else
      	{
	  cerr << "Invalid Case for inserting tree" << endl;
	  exit(1);
      	}
    }
  else
    {
      // tree is in vector
      // we can proceed with insert

      // Split the line to grab data

      // Data Value
      getline(ss,token, ',');
      data = token;
      
      // Number Value
      getline(ss,token, ',');
      number = token;
      
      int index;
      
      // find the treeIndex 
      for (unsigned int i = 0; i < m_treeIdVector.size(); i++)
	{
	  if (m_treeIdVector[i] == treeId)
	    {
	      index = i;
	    }
	}

      AVLTreeBase* treeBase = m_treeVector[index];

      // insert data, number pair
      
      if(m_treeTypes[index] == "char & int")
     	{ 
	  // convert number to int
	  
	  numInt = atoi(number.c_str());

	  AVLTree<char,int>* tree = static_cast<AVLTree<char,int>*>(treeBase);

	  tree->insert(*(data.c_str()),numInt);
	  
	  // Re-Balanace Tree after insertion
	  tree->balanceTree();
     	}
      else if(m_treeTypes[index] == "char & float")
	{
	  // convert numVal to float
	  numFloat = atof(number.c_str());

	  AVLTree<char,float>* tree = static_cast<AVLTree<char,float>*>(treeBase);

	  tree->insert(*(data.c_str()),numFloat);
	  
	  // Re-Balanace Tree after insertion
	  tree->balanceTree();
      	}
      else if(m_treeTypes[index] == "string & int")
      	{
	  // convert numVal to int
	  numInt = atoi(number.c_str());

	  AVLTree<string,int>* tree = static_cast<AVLTree<string,int>*>(treeBase);
	  tree->insert(data,numInt);

	  // Re-Balanace Tree after insertion
	  tree->balanceTree();
     	}
      else if(m_treeTypes[index] == "string & float")
      	{
	  // convert numVal to float
	  numFloat = atof(number.c_str());

	  AVLTree<string,float>* tree = static_cast<AVLTree<string,float>*>(treeBase);
	  tree->insert(data,numFloat);

	  // Re-Balanace Tree after insertion
	  tree->balanceTree();
	}
      else
      	{
	  // invalid case
	  cerr << "Invalid Case for inserting into tree" << endl;
	  exit(1);
      	}
    }
}

// print_range
// Uses the given string to print out a range from a given tree
void AVLForest::print_range(std::ostream& out, std::string line)
{
  istringstream ss(line);
  string token;
  int index,treeId, lowerB, upperB;

  // Get the data from the line
  getline(ss,token,',');
  treeId = atoi(token.c_str());

  getline(ss,token,',');
  lowerB = atoi(token.c_str());

  getline(ss,token,',');
  upperB = atoi(token.c_str());

  // find the treeIndex 
  for (unsigned int i = 0; i < m_treeIdVector.size(); i++)
    {
      if (m_treeIdVector[i] == treeId)
	{
	  index = i;
	}
    }
  
  AVLTreeBase* treeBase = m_treeVector[index];

  // create the tree pointer depending on data types
  if(m_treeTypes[index] == "char & int")
    {
      AVLTree<char,int>* tree = static_cast<AVLTree<char,int>*>(treeBase);
      tree->print_range(out,lowerB,upperB);
      out << endl;
    }
  else if(m_treeTypes[index] == "char & float")
    {
      AVLTree<char,float>* tree = static_cast<AVLTree<char,float>*>(treeBase);
      tree->print_range(out,lowerB,upperB);
      out << endl;
    }
  else if(m_treeTypes[index] == "string & int")
    {
      AVLTree<string,int>* tree = static_cast<AVLTree<string,int>*>(treeBase);
      tree->print_range(out,lowerB,upperB);
      out << endl;
    }
  else if(m_treeTypes[index] == "string & float")
    {
      AVLTree<string,float>* tree = static_cast<AVLTree<string,float>*>(treeBase);
      tree->print_range(out,lowerB,upperB);     
      out << endl;
    }
}


// operator <<
// Overloaded operator to print out the AVLForest 
std::ostream& operator << (std::ostream& out, AVLForest& avlForest)
{
  // print all trees
  vector<AVLTreeBase*> forest = avlForest.m_treeVector;
  vector<string> treeTypes = avlForest.m_treeTypes;
  
  // iterate over vector of trees
  for(unsigned int i = 0; i < forest.size(); i++)
    {
      if(treeTypes[i] == "char & int" )
	{
	  AVLTree<char,int>* tree = static_cast<AVLTree<char,int>*>(forest[i]);
	  tree->printTree(out);
	  out << endl;
	}
      else if(treeTypes[i] == "char & float")
	{
	  AVLTree<char,float>* tree = static_cast<AVLTree<char,float>*>\
	    (forest[i]);
	  tree->printTree(out);
	  out << endl;
	}
      else if(treeTypes[i] == "string & int")
	{
	  AVLTree<string,int>* tree = static_cast<AVLTree<string,int>*>\
	    (forest[i]);
	  tree->printTree(out);
	  out << endl;
	}
      else if(treeTypes[i] == "string & float")
	{
	  AVLTree<string,float>* tree = static_cast<AVLTree<string,float>*>\
	    (forest[i]);
	  tree->printTree(out);
	  out << endl;
	}
      else
	{
	  cerr << "Invalid Case for printing" << endl;
	}
    }
  return out;
}

