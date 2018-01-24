/***********************
 ** File:    Pinball.cpp
 ** Project: CMSC 341 Project 5, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    12/6/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** 
 **
 ************************/

#include "Pinball.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

// Default Constructor
Pinball::Pinball(int n)
{
  m_capacity = n;
  m_degree = 9;
  m_ejectLimit = 8;
  m_size = 0;
  m_totalEjects = 0;
  m_maxEjects = 0;
  m_countEjects = 0;

  // allocate space for the H array and initialize it 
  H = new char *[m_capacity];

  for (int i=0; i < m_capacity; i++)
    {
      H[i] = NULL;
      m_primSlots.push_back(0);
    }
}

// Destructor
Pinball::~Pinball()
{
  //write code
  // strings in the H array must be deallocated
  // using free() since they are C strings
  for (int i = 0; i < m_capacity; i++)
    {
      free(H[i]);
    }

  delete[] H;
}

// insert
// inserts a copy of the C string str into the hash table.
// use strdup() to copy C strings. If hash table is full or the
// maximum number of ejections was exceeded, throw a PinballHashFull
// exception. 
// Calling insert() with a string that is already in the hash table
// should have no effect.
void Pinball::insert(const char *str)
{
  // throw an exception
  if (m_size == m_capacity || m_countEjects > m_ejectLimit)
    {
      m_maxEjects = m_countEjects;
      throw PinballHashFull("*** Exception: Maximum ejections reached!");
    }
  else
    {
      //make sure it's not a duplicate
      if (find(str) != -1)
	{
	  return;
	}
      
      // make copy of C string
      char * strCopy = strdup(str);
      int primarySlot = hashCode(str) % m_capacity;
      
      int auxSlots[m_degree-1];
      int currAuxSlot;
      bool strInserted = false;
      
      // add to the hits for that primarySlot
      m_primSlots[primarySlot] = m_primSlots[primarySlot] + 1;

      if (H[primarySlot] != NULL)
	{
	  // using primarySlot index as random seed
	  int degreeCount = 0;
	  int savedSeed = rand();
	  srand(primarySlot);

	  for (int i = 0; i < (m_degree-1); i++)
	    {
	      auxSlots[i] = rand() % m_capacity;
	    }

	  // see if any of the auxiliary slots are empty
	  while (degreeCount != (m_degree-1))
	    {
	      currAuxSlot = auxSlots[degreeCount];
	      if (at(currAuxSlot) == NULL)
		{
		  H[currAuxSlot] = strCopy;
		  degreeCount = (m_degree-1);
		  m_size++;
		  strInserted = true;
		  if (m_countEjects > m_maxEjects)
		    m_maxEjects = m_countEjects;
		  m_countEjects = 0;
		}
	      else 
		{
		  degreeCount++;
		}
	    }
 
	  // if none of the auxiliary slots were empty
	  //  randomly choose one of the 4 slots and eject a string
	  //  and put the str there
	  if(strInserted == false)
	    {
	      srand(savedSeed);
	      int pickAux = rand() % (m_degree-1);

	      currAuxSlot = auxSlots[pickAux];

	      char * ejectedStr = strdup(H[currAuxSlot]);

	      free(H[currAuxSlot]);
	      H[currAuxSlot] = strCopy;
	      
	      //keeping track of ejections
	      m_totalEjects++;
	      m_countEjects++;
	      if (m_countEjects > m_maxEjects)
		m_maxEjects = m_countEjects;

	      // Re-insert ejected string
	      reInsert(ejectedStr);
	    }
	}
      else
	{
	  H[primarySlot] = strCopy;
	  m_size++;
	  strInserted = true;
	  if (m_countEjects > m_maxEjects)
	    m_maxEjects = m_countEjects;
	  m_countEjects = 0;
	}
    }
}

//reInsert
// reinserts the string that was ejected
void Pinball::reInsert(char *str)
{
  // throw an exception
  if (m_size == m_capacity || m_countEjects > m_ejectLimit)
    {
      free(str);
      m_maxEjects = m_countEjects;
      throw PinballHashFull("*** Exception: Maximum ejections reached!");
    }
  else
    {
      int primarySlot = hashCode(str) % m_capacity;
      
      int auxSlots[m_degree-1];
      int currAuxSlot;
      bool strInserted = false;
      if (H[primarySlot] != NULL)
	{
	  // using primarySlot index as random seed
	  int degreeCount = 0;
	  int savedSeed = rand();
	  srand(primarySlot);

	  for (int i = 0; i < (m_degree-1); i++)
	    {
	      auxSlots[i] = rand() % m_capacity;
	    }

	  // see if any of the auxiliary slots are empty
	  while (degreeCount != (m_degree-1))
	    {
	      currAuxSlot = auxSlots[degreeCount];
	      if (at(currAuxSlot) == NULL)
		{
		  H[currAuxSlot] = str;
		  degreeCount = (m_degree-1);
		  m_size++;
		  strInserted = true;
		  if (m_countEjects > m_maxEjects)
		    m_maxEjects = m_countEjects;
		  m_countEjects = 0;
		}
	      else 
		{
		  degreeCount++;
		}
	    }

	  // if none of the auxiliary slots were empty
	  //  randomly choose one of the 4 slots and eject a string
	  //  and put the str there
	  if(strInserted == false)
	    {
	      srand(savedSeed);
	      int pickAux = rand() % (m_degree-1);

	      currAuxSlot = auxSlots[pickAux];

	      char * ejectedStr = strdup(H[currAuxSlot]);
	      
	      free(H[currAuxSlot]);
	      H[currAuxSlot] = str;
	      
	      //keeping track of ejections
	      m_totalEjects++;
	      m_countEjects++;
	      if (m_countEjects > m_maxEjects)
		m_maxEjects = m_countEjects;

	      // Re-insert ejected string
	      reInsert(ejectedStr);
	    }
	}
      else
	{
	  H[primarySlot] = str;
	  m_size++;
	  strInserted = true;
	  if (m_countEjects > m_maxEjects)
	    m_maxEjects = m_countEjects;
	  m_countEjects = 0;
	}
    }
}

// find
// Looks for str in the hash table. If found, the index of str
// is returned. If str is not in hash table, return -1
int Pinball::find(const char *str)
{
  // write code
  int strIndex = -1;
  int primarySlot = hashCode(str) % m_capacity;

  if (at(primarySlot) != NULL)
    {
      if (strcmp(str,at(primarySlot)) == 0)
	{
	  strIndex = primarySlot;
	}
    }
      
  int auxSlots[m_degree-1];
  
  srand(primarySlot);
  
  for (int i = 0; i < (m_degree-1); i++)
    {
      auxSlots[i] = rand() % m_capacity;
    }
  
  for (int i = 0; i < (m_degree-1); i++)
    {
      if (H[auxSlots[i]] != NULL)
	{
	  if (strcmp(str,at(auxSlots[i])) == 0)
	    {
	      strIndex = auxSlots[i];
	    }
	}
    }

  return strIndex;
}

// at
// Returns a pointer to the string stored at the index slot
// of the hash table. If the index is invalid, throws exception 
const char* Pinball::at(int index)
{
  // throw an out_of_range error if index is invalid
  if (index < 0 || index >= m_capacity)
    {
      throw out_of_range("*** Exception: Index is invalid!");
    }

  return H[index];
}

// remove
// Removes str from the hash table and returns the pointer. If str
// is not in the hash table, return NULL
char* Pinball::remove(const char *str)
{
  int stringIndex = find(str);
  
  if (stringIndex == -1)
    {
      return NULL;
    } 

  int primarySlot = hashCode(str) % m_capacity;

  // Decrease the number of hits to str's primary slot
  m_primSlots[primarySlot] = m_primSlots[primarySlot] - 1;


  char * removedStr = strdup(str);
  free(H[stringIndex]);
  H[stringIndex] = NULL;
  m_size--;

  return removedStr;
}

// printStats
// Print out some statistics about the hash table
void Pinball::printStats()
{
  float totalPrimSlots = 0;
  int maxPrimHits = m_primSlots[0];

  for (int i = 0; i < m_capacity; i++)
    {
      if (m_primSlots[i] != 0)
	{
	  totalPrimSlots++;
	}

      if (m_primSlots[i] > maxPrimHits)
      	{
      	  maxPrimHits = m_primSlots[i];
     	}
    }

  float avgPrimSlots = m_size/totalPrimSlots;

  cout << "Hash statistics report: "
       << "\n\trandomness level = a little bit random" 
       << "\n\tcapacity = " << m_capacity
       << "\n\tsize = " << m_size
       << "\n\tdegree = " << m_degree 
       << "\n\tejection limit = " << m_ejectLimit 
       << "\n\tnumber of primary slots = " << totalPrimSlots
       << "\n\taverage hits to primary slots = " << avgPrimSlots
       << "\n\tmaximum hits to primary slots = " << maxPrimHits
       << "\n\ttotal number of ejections = " << m_totalEjects
       << "\n\tmaximum number of ejections in a single insertion = " 
       << m_maxEjects << endl;
}
