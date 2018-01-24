/***********************
 ** File:    MinHeap.h
 ** Project: CMSC 341 Project 4, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/22/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This is the header file for the MinHeap Class
 **
 ************************/
#ifndef MINHEAP_H
#define MINHEAP_H

#include "Heap.h"

template<class T, int m_size>
  class MinHeap: public Heap<T,m_size>
{
 public:
  
  // Default Constructor
  MinHeap();
  
  // Copy Constructor
  MinHeap(const Heap<T, m_size>& origHeap);

  //-------------------------------------------------------
  // Name: Insert
  // PreCondition: none
  // PostCondition: Inserts the insertable into m_currentIndex
  //---------------------------------------------------------
  void Insert(T& insertable);

  //-------------------------------------------------------
  // Name: Remove
  // PreCondition: none
  // PostCondition: Removes the item in first index
  //---------------------------------------------------------
  T& Remove();

  //-------------------------------------------------------
  // Name: PercolateUp
  // PreCondition: index must be an integer
  // PostCondition: Compares the item in index to its parent
  //---------------------------------------------------------
  void PercolateUp(int index);

  //-------------------------------------------------------
  // Name: PercolateDown
  // PreCondition: index must be an integer
  // PostCondition: Compares the item in index to its children
  //---------------------------------------------------------
  void PercolateDown(int index);
};

#include "MinHeap.cpp"

#endif
