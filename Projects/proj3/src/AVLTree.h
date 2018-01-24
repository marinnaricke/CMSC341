/***********************
 ** File:    AVLTree.h
 ** Project: CMSC 341 Project 3, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/1/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 **
 **
 ************************/
#ifndef AVLTREE_H
#define AVLTREE_H

using namespace std;

#include "AVLTreeBase.h"
#include "AVLNode.h"
#include <fstream>
#include <iostream>

template <class T1, class T2>
class AVLTree: public AVLTreeBase
{
 public:
  
  // Default Constructor
  AVLTree();

  // Non-Default Constructor
  AVLTree(int treeId, PrintOrder order);

  // Destructor 
  ~AVLTree();

  //-------------------------------------------------------
  // Name: setId
  // PreCondition: none
  // PostCondition: Sets the id number for the tree
  //---------------------------------------------------------
  void setId(int treeId);

  //-------------------------------------------------------
  // Name: getId
  // PreCondition: none
  // PostCondition: Returns the treeId number 
  //---------------------------------------------------------
  int getId();

  //-------------------------------------------------------
  // Name: setOrder
  // PreCondition: none
  // PostCondition: Sets the print order for the tree
  //---------------------------------------------------------
  void setPrintOrder( PrintOrder order);

  //-------------------------------------------------------
  // Name: makeEmpty
  // PreCondition:  none
  // PostCondition: Clears out the AVLTree
  //---------------------------------------------------------
  void makeEmpty();

  //-------------------------------------------------------
  // Name: insert
  // PreCondition: none
  // PostCondition: Inserts a node into the tree 
  //---------------------------------------------------------
  void insert(const T1& value, const T2& key);

  //-------------------------------------------------------
  // Name: balanceTree
  // PreCondition:  none
  // PostCondition: Balances the tree
  //---------------------------------------------------------
  void balanceTree();

  //-------------------------------------------------------
  // Name: nodeBalance
  // PreCondition:  none
  // PostCondition: Returns an integer
  //---------------------------------------------------------
  int nodeBalance(AVLNode<T1,T2>* t);

  //-------------------------------------------------------
  // Name: findHeight
  // PreCondition:  none
  // PostCondition: Returns the height of the node
  //---------------------------------------------------------
  int getHeight(AVLNode<T1,T2>* t);
  
  //-------------------------------------------------------
  // Name: rotateLeft
  // PreCondition:  none
  // PostCondition: Left Rotates the tree around a node
  //---------------------------------------------------------
  void rotateLeft(AVLNode<T1,T2>* currentNode);

  //-------------------------------------------------------
  // Name: rotateRight
  // PreCondition:  none
  // PostCondition: Right Rotates the tree around a node
  //---------------------------------------------------------
  void rotateRight(AVLNode<T1,T2>* currentNode);
  
  //-------------------------------------------------------
  // Name: printTree
  // PreCondition:  none
  // PostCondition: Prints the tree in a given order
  //---------------------------------------------------------
  void printTree(std::ostream& out) const;

  //-------------------------------------------------------
  // Name: print_range
  // PreCondition: none
  // PostCondition: Prints the tree with given range
  //---------------------------------------------------------
  void print_range(std::ostream & out, int lowerBound, int upperBound);

 private:

  AVLNode<T1,T2>* m_root; // root of the tree
  int m_treeId;           // treeid number   
  int m_treeHeight;       // height of the tree
  PrintOrder m_order;     // print order for the tree

  //-------------------------------------------------------
  // Name: makeEmpty
  // PreCondition: none
  // PostCondition: Clears out the AVLTree
  //---------------------------------------------------------
  void makeEmpty( AVLNode<T1,T2> *& t);

  //-------------------------------------------------------
  // Name: balanceTree
  // PreCondition: none
  // PostCondition: Balances the tree 
  //---------------------------------------------------------
  void balanceTree(AVLNode<T1,T2> * t);

  //-------------------------------------------------------
  // Name: insert
  // PreCondition: none
  // PostCondition: Inserts a node into the tree 
  //---------------------------------------------------------
  void insert(const T1& value, const T2& key,AVLNode<T1,T2> *currentNode);
  
  //-------------------------------------------------------
  // Name: printTree
  // PreCondition:  none
  // PostCondition: Prints the tree in a given order
  //---------------------------------------------------------
  void printTree(AVLNode<T1,T2>* t, std::ostream& out) const;
  
  //-------------------------------------------------------
  // Name: print_range
  // PreCondition: none
  // PostCondition: Prints tree in given range
  //---------------------------------------------------------
  void print_range(std::ostream& out,int lowerBound, int upperBound,\
		   AVLNode<T1,T2>* t);
};

#include "AVLTree.cpp"

#endif
