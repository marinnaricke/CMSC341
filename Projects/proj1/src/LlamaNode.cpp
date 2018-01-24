/***********************
 ** File:    LlamaNode.cpp
 ** Project: CMSC 341 Project 1, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/4/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 **  This file has the implementations of the LlamaNode class
 ** for Project 1. See project description for details.
 ** 
 **  This file should not be modified in ANY way.  
 **
 ************************/

#ifndef LLAMANODE_CPP
#define LLAMANODE_CPP


#include <iostream>
#include "LlamaNode.h"
using namespace std ;


// Static variables

template <class T, int LN_SIZE>
int LlamaNode<T,LN_SIZE>::newCount = 0 ;


template <class T, int LN_SIZE>
int LlamaNode<T,LN_SIZE>::deleteCount = 0 ;


template <class T, int LN_SIZE>
LlamaNode<T,LN_SIZE>::LlamaNode() {
  m_next = NULL ; 
  newCount++ ; 
}


template <class T, int LN_SIZE>
LlamaNode<T,LN_SIZE>::~LlamaNode() { 
  m_next = NULL ; 
  deleteCount++ ; 
}


template <class T, int LN_SIZE>
void LlamaNode<T,LN_SIZE>::report() {

  cerr << "# of nodes created = " << LlamaNode<T,LN_SIZE>::newCount << endl ;
  cerr << "# of nodes destroyed = " << LlamaNode<T,LN_SIZE>::deleteCount << endl ;

}


#endif
