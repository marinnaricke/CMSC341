/***********************
 ** File:    Llama.cpp
 ** Project: CMSC 341 Project 1, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/4/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file has the function definitions for the Llama.cpp class. 
 **
 ************************/
#ifndef LLAMA_CPP
#define LLAMA_CPP

#include <iostream>
using namespace std;

#include "Llama.h"

// Default Constructor
// Creates a Llama Stack that holds one node
template <class T, int LN_SIZE>
Llama<T,LN_SIZE>::Llama()
{
  // Initialize member variables

  m_head = new LlamaNode<T,LN_SIZE>();
  m_current = m_head;
  m_llamaSize = 0;
  m_index = (LN_SIZE) - 1;
  m_hasExtra = false;
  m_numNodes = 1;
}

// Copy Constructor
template <class T, int LN_SIZE>
Llama<T,LN_SIZE>::Llama(const Llama<T,LN_SIZE>& other)
{
  // copy member variables
  m_llamaSize = other.m_llamaSize;
  m_index = other.m_index;
  m_topIndex = other.m_topIndex;
  m_hasExtra = other.m_hasExtra;
  m_numNodes = other.m_numNodes;

  m_head = new LlamaNode<T,LN_SIZE>();
  LlamaNode<T,LN_SIZE> *current = m_head;
  LlamaNode<T,LN_SIZE> *currentOther = other.m_head;

  // copy contents of topNode
  for (int i = 0; i < LN_SIZE; i++)
    {
      current->arr[i] = currentOther->arr[i]; 
    }

  // create and copy contents of each node
  while (currentOther->m_next != NULL)
    {
      current->m_next = new LlamaNode<T,LN_SIZE>();
      current = current->m_next;
      currentOther = currentOther->m_next;

      for (int i = 0; i < LN_SIZE; i++)
	{
	  current->arr[i] = currentOther->arr[i]; 
	}
    }

  // if an extra node exists, set m_current to correct node
  if (m_hasExtra == true)
    {
      m_current = m_head->m_next;
    }
  else
    {
      m_current = m_head;
    }
}

// ~Llama()
// Destructor for the Llama class
// All dynamically allocated memory associated with the host 
// object must be deallocated.
template <class T, int LN_SIZE>
Llama<T,LN_SIZE>::~Llama()
{
  LlamaNode<T,LN_SIZE> *current = m_head;
  LlamaNode<T,LN_SIZE> *next;

  // Traverse through linked list and delete nodes
  while(current != NULL)
    {
      next = current->m_next;
      delete current;
      current = next;
    }

  m_head = NULL;
  m_current = NULL;
}

// size()
// Returns the number of items in the Llama Stack
template <class T, int LN_SIZE>
int Llama<T, LN_SIZE>::size()
{
  return m_llamaSize;
}

// dump()
// used for debugging
// Prints out all pertinent information regarding the
// host Llama stack
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::dump()
{
  LlamaNode<T,LN_SIZE> *current = m_current;
  int numCount = m_topIndex;

  cerr << "\n***** Llama Stack Dump ******\n"
       << "LN_SIZE = " << LN_SIZE
       << "\n# of items in the stack = " << m_llamaSize 
       << endl;

  LlamaNode<T,LN_SIZE>::report();

  // Check if there is an extra node
  if (m_hasExtra == true)
    {
      cerr << "\nThis stack has an extra node: " << &m_head->arr << endl;
    }
  else
    {
      cerr << "\nThis stack does not have an extra node." << endl;
    }
  
  cerr << "\nStack contents,top to bottom" << endl;

  cerr << "-----" << &current->arr << "-----" << endl;
  while (numCount != LN_SIZE)
    {
      cout << current->arr[numCount] << endl;
      numCount++;
    }

  current = current->m_next;

  // Traverse through linked list 
  while (current != NULL)
    {
      cerr << "-----" << &current->arr << "-----" << endl;
      
      for (int i = 0; i < LN_SIZE; i++)
	{
	  cout << current->arr[i] << endl;
	}
      current = current->m_next;
    }
  
  cerr << "----- bottom of stack -----" << endl;
  cerr << "\n***************************" << endl;
}

// push()
// Adds data to the top of the stack.
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::push(const T& data)
{
  LlamaNode<T,LN_SIZE> *tempNode;

  // if array is filled, else continue filling
  if (m_index == -1)
    { 
      // use extra node next if available, else create new
      if (m_current != m_head)
	{
	  m_current = m_head;
	  m_hasExtra = false;
	  m_index = (LN_SIZE) - 1;
	  m_current->arr[m_index] = data;
	}
      else
	{
	  m_numNodes++;
	  tempNode = new LlamaNode<T,LN_SIZE>();
	  tempNode->m_next = m_head;
	  m_head = tempNode;
	  m_current = m_head;
	  m_index = (LN_SIZE) - 1;
	  m_current->arr[m_index] = data;
	}
    }
  else
    {
      m_current->arr[m_index] = data;
    }

  // keep track of top index
  m_topIndex = m_index;

  // move to next open index
  m_index--;
  m_llamaSize++;
}

// pop()
// removes and returns the item at the top of the Llama Stack.
// Should throw a LlamaUnderflow exception if the stack is empty
template <class T, int LN_SIZE>
T Llama<T, LN_SIZE>::pop()
{ 
  // throw a LlamaUnderflow exception if stack is empty
  if (size() == 0)
    {
      throw LlamaUnderflow("The stack is empty.");
    }

  // store top item
  T poppedItem = m_current->arr[m_topIndex];
  
  m_index = m_topIndex;
  m_topIndex++;

  // if array is completely empty
  if (m_topIndex == LN_SIZE)
    {
      m_hasExtra = true;
      m_current = m_current->m_next;
      m_index = -1;
      m_topIndex = 0;
    }
  // remove extra node if array size is half
  // the size of the LN_SIZE
  else if (m_topIndex >= ((LN_SIZE)/2) && m_hasExtra == true)
    {
      m_hasExtra = false;
      m_numNodes--;
      delete m_head;
      m_head = m_current;
    }

  m_llamaSize--;

  return poppedItem;
}

// dup()
// duplicates the top of the stack.
// If the stack is empty, dup() should throw a LlamaUnderFlow exception.
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::dup()
{
  // throw a LlamaUnderflow exception if stack is empty
  if (size() == 0)
    {
      throw LlamaUnderflow("The stack is empty.");
    }

  // copy top item
  T dupItem = m_current->arr[m_topIndex];
  push(dupItem);
}

// swap()
// exchanges the top two items of the stack.
// If there are fewer than two items in the stack, swap() should throw a
// LlamaUnderflow exception.
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::swap()
{
  LlamaNode<T,LN_SIZE> *current = m_current;
  LlamaNode<T,LN_SIZE> *next;

  // throw a LlamaUnderFlow exception if fewer than two items
  if (size() < 2)
    {
      throw LlamaUnderflow("The stack size is less than two items");
    }

  T topItem = current->arr[m_topIndex];
  T secondItem;
  int secondIndex = m_topIndex + 1;

  if (secondIndex == LN_SIZE)
    {
      // move to next node
      secondIndex = 0;
      next = current->m_next;
      secondItem = next->arr[secondIndex];
      
      // swap values
      current->arr[m_topIndex] = secondItem;
      next->arr[secondIndex] = topItem;
    }
  else
    {
      secondItem = current->arr[secondIndex];

      // swap values
      current->arr[m_topIndex] = secondItem;
      current->arr[secondIndex] = topItem;
    }
}

// rot()
// permutes the top three items of the stack.
// Note: "rot" is short for "rotate".
// If there are fewer than three items in the stack, rot() should throw a 
// LlamaUnderflow exception.
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::rot()
{
  LlamaNode<T,LN_SIZE> *current = m_current;
  LlamaNode<T,LN_SIZE> *next;

  // throw a LlamaUnderflow exception fewer than three items
  if (size() < 3)
    {
      throw LlamaUnderflow("The stack size is less than three.");
    }

  T topItem = current->arr[m_topIndex];
  T secondItem;
  int secondIndex = m_topIndex + 1;
  T thirdItem;
  int thirdIndex = m_topIndex + 2;
  
  if (secondIndex == LN_SIZE)
    {
      secondIndex = 0;
      thirdIndex = 1;

      next = current->m_next;
      secondItem = next->arr[secondIndex];
      thirdItem = next->arr[thirdIndex];
      
      // rotate values
      current->arr[m_topIndex] = thirdItem;
      next->arr[secondIndex] = topItem;
      next->arr[thirdIndex] = secondItem;
    }
  else if (thirdIndex == LN_SIZE)
    {
      secondItem = current->arr[secondIndex];
      thirdIndex = 0;
      
      next = current->m_next;
      thirdItem = next->arr[thirdIndex];
      
      // rotate values
      current->arr[m_topIndex] = thirdItem;
      current->arr[secondIndex] = topItem;
      next->arr[thirdIndex] = secondItem;
    }
  else 
    {
      secondItem = current->arr[secondIndex];
      thirdItem = current->arr[thirdIndex];

      // rotate values
      current->arr[m_topIndex] = thirdItem;
      current->arr[secondIndex] = topItem;
      current->arr[thirdIndex] = secondItem;
    }
}

// peek()
// returns the value of an item in the stack. The offset is used to determine
// which item is retrieved: peek(0) is the top of the stack, peek(1) is the 
// first item below the top,...If the offset is too large, peek() should 
// throw a LlamaUnderflow exception.
template <class T, int LN_SIZE>
T Llama<T, LN_SIZE>::peek(int offset) const
{
  LlamaNode<T,LN_SIZE> *current = m_head;
  int currentItem = 0;
  T peekItem;

  // throw a LlamaUnderflow exception
  if (offset >= m_llamaSize)
    {
      throw LlamaUnderflow("The offset is too large");
    }

  if ( (m_numNodes * LN_SIZE) > m_llamaSize)
    {
      int numDiff = (m_numNodes * LN_SIZE) - m_llamaSize;
      offset = offset + numDiff;
    }

  // Go through each node's array and find 
  // item that corresponds to the offset
  while (current != NULL)
    {
      for (int i = 0; i < LN_SIZE; i++)
        {
	  if (currentItem == offset)
	    {
	      peekItem = current->arr[i];
	    }	  	      
	  currentItem++;
        }
      current = current->m_next;
    }

  return peekItem;
}

// overloaded assignment operator
// should handle the case of self-assignement.
template <class T, int LN_SIZE>
const Llama<T,LN_SIZE>& Llama<T, LN_SIZE>::operator=(const Llama<T,LN_SIZE>& rhs)
{
  LlamaNode<T,LN_SIZE> *current = m_head;
  LlamaNode<T,LN_SIZE> *next;

  // empty out linked list
  while (current != NULL)
    {
      next = current->m_next;
      delete current;
      current = next;
    }
  
  m_head = NULL;
  m_current = NULL;
  
  m_head = new LlamaNode<T,LN_SIZE>();
  current = m_head;
  LlamaNode<T,LN_SIZE> *currentRhs = rhs.m_head;
  
  // copy the member variables
  m_llamaSize = rhs.m_llamaSize;
  m_index = rhs.m_index;
  m_topIndex = rhs.m_topIndex;
  m_hasExtra = rhs.m_hasExtra;
  m_numNodes = rhs.m_numNodes;
  
  for (int i = 0; i < LN_SIZE; i++)
    {
      current->arr[i] = currentRhs->arr[i];
    }

  // create and copy each node
  while (currentRhs->m_next != NULL)
    {
      current->m_next = new LlamaNode<T,LN_SIZE>();
      current = current->m_next;
      currentRhs = currentRhs->m_next;

      for (int i = 0; i < LN_SIZE; i++)
        {
          current->arr[i] = currentRhs->arr[i];
        }
    }

  if (m_hasExtra == true)
    {
      m_current = m_head->m_next;
    }
  else
    {
      m_current = m_head;
    }

  return *this;
}

#endif
