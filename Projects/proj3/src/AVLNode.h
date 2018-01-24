/***********************
 ** File:    AVLNode.h
 ** Project: CMSC 341 Project 3, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/1/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 **
 **
 ************************/

#ifndef AVLNODE_H
#define AVLNODE_H

template <class T1, class T2>
class AVLNode
{
 public:

  // Default Constructor
  AVLNode();

  // Non-Default Constructor
  AVLNode(const T1& value, const T2& key, AVLNode<T1,T2> *left, \
	  AVLNode<T1,T2> *right, AVLNode *parent);
  
  //-------------------------------------------------------
  // Name: setHeight
  // PreCondition: none
  // PostCondition: Sets the height of the node
  //---------------------------------------------------------
  void setHeight(int height);

  //-------------------------------------------------------
  // Name: getKey
  // PreCondition: none
  // PostCondition: Returns the key
  //---------------------------------------------------------
  T2 getKey();

  //-------------------------------------------------------
  // Name: getValue
  // PreCondition: none
  // PostCondition: Returns the value
  //---------------------------------------------------------
  T1 getValue();

  //-------------------------------------------------------
  // Name: getLeftNode
  // PreCondition: none
  // PostCondition: Returns the left node
  //---------------------------------------------------------
  AVLNode<T1,T2>* getLeftNode();

  //-------------------------------------------------------
  // Name: getRightNode
  // PreCondition: none
  // PostCondition: Returns the right node
  //---------------------------------------------------------
  AVLNode<T1,T2>* getRightNode();

  //-------------------------------------------------------
  // Name: setLeftNode
  // PreCondition: none
  // PostCondition: Sets the left node
  //---------------------------------------------------------
  void setLeftNode(AVLNode<T1,T2>* left);

  //-------------------------------------------------------
  // Name: setRightNode
  // PreCondition: none
  // PostCondition: Sets the right node
  //---------------------------------------------------------
  void setRightNode(AVLNode<T1,T2>* right);

  //-------------------------------------------------------
  // Name: getParentNode
  // PreCondition: none
  // PostCondition: Returns the parent node
  //---------------------------------------------------------
  AVLNode<T1,T2>* getParentNode();

  //-------------------------------------------------------
  // Name: setParentNode
  // PreCondition: none
  // PostCondition: Sets the parent node
  //---------------------------------------------------------
  void setParentNode(AVLNode<T1,T2>* parent);

 private:
  T1 m_value;
  T2 m_key;
  AVLNode* m_left;
  AVLNode* m_right;
  AVLNode* m_parent;
  int m_nodeHeight;
};

#include "AVLNode.cpp"

#endif
