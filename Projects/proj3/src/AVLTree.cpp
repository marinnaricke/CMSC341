/***********************
 ** File:    AVLTree.cpp
 ** Project: CMSC 341 Project 3, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/1/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 **
 **
 ************************/
#ifndef AVLTREE_CPP
#define AVLTREE_CPP

#include "AVLTree.h"
#include <iostream>
#include <queue>

// Default Constructor
template <class T1, class T2>
AVLTree<T1,T2>::AVLTree()
{
  m_root = NULL;
}

// Non-Default Constructor
template <class T1, class T2>
AVLTree<T1,T2>::AVLTree(int treeId, AVLTreeBase::PrintOrder order)
{
  m_treeId = treeId;
  m_order = order;
  m_root = NULL;
}

// Destructor
template <class T1, class T2>
AVLTree<T1,T2>::~AVLTree()
{
  makeEmpty();
}

// setId
// Sets the treeId number
template <class T1, class T2>
void AVLTree<T1,T2>::setId(int treeId)
{
  m_treeId = treeId;
}

// getId
// Returns the treeId number
template <class T1, class T2>
int AVLTree<T1,T2>::getId()
{
  return m_treeId;
}

// setPrintOrder
// Sets the printOrder for the tree
template <class T1, class T2>
void AVLTree<T1,T2>::setPrintOrder( PrintOrder order)
{
  m_order = order;
}

// makeEmpty
// clears out the tree of all nodes
template <class T1, class T2>
void AVLTree<T1,T2>::makeEmpty()
{
  makeEmpty(m_root);
}

// insert
// Inserts nodes into the tree 
template <class T1, class T2>
void AVLTree<T1,T2>::insert(const T1& value, const T2& key)
{
  insert(value,key,m_root);
}

// insert
// Inserts nodes into the tree
template <class T1, class T2>
void AVLTree<T1,T2>::insert(const T1& value, const T2& key, \
			    AVLNode<T1,T2> * currentNode)
{
  AVLNode<T1,T2>* insertNode;

  // If there is nothing currently in the tree
  if (currentNode == NULL)
    {
      m_root = new AVLNode<T1,T2>(value,key,NULL,NULL,NULL);
    }
  else if( key < currentNode->getKey() ) 
    { 
      // Check if there is a left child
      if (currentNode->getLeftNode() != NULL)
	{
	  insert(value,key,currentNode->getLeftNode()); 
	}
      else
	{
	  insertNode = new AVLNode<T1,T2>(value,key,NULL,NULL,currentNode);
	  currentNode->setLeftNode(insertNode);
	  m_treeHeight++;
	}
    } 
  else if( currentNode->getKey() < key ) 
    { 
      // Check if there is a right child
      if (currentNode->getRightNode() != NULL)
	{
	  insert(value,key,currentNode->getRightNode());
	  m_treeHeight++;
	}
      else
	{
	  insertNode = new AVLNode<T1,T2>(value,key,NULL,NULL,currentNode);
	  currentNode->setRightNode(insertNode);
	}
    }
  else;  // Duplicate; do nothing
}

// balanceTree
// Uses rotations, if necessary, to balance the tree
template <class T1, class T2>
void AVLTree<T1,T2>::balanceTree()
{
  int rootBalance = nodeBalance(m_root);

  // Check if it is left subtree heavy
  if (rootBalance > 1)
    {
      // right child is the cause for the unbalance
      if(nodeBalance(m_root->getLeftNode()) < 0)
	{
	  // rotate the node left
	  rotateLeft(m_root->getLeftNode());
	}
      
      // rotate the root right
      rotateRight(m_root);
    }
  else if (rootBalance < -1)
    {
      if (nodeBalance(m_root->getRightNode()) > 0)
	{
	  rotateRight(m_root->getRightNode());
	}
      rotateLeft(m_root);
    }
}

// nodeBalance
// Calculates the balance of the leftNode - rightNode
template <class T1, class T2>
int AVLTree<T1,T2>::nodeBalance(AVLNode<T1,T2>* currentNode)
{
  int balanceInt = 0;

  if (m_treeHeight != 0)
    {
      balanceInt = getHeight(currentNode->getLeftNode()) -	\
	getHeight(currentNode->getRightNode());
    }
  return balanceInt;
}

// getHeight
// Calculates the height of a node in the tree
// and returns the integer value
template <class T1, class T2>
int AVLTree<T1,T2>::getHeight(AVLNode<T1,T2> *currentNode)
{
  //AVLNode<T1,T2>* compareNode = m_root;

  int nodeHeight = 0;

  if (currentNode != NULL)
    {
      // Calculate the height for the left and right children
      int leftHeight = getHeight(currentNode->getLeftNode());
      int rightHeight = getHeight(currentNode->getRightNode());

      nodeHeight = 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
      currentNode->setHeight(nodeHeight);
    }

  return nodeHeight;
}

// rotateLeft
// Deals with left rotation
template <class T1, class T2>
void AVLTree<T1,T2>::rotateLeft(AVLNode<T1,T2>* currentNode)
{
  // node to be rotated with
  AVLNode<T1,T2>* newNode = currentNode->getRightNode();
  
  currentNode->setRightNode(newNode->getLeftNode());
  newNode->setLeftNode(currentNode);

  // if currentNode is the root, newNode becomes the root
  if (currentNode->getParentNode() == NULL)
    {
      m_root = newNode;
      newNode->setParentNode(NULL);
    }
  else
    {
      if (currentNode->getParentNode()->getLeftNode() == currentNode)
	{
	  currentNode->getParentNode()->setLeftNode(newNode);
	}
      else
	{
	  currentNode->getParentNode()->setRightNode(newNode);
	}
      
      newNode->setParentNode(currentNode->getParentNode());
    }
  
  // newNode becomes the parent
  currentNode->setParentNode(newNode);
}

// rotateRight
// Deals with right rotation
template <class T1, class T2>
void AVLTree<T1,T2>::rotateRight(AVLNode<T1,T2>* currentNode)
{
  // node to rotate with
  AVLNode<T1,T2>* newNode = currentNode->getLeftNode();

  currentNode->setLeftNode(newNode->getRightNode());
  newNode->setRightNode(currentNode);

  if (currentNode->getParentNode() == NULL)
    {
      m_root = newNode;
      newNode->setParentNode(NULL);
    }
  else
    {
      if(currentNode->getParentNode()->getLeftNode() == currentNode)
	{
	  currentNode->getParentNode()->setLeftNode(newNode);
	}
      else
	{
	  currentNode->getParentNode()->setRightNode(newNode);
	}
      newNode->setParentNode(currentNode->getParentNode());
    }
  currentNode->setParentNode(newNode);
}

// printTree
// Prints the contents of the tree
template <class T1, class T2>
void AVLTree<T1,T2>::printTree(ostream& out) const
{
  printTree(m_root,out);
}

// printTree
// Prints the contents of the tree based
// on the given printOrder
template <class T1, class T2>
void AVLTree<T1,T2>::printTree(AVLNode<T1,T2>* currentNode, ostream & out) const
{
  if (currentNode != NULL)
    {
      if (m_order == AVLTreeBase::IN)
	{
	  // L -> N -> R
	  printTree(currentNode->getLeftNode(),out);
	  out << currentNode->getValue() << " ";
	  printTree(currentNode->getRightNode(),out);
	}
      else if (m_order == AVLTreeBase::PRE)
	{
	  // N -> L -> R
	  out << currentNode->getValue() << " ";
	  printTree(currentNode->getLeftNode(),out);
	  printTree(currentNode->getRightNode(),out);
	}
      else if (m_order == AVLTreeBase::POST)
	{
	  // L -> R -> N
	  printTree(currentNode->getLeftNode(),out);
	  printTree(currentNode->getRightNode(),out);
	  out << currentNode->getValue() << " ";
	}
      else if (m_order == AVLTreeBase::LEVEL) 
	{
	  queue<AVLNode<T1,T2>*> levelOrder;
	  
	  levelOrder.push(currentNode);

	  while (! levelOrder.empty())
	    {
	      // Process the front's children first
	      AVLNode<T1,T2>* treeNode = levelOrder.front();

	      out << treeNode->getValue() << " ";

	      // Store the left children
	      if ( treeNode->getLeftNode() != NULL )
		levelOrder.push(treeNode->getLeftNode());

	      // Store the right children
	      if ( treeNode->getRightNode() != NULL )
		levelOrder.push(treeNode->getRightNode());

	      // Pop the visited node
	      levelOrder.pop();
	    }
	}
    }
}

// print _range
// Prints the tree in a given range 
template <class T1, class T2>
void AVLTree<T1,T2>::print_range(std::ostream& out, int lowerBound, \
				 int upperBound)
{
  print_range(out,lowerBound,upperBound,m_root);
}

// print_range
// Prints the tree in a given range
template <class T1, class T2>
void AVLTree<T1,T2>::print_range(std::ostream& out,int lowerBound, \
				 int upperBound,AVLNode<T1,T2>* t)
{
  if (t == NULL)
    {
      return;
    }
  if (lowerBound < t->getKey())
    {
      print_range(out, lowerBound, upperBound, t->getLeftNode());
    }
  if (lowerBound <= t->getKey() && upperBound >= t->getKey())
    {
      out << t->getValue() << " ";
    }
  if (upperBound > t->getKey())
    {
      print_range(out,lowerBound,upperBound,t->getRightNode());
    }
}

#endif
