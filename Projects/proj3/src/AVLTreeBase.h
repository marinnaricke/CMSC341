/***********************
 ** File:    Driver.cpp
 ** Project: CMSC 341 Project 3, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/1/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** 
 **
 ************************/

#ifndef _AVLTREEBASE_H_
#define _AVLTREEBASE_H_

class AVLTreeBase
{
  // dummy class required to remove template dependency
 public:

  /*
   * IN = in-order print
   * PRE = pre-order print
   * POST = post-order print
   * LEVEL = level-order print
   */
  enum PrintOrder{IN, PRE, POST, LEVEL};

  /*
   * types for template instantiations
   */
  enum DataType{CHARACTER, STRING};
  enum NumberType{INTEGER, FLOAT};
};

#endif /* _AVLTREEBASE_H_ */
