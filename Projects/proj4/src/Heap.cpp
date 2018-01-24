/***********************
 ** File:    Heap.cpp
 ** Project: CMSC 341 Project 4, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/22/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the definitions for the Heap Class.
 **
 ************************/
#ifndef HEAP_CPP_
#define HEAP_CPP_

#include "Heap.h"
#include <iostream>

// Default Constructor
template<class T, int m_size>
Heap<T, m_size>::Heap() 
{	    
  m_array = new T[m_size];
  m_currentIndex = 1;
  m_heapSize = 1;
}

// Copy Constructor
template<class T, int m_size>
Heap<T, m_size>::Heap(const Heap<T, m_size>& origHeap) 
{
  m_array = new T[m_size];
  m_currentIndex = origHeap.m_currentIndex;
  m_heapSize = origHeap.m_heapSize;

  for (unsigned int i = 0; i < m_size; i++)
    {
      m_array[i] = origHeap.m_array[i];
    } 
}

// Contains
// Returns a boolean whether or not an item 
// was found in the heap. Uses the Find function.
template<class T, int m_size>
bool Heap<T, m_size>::Contains(const T& needle) const 
{
  if (Find(needle) == NULL)
    {
      return false;
    }
  else
    {
      return true;
    }
}	

// Find
// Returns a pointer to an object in the Heap.
// Simply returns NULL if the object wasn't found.
template<class T, int m_size>
const T* Heap<T, m_size>::Find(const T& needle) const 
{
  T* needlePointer = NULL;

  for (unsigned int i = 0; i < m_size; i++)
    {
      if (needle == m_array[i])
	{
	  needlePointer = &m_array[i];
	} 
    }
  
  return needlePointer;
}

// Remove
// This function is not defined for the parent class
template<class T, int m_size>
T& Heap<T, m_size>::Remove() 
{
  std::cerr << "Remove must be defined in MinHeap and MaxHeap" << std::endl;
  return m_array[0];
}

// Insert
// This function is not defined for the parent class
template<class T, int m_size>
void Heap<T, m_size>::Insert(T& insertable) 
{
  // left blank
}	

// PercolateUp
// This function is not defined for the parent class
template<class T, int m_size>
void Heap<T, m_size>::PercolateUp(int index) 
{
  // left blank
}

// PercolateDown
// This function is not defined for the parent class
template<class T, int m_size>
void Heap<T, m_size>::PercolateDown(int index) 
{
  // left blank
}

// printArray
// Used for testing purposes. Prints the contents
//  of m_array.
template<class T, int m_size>
void Heap<T,m_size>::printArray()
{
  for (int i = 0; i < m_heapSize; i++)
    {
      std::cout << m_array[i].GetKey() << std::endl;
    }
}

#endif /* HEAP_CPP_ */
