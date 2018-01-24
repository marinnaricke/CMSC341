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

#ifndef _AVLFOREST_H_
#define _AVLFOREST_H_

/* include your tree implementation  */
#include "AVLTree.h"
#include <vector>
#include <string>
#include <iostream>

class AVLForest
{
  // vector of trees
  // we use a non-templated base class so we can hold all template instantiations
  std::vector<AVLTreeBase*> m_treeVector;

  // other data memebers
  
public:

  // Default Constructor
  AVLForest();
  
  // Destructor
  ~AVLForest();

  //-------------------------------------------------------
  // Name: insert
  // PreCondition:  
  // PostCondition: 
  //---------------------------------------------------------
  void insert(std::string);

  //-------------------------------------------------------
  // Name: print_range
  // PreCondition: none
  // PostCondition: Prints specific range of nodes from tree
  //---------------------------------------------------------
  void print_range(std::ostream&, std::string);
  
  //-------------------------------------------------------
  // Name: operator <<
  // PreCondition: none
  // PostCondition: Pretty prints the AVLForest
  //---------------------------------------------------------
  friend std::ostream& operator << (std::ostream&, AVLForest& forest);

  // other member functions

 private:
  
  std::vector<int> m_treeIdVector; // holds the treeId numbers
  std::vector<string> m_treeTypes; // holds the tree data types

};

#endif /* _AVLFOREST_H_ */
