/***********************
 ** File:    Pinball.h
 ** Project: CMSC 341 Project 5, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    12/6/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** 
 **
 ************************/

#ifndef _PINBALL_H_
#define _PINBALL_H_

#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

class PinballHashFull : public std::out_of_range 
{
 public:
 PinballHashFull(const string& what) : std::out_of_range(what) { }
} ;


class Pinball 
{
 public:

  // Default Constructor
  Pinball(int n = 1019);    // default capacity is prime

  // Destructor
  ~Pinball();
  
  //-------------------------------------------------------
  // Name: insert
  // PreCondition: str must be a const char *  
  // PostCondition: inserts str into the hash table
  //---------------------------------------------------------  
  void insert(const char *str);

  //-------------------------------------------------------
  // Name: find
  // PreCondition: str must be a const char *
  // PostCondition: Returns an integer
  //---------------------------------------------------------
  int find(const char *str);

  //-------------------------------------------------------
  // Name: at
  // PreCondition: index must be an integer 
  // PostCondition: Returns a const char *
  //---------------------------------------------------------
  const char * at(int index);

  //-------------------------------------------------------
  // Name: remove
  // PreCondition: str must be a const char *
  // PostCondition: Returns a char *
  //---------------------------------------------------------
  char * remove(const char *str);

  //-------------------------------------------------------
  // Name: printStats
  // PreCondition: none
  // PostCondition: Prints out statistics for the hash table
  //---------------------------------------------------------
  void printStats();
  
  //-------------------------------------------------------
  // Name: size
  // PreCondition: none
  // PostCondition: Returns the current size of H
  //---------------------------------------------------------
  int size() { return m_size; }
  
  // add public data members and 
  // public member functions as needed

  //-------------------------------------------------------
  // Name: reInsert
  // PreCondition: str must be a char *
  // PostCondition: str is reinserted into the hash table
  //---------------------------------------------------------
  void reInsert(char *str);

 private:
  
  char ** H ;        // the actual hash table
  int m_size ;       // number of items stored in H
  int m_capacity ;   // number slots allocated in H
  
  int m_degree ;     // use degree assigned to you
  int m_ejectLimit ; // use ejection limit assigned to you
  
  
  // Made inline definition of hashCode() so everyone uses
  // the same function.
  //
  unsigned int hashCode(const char *str) 
  {
    unsigned int val = 0; 
    const unsigned int thirtyThree = 33;  // magic number from textbook
    
    int i = 0;
    while (str[i] != '\0')
      {
	val = val * thirtyThree + str[i];
	i++;
      }
    return val; 
  }

  // add private data members and 
  // private member functions as needed
  int m_countEjects; // keeps track of number of ejects in single operation
  int m_totalEjects; // total number of ejections
  int m_maxEjects;  // keeps track of maxEjects
  vector<int> m_primSlots; // used to store the hits per primary slot
};

#endif
