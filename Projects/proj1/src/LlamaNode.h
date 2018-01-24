/***********************
 ** File:    LlamaNode.h
 ** Project: CMSC 341 Project 1, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/4/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 **  This file has the class declaration for the LlamaNode class for
 ** for Project 1. See project description for details. 
 ** 
 **        This file should not be modified in ANY way.
 ************************/

#ifndef LLAMANODE_H
#define LLAMANODE_H

#include <iostream>
using namespace std ;


template <class T, int LN_SIZE>   // forward class declaration
  class Llama ;


template <class T, int LN_SIZE>
  class LlamaNode {

  friend class Llama<T,LN_SIZE> ;

 public:

  LlamaNode()  ;
  ~LlamaNode() ;

  static void report() ; 


 private:   

  static int newCount ;      // # of times constructor was called
  static int deleteCount ;   // # of times desctructor was called

  T arr[LN_SIZE] ;
  LlamaNode *m_next ;   

} ;


#include "LlamaNode.cpp"

#endif
