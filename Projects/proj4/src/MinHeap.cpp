/***********************
 ** File:    MinHeap.cpp
 ** Project: CMSC 341 Project 4, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/22/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the defintions for the MinHeap Class
 **
 ************************/
#ifndef MINHEAP_CPP
#define MINHEAP_CPP

#include "MinHeap.h"

// Default Constructor
// Calls the Heap Constructor
template<class T, int m_size>
MinHeap<T, m_size>::MinHeap(): Heap<T,m_size>()
{

}

// Copy Constructor
// Calls the Heap Copy Constructor
template<class T, int m_size>
MinHeap<T, m_size>::MinHeap(const Heap<T, m_size>& origHeap): \
  Heap<T,m_size>(origHeap)
{

}

// Insert
// Inserts the item into the m_currentIndex of the heap.
// Calls PercolateUp().
template<class T, int m_size>
void MinHeap<T, m_size>::Insert(T& insertable)
{
  // Always inserting into the last open index
  this->m_array[this->m_currentIndex] = insertable;

  if (this->m_currentIndex != 1)
    {
      PercolateUp(this->m_currentIndex);
    }

  this->m_currentIndex++;
  this->m_heapSize++;
}

// Remove
// Removes the item in the first index of the heap.
// Calls PercolateDown(). Returns a reference to the
//  item that was removed.
template<class T, int m_size>
T& MinHeap<T, m_size>::Remove()
{
  // Always going to remove the first item in the heap
  //  and replacing with the last item in the heap
  T defaultPin;

  // to store for later
  this->m_array[0] = this->m_array[1];
  T& removePin = this->m_array[0];

  // bring the last item to the top
  this->m_array[1] = this->m_array[this->m_currentIndex - 1];
  this->m_array[this->m_currentIndex-1] = defaultPin;

  this->m_currentIndex--;
  this->m_heapSize--;

  int rootIndex = 1;
  if (rootIndex*2 < this->m_heapSize)
    {
      PercolateDown(rootIndex);
    }

  return removePin;
}

// PercolateUp
// Checks the parent of the index being passed in
//  Recursively calls the function until the heap
//  is a corrent minHeap
template<class T, int m_size>
void MinHeap<T, m_size>::PercolateUp(int index)
{
  if (index != 1)
    {
      int parent = index/2;
      T temp;
      
      // if child is less than parent
      //  child becomes parent
      if (this->m_array[index].CompareTo(this->m_array[parent]) == -1)
	{
	  temp = this->m_array[parent];
	  this->m_array[parent] = this->m_array[index];
	  this->m_array[index] = temp;
	  
	  PercolateUp(parent);
	}
    }
}

// PercolateDown
// Checks the children of the index being passed in
//  Recursively calls the function until the heap is correct
template<class T, int m_size>
void MinHeap<T, m_size>::PercolateDown(int index)
{
  int leftChild = index*2;
  int rightChild = leftChild + 1;
  int lesserChild;
  T temp;

  // find the lesser of the two children
  if (rightChild <= this->m_heapSize && \
      this->m_array[rightChild].GetKey() != -1)
    {
      if (this->m_array[leftChild].CompareTo(this->m_array[rightChild]) == -1)
	{
	  lesserChild = leftChild;
	}
      else
	{
	  lesserChild = rightChild;
	}
    }
  else
    {
      lesserChild = leftChild;
    }
  
  // compare the lesser child to the parent
  // if parent is greater than small child, parent percolates down
  if (this->m_array[index].CompareTo(this->m_array[lesserChild]) == 1)
    {
      // save the parent
      temp = this->m_array[index];
      
      // place lesser child where parent was
      this->m_array[index] = this->m_array[lesserChild];
      
      // place the parent where the lesser child was
      this->m_array[lesserChild] = temp;

      if (lesserChild*2 <= this->m_heapSize && \
	  this->m_array[lesserChild*2].GetKey() != -1)
	{      
	  PercolateDown(lesserChild);
	}
    }
}

#endif
