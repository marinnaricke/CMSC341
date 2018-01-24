/***********************
 ** File:    Driver.cpp
 ** Project: CMSC 341 Project 4, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    11/22/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This is the main driver. 
 **
 ************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>

#include "PinHit.h"
#include "Heap.h"
#include "MinHeap.h"
#include "MaxHeap.h"

// global variable
std::string heapType = "--max";

//-------------------------------------------------------
// Name: printGreeting
// PreCondition: none
// PostCondition: Prints name and class section
//---------------------------------------------------------
void printGreeting();

//-------------------------------------------------------
// Name: ReadPins
// PreCondition: none
// PostCondition: Returns a vector of type PinHit
//---------------------------------------------------------
std::vector<PinHit> ReadPins(char* fileName, int* totalHits);

//-------------------------------------------------------
// Name: BuildHeap
// PreCondition: none
// PostCondition: Returns a templated Heap
//---------------------------------------------------------
template<class T, int m_size>
Heap<T, m_size>* BuildHeap(std::vector<T> PinHits, int slots);

//-------------------------------------------------------
// Name: Hack
// PreCondition: none
// PostCondition: Returns an integer
//---------------------------------------------------------
template<class T, int m_size>
int Hack(Heap<T, m_size>* heap, std::vector<T> PinHits, int totalHits);

int main(int argc, char* argv[]) 
{
  const int SIZE = 10001;
  int max_hits = 10000;
  int totalHits = 0; // total number of lines(pins) in the file
  int hacks;
  std::vector<PinHit> pinHits;
  heapType = argv[2];

  printGreeting();

  // Create pinHits vector
  pinHits = ReadPins(argv[1], &totalHits); 

  // Create Heap
  Heap<PinHit,SIZE>* heap;

  heap = BuildHeap<PinHit,SIZE>(pinHits,max_hits);

  // **** For testing purposes ****
  // ** print array **
  //heap->printArray();
  
  std::cout << "TotalHits: " << totalHits << std::endl;

  hacks = Hack(heap,pinHits,totalHits);

  std::cout << " Number of successful hacks: " << hacks << std::endl;

  return EXIT_SUCCESS;
}

// printGreeting
// prints name and class section
void printGreeting() 
{
  std::cout << "Marinna Ricketts-Uy, Section 02" << std::endl;
}

// ReadPins
// Reads in the input file and creates the PinHit vector
std::vector<PinHit> ReadPins(char* fileName, int* totalHits) 
{
  PinHit newPin;
  std::vector<PinHit> pinHits (10000,newPin);
  std::ifstream infile;
  std::string oneLine,data;
  int pinNumber;
  PinHit pin;

  // opening the file
  infile.open(fileName,std::ios_base::in);

  // Checking if file can be opened
  if (infile.fail())
    {
      std::cerr << "File could not be successfully opened." << std::endl;
      exit(1);
    }
  else
    {
      while(true)
	{
	  getline(infile,oneLine);

	  if (infile.eof())
	    {
	      break;
	    }
	  
	  std::istringstream istrm(oneLine);
	  istrm >> data;

	  pinNumber = atoi(data.c_str());

	  // if pin is not already in vector, create pin
	  // else increment hits
	  *totalHits = *totalHits + 1;
	  if (pinHits[pinNumber].GetKey() != pinNumber)
	    {
	      PinHit pin(pinNumber, 1);
	      pinHits[pinNumber] = pin;
	    }
	  else
	    {
	      pinHits[pinNumber].IncrementHits();
	    }

	}
    }

  infile.close();
  return pinHits;
}

// BuildHeap
// Creates the heap, based on command line argument
template<class T, int m_size>
Heap<T, m_size>* BuildHeap(std::vector<T> PinHits, int slots) 
{
  // using the vector of PinHits, insert the PinHits into the Heap
  
  // create heap depending on user input
  Heap<PinHit,m_size>* newHeap;

  if (heapType == "--min") 
    {
      newHeap = new MinHeap<PinHit, m_size>();
    } 
  else if (heapType == "--max") 
    {
      newHeap = new MaxHeap<PinHit, m_size>();
    } 
  else 
    {
      newHeap = new Heap<PinHit, m_size>();
    }

  //Insert into the heap
  for (int i = 0; i < slots; i++)
    {
      if (PinHits[i].GetKey() != -1)
	{
	  newHeap->Insert(PinHits[i]);
	}
    }

  return newHeap; 
}

// Hack
// Returns an integer of the number of successful hacks
template<class T, int m_size>
int Hack(Heap<T, m_size>* heap, std::vector<T> PinHits, int totalHits) 
{
  int UPPER_BOUND = totalHits; // used for failsafes

  /*
   * His fictional bank with fictional cards and 
   * "normal pins" will allow you to incorrectly attempt 
   * to access his card 3 times per hour. You have from 
   * the start of the assignment to the end to hack as 
   * many accounts as possible (14 days * 24 hr/day * 3 
   * attempts/hr = 1008 attempts per card)
   */
  int MAX_ATTEMPTS = 1008;

  int hackAttemptsLeft = MAX_ATTEMPTS;
  int successfulHacks = 0;

  srand (time(NULL)); // seeds our random generator with the current time  
  int randomNumHits = rand() % totalHits; // generates a random hit between 0 and total hits
  //randomNumHits = 0; // change this if you want to hardcode in your hits for a specific pin
  int curHits = 0; // our variable for crawling
  int randomIndex = -1; // the index where our new random pinhit lives
  int newHits = 0; // number of hits in new "random" pin
  int failSafe = 0; // always good to have one of these in what could be an infinite loop

  /* 
   * Linearly searches through PinHits until
   * we've accrued enough hits to reach our random hits
   * which will then determine the next pin to try to hack.
   * We use newHits to make sure we don't pick a random pin
   * that's not in our heap. 
   */
  PinHit curPinHit;
  while (newHits == 0 && failSafe < UPPER_BOUND) {

    for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++) {
      curHits += PinHits[i].GetValue();
      randomIndex = i;
    }
    // should have found the random pin by now
    curPinHit = PinHits[randomIndex];
    newHits = curPinHit.GetValue(); // make sure it's actually in our heap
    std::cout << "Random Pin: [" << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
    failSafe++;
  }

  // let's make a copy of the heap so we don't modify the original.
  Heap<T, m_size>* heapCopy;

  if (heapType == "--min") {
    heapCopy = new MinHeap<T, m_size>(*heap);
  } else if (heapType == "--max") {
    heapCopy = new MaxHeap<T, m_size>(*heap);
  } else {
    heapCopy = new Heap<T, m_size>(*heap);
  }

  failSafe = 0;

  PinHit defaultPin;

  // exit once hacking 10000 accounts, either a hacking prodigy or something is wrong
  int MAX_NUM_HACKS = 10000;

  // **added variable
  int hitCount = 0;

  while (0 < hackAttemptsLeft && successfulHacks < MAX_NUM_HACKS) {
    // grabs our root
    PinHit topOfHeap = heapCopy->Remove();

    // ** added line **
    hitCount = hitCount + (topOfHeap.GetValue()); 

    if (topOfHeap == defaultPin)
      break;

    if (hackAttemptsLeft == 1)
      std::cout << topOfHeap.GetKey() << ", " << topOfHeap.GetValue() << " our last attempt" << std::endl;

    hackAttemptsLeft--;

    // account was hacked!
    if (topOfHeap == curPinHit) 
      {
	std::cout << "We got them!" << std::endl;
	successfulHacks++;
	
	// reset our heap
	if (heapType == "--min") 
	  {
	    heapCopy = new MinHeap<T, m_size>(*heap);
	  } 
	else if (heapType == "--max") 
	  {
	    heapCopy = new MaxHeap<T, m_size>(*heap);
	  } 
	else 
	  {
	    heapCopy = new Heap<T, m_size>(*heap);
	  }

	// reset
	hackAttemptsLeft = MAX_ATTEMPTS;
	randomNumHits = rand() % totalHits;
	curHits = 0;
	randomIndex = -1;
	newHits = 0;
	failSafe = 0;
	while (newHits == 0 && failSafe < UPPER_BOUND) 
	  {
	    
	    for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++) 
	      {
		curHits += PinHits[i].GetValue();
		randomIndex = i;
	      }
	    // should have found the random pin by now
	    curPinHit = PinHits[randomIndex];
	    newHits = curPinHit.GetValue(); // make sure it's actually in our heap
	    std::cout << "Random Pin: [" << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
	    failSafe++;
	  }
	
	std::cout << "Valid Random Pin: " << curPinHit.GetKey() << " found!" << std::endl;
      }
  }
  
  std::cout << "Hits: " << hitCount << std::endl;
  return successfulHacks;
}
