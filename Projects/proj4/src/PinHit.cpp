/***********************
 ** File:    PinHit.cpp
 ** Project: CMSC 341 Project 4, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/22/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 **  This file contains the defintions for the PinHit Class
 **
 ************************/

#include "PinHit.h"

// Default Constructor
// Sets m_pin and m_hits to default values
PinHit::PinHit() 
{
  m_pin = -1;
  m_hits = 0;
}

// Non-Default Constructor
PinHit::PinHit(int key, int value) 
{
  m_pin = key;
  m_hits = value;
}

// SetKey
// 
void PinHit::SetKey(int pin) 
{
  m_pin = pin;
}

// GetKey
//
int PinHit::GetKey() const 
{
  return m_pin;
}

// GetValue
//
int PinHit::GetValue() const 
{
  return m_hits;
}

// IncrementHits
//
void PinHit::IncrementHits() 
{
  m_hits++;
}

// CompareTo
// Compares the value (hits) of this PinHit.
int PinHit::CompareTo(const PinHit& other) const 
{
  if (m_hits == other.m_hits)
    {
      return 0;
    }
  else if (m_hits < other.m_hits)
    {
      return -1;
    }
  return 1;
}

// operator==
// 
bool PinHit::operator==(const PinHit& other) 
{
  if (this->GetKey() == other.GetKey())
    {
      return true;
    }
  else 
    {
      return false;
    }
}

