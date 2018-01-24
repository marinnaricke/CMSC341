/***********************
 ** File:    PinHit.cpp
 ** Project: CMSC 341 Project 4, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/22/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This is the header file for the PinHit Class
 **
 ************************/

#ifndef PINHIT_H_
#define PINHIT_H_

class PinHit 
{
  
 public:

  // Default Constructor
  PinHit();

  // Non-Default Constructor
  PinHit(int key, int value);

  //-------------------------------------------------------
  // Name: SetKey
  // PreCondition: pin must be an integer
  // PostCondition: Sets the m_pin member variable
  //---------------------------------------------------------
  void SetKey(int pin);

  //-------------------------------------------------------
  // Name: GetKey
  // PreCondition: none
  // PostCondition: Returns an integer
  //---------------------------------------------------------
  int GetKey() const;

  //-------------------------------------------------------
  // Name: GetValue
  // PreCondition: none 
  // PostCondition: Returns an integer
  //---------------------------------------------------------
  int GetValue() const;

  //-------------------------------------------------------
  // Name: IncrementHits
  // PreCondition: none 
  // PostCondition: Increments the member variable, m_hits
  //---------------------------------------------------------
  void IncrementHits();

  //-------------------------------------------------------
  // Name: CompareTo
  // PreCondition: none
  // PostCondition: Returns an integer
  //---------------------------------------------------------
  int CompareTo(const PinHit& other) const;

  //-------------------------------------------------------
  // Name: operator==
  // PreCondition: none 
  // PostCondition: Returns a boolean
  //---------------------------------------------------------
  bool operator==(const PinHit& other);
  
 private:

  int m_pin, m_hits;
};

#endif /* PinHit_H_ */
