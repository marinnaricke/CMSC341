/***********************
 ** File:    MaxHeap.h
 ** Project: CMSC 341 Project 4, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/22/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the header for the MaxHeap Class
 **
 ************************/

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "Heap.h"

template<class T, int m_size>
  class MaxHeap: public Heap<T,m_size>
{
 public:

  // Default Constructor
  MaxHeap();

  // Copy Constructor
  MaxHeap(const Heap<T, m_size>& origHeap);

  //-------------------------------------------------------
  // Name: Remove
  // PreCondition: none
  // PostCondition: Returns a reference to the removed object
  //---------------------------------------------------------
  T& Remove();

  //-------------------------------------------------------
  // Name: Insert
  // PreCondition: none
  // PostCondition: Inserts the object into the m_currentIndex
  //---------------------------------------------------------
  void Insert(T& insertable);

  //-------------------------------------------------------
  // Name: PercolateUp 
  // PreCondition: none
  // PostCondition: Compares the item in index to its parents
  //---------------------------------------------------------
  void PercolateUp(int index);

  //-------------------------------------------------------
  // Name: PercolateDown
  // PreCondition: none
  // PostCondition: Compares the item in index to its children 
  //---------------------------------------------------------
  void PercolateDown(int index);

};

#include "MaxHeap.cpp"

#endif
