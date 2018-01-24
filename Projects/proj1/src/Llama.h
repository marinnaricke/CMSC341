/***********************
 ** File:    Llama.h
 ** Project: CMSC 341 Project 1, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/4/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 **  This file has the class declaration for LlamaNode class
 ** for Project 1. See project description for details.
 **
 **  You may add public and private data members to the Llama class.
 **
 **  You may add public and private member functions to the Llama class.
 ************************/

#ifndef LLAMA_H
#define LLAMA_H

#include <stdexcept>
#include <string>
#include "LlamaNode.h"

using namespace std;


class LlamaUnderflow : public std::out_of_range 
{
 public:

  // Constructor
 LlamaUnderflow(const string& what) : std::out_of_range(what) {}

};


template <class T, int LN_SIZE>
  class Llama 
{

 public:

  // Default Constructor
  Llama();

  // Copy Constructor
  Llama(const Llama<T,LN_SIZE>& other);

  // Destructor
  ~Llama();

  //-----------------------------------------
  // Name: size
  // PreCondition: none
  // PostCondition: Returns the size of the Llama Stack
  //-----------------------------------------
  int size(); 

  //-----------------------------------------
  // Name: dump
  // PreCondition: none
  // PostCondition: Prints the contents of the Llama Stack
  //-----------------------------------------
  void dump();

  //-----------------------------------------
  // Name: push
  // PreCondition: none
  // PostCondition: Data is added to the top node
  //-----------------------------------------
  void push(const T& data);

  //-----------------------------------------
  // Name: pop
  // PreCondition: none
  // PostCondition: Returns the data being "popped"
  //-----------------------------------------
  T pop();

  //-----------------------------------------
  // Name: dup
  // PreCondition: none
  // PostCondition: (top) A B C D -> A A B C D
  //-----------------------------------------
  void dup();

  //-----------------------------------------
  // Name: swap
  // PreCondition: none
  // PostCondition: (top) A B C D -> B A C D 
  //-----------------------------------------
  void swap();

  //-----------------------------------------
  // Name: rot
  // PreCondition: none
  // PostCondition: (top) A B C D -> C A B D
  //-----------------------------------------
  void rot();  

  //-----------------------------------------
  // Name: peek
  // PreCondition: the offset must be of type int
  // PostCondition: Returns the data at the offset
  //-----------------------------------------
  T peek(int offset) const ;

  //-----------------------------------------
  // Name: operator=
  // PreCondition: rhs must be a Llama object
  // PostCondition: 
  //-----------------------------------------
  const Llama<T,LN_SIZE>& operator=(const Llama<T,LN_SIZE>& rhs) ;

 private:

  LlamaNode<T,LN_SIZE> *m_head;    // pointer to top node
  LlamaNode<T,LN_SIZE> *m_current; // pointer to the current node
  int m_llamaSize;              // stores the size of the Llama stack 
  int m_index;                  // number for next open index
  int m_topIndex;               // number for top index
  bool m_hasExtra;              // boolean for an extra node
  int m_numNodes;              // number of nodes
};

#include "Llama.cpp"

#endif
