/***********************
 ** File:    AVLNode.cpp
 ** Project: CMSC 341 Project 3, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/1/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 **
 **
 ************************/
#ifndef AVLNODE_CPP
#define AVLNODE_CPP

#include "AVLNode.h"
#include <iostream>

// Default Constructor
template <class T1, class T2>
AVLNode<T1,T2>::AVLNode()
{
  m_left = NULL;
  m_right = NULL;
  m_parent = NULL;
  m_nodeHeight = 0;
}

// Non-Default Constructor
template <class T1, class T2>
AVLNode<T1,T2>::AVLNode(const T1& value, const T2& key,AVLNode<T1,T2> *left,\
			AVLNode<T1,T2> *right, AVLNode<T1,T2> *parent)
{
  m_value = value;
  m_key = key;
  m_left = left;
  m_right = right;
  m_parent = parent;
  m_nodeHeight = 0;
}

// setHeight
// Sets the height for the node
template <class T1, class T2>
void AVLNode<T1,T2>::setHeight(int height)
{
  m_nodeHeight = height;
}

// getKey
// Returns the key for the node
template <class T1, class T2>
T2 AVLNode<T1,T2>::getKey()
{
  return m_key;
}

// getValue
// Returns the value for the node
template <class T1, class T2>
T1 AVLNode<T1,T2>::getValue()
{
  return m_value;
}

// getLeftNode
// Returns the left child
template <class T1, class T2>
AVLNode<T1,T2>* AVLNode<T1,T2>::getLeftNode()
{
  return m_left;
}

// getRightNode
// Returns the right child
template <class T1, class T2>
AVLNode<T1,T2>* AVLNode<T1,T2>::getRightNode()
{
  return m_right;
}

// setLeftNode
// Sets the left child
template <class T1, class T2>
void AVLNode<T1,T2>::setLeftNode(AVLNode<T1,T2> * left)
{
  m_left = left;
}

// setRightNode
// Sets the right child
template <class T1, class T2>
void AVLNode<T1,T2>::setRightNode(AVLNode<T1,T2> * right)
{
  m_right = right;
}

// getParentNode
// Returns the parent
template <class T1, class T2>
AVLNode<T1,T2>* AVLNode<T1,T2>::getParentNode()
{
  return m_parent;
}

// setParentNode
// Sets the parent
template <class T1, class T2>
void AVLNode<T1,T2>::setParentNode(AVLNode<T1,T2> * parent)
{
  m_parent = parent;
}

#endif 
