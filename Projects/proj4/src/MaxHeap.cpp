/***********************
 ** File:    MaxHeap.cpp
 ** Project: CMSC 341 Project 4, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/22/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file contains the definitions for the MaxHeap Class
 **
 ************************/
#ifndef MAXHEAP_CPP
#define MAXHEAP_CPP

#include "MaxHeap.h"

// Default Constructor
// Calls the constructor of Heap<T,m_size>
template<class T, int m_size>
MaxHeap<T, m_size>::MaxHeap(): Heap<T,m_size>()
{

}

// Copy Constructor
template<class T, int m_size>
MaxHeap<T, m_size>::MaxHeap(const Heap<T, m_size>& origHeap): \
  Heap<T,m_size>(origHeap)
{

}

// Remove
// Removes the first item in the heap and replaces with
// the last item in the heap. Calls PercolateDown().
template<class T, int m_size>
T& MaxHeap<T, m_size>::Remove()
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

// Insert
// Inserts the item into the last open index (m_currentIndex)
//  of the heap. Calls PercolateUp().
template<class T, int m_size>
void MaxHeap<T, m_size>::Insert(T& insertable)
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

// PercolateUp
// Checks the parent of the index being passed in
//  Recursively calls the function until the heap
//  is a correct maxHeap
template<class T, int m_size>
void MaxHeap<T, m_size>::PercolateUp(int index)
{
  if (index != 1)
    {
      int parent = index/2;
      T temp;
      
      // if child is greater than parent
      //  child becomes the parent
      if (this->m_array[index].CompareTo(this->m_array[parent]) == 1)
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
//  Recursively calls the function until the heap is
//  a correct maxHeap
template<class T, int m_size>
void MaxHeap<T, m_size>::PercolateDown(int index)
{
  // This node will be a parent
  int leftChild = index*2;
  int rightChild = leftChild + 1;
  int greaterChild;
  T temp;

  
  // find the greater of the two children
  if (rightChild <= this->m_heapSize && \
      this->m_array[rightChild].GetKey() != -1)
    {
      if (this->m_array[leftChild].CompareTo(this->m_array[rightChild]) == 1)
	{
	  greaterChild = leftChild;
	}
      else
	{
	  greaterChild = rightChild;
	}
    }
  else 
    {
      greaterChild = leftChild;
    }
  
  // compare the greater child to the parent
  // if parent is less than big child, parent percolates down
  if (this->m_array[index].CompareTo(this->m_array[greaterChild]) == -1)
    {
      // save the parent
      temp = this->m_array[index];
      
      // place greater child where parent was
      this->m_array[index] = this->m_array[greaterChild];
      
      // place the parent where the greater child was
      this->m_array[greaterChild] = temp;
      
      if (greaterChild*2 <= this->m_heapSize && \
	  this->m_array[greaterChild*2].GetKey() != -1)
	{
	  PercolateDown(greaterChild);
	}
    }
}

#endif
