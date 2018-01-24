/***********************
 ** File:    Heap.h
 ** Project: CMSC 341 Project 4, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/22/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This is the header file for the Heap Class
 **
 ************************/

#ifndef HEAP_H_
#define HEAP_H_

#include "PinHit.h"

template<class T, int m_size> 
  class Heap
{
 public:

  // Default Constructor
  Heap();

  // Copy Constructor
  Heap(const Heap<T, m_size>& origHeap);

  //-------------------------------------------------------
  // Name: Contains
  // PreCondition: none
  // PostCondition: Returns a boolean
  //---------------------------------------------------------
  bool Contains(const T& needle) const;

  //-------------------------------------------------------
  // Name: Find
  // PreCondition: none
  // PostCondition: Returns a pointer to an address
  //---------------------------------------------------------
  const T* Find(const T& needle) const;

  //-------------------------------------------------------
  // Name: Remove
  // PreCondition: none
  // PostCondition: Removes an item from the heap
  //---------------------------------------------------------
  virtual T& Remove();

  //-------------------------------------------------------
  // Name: Insert
  // PreCondition: none
  // PostCondition: Inserts an item into the heap
  //---------------------------------------------------------
  virtual void Insert(T& insertable);

  //-------------------------------------------------------
  // Name: PercolateUp
  // PreCondition: none
  // PostCondition: Moves an item up the heap
  //---------------------------------------------------------
  virtual void PercolateUp(int index);

  //-------------------------------------------------------
  // Name: PercolateDown
  // PreCondition: none
  // PostCondition: Moves an item down the heap
  //---------------------------------------------------------
  virtual void PercolateDown(int index);
  
  // student-made functions below

  // **** For testing purposes ****
  //-------------------------------------------------------
  // Name: printArray
  // PreCondition: none
  // PostCondition: Prints the contents of m_array
  //---------------------------------------------------------
  void printArray();
  
 protected:
  
  T* m_array; 

  int m_currentIndex;  // keeps track of next available index

  int m_heapSize; // keeps track of the size of the heap
};

#include "Heap.cpp"
#endif /* HEAP_H_ */
