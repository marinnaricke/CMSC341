/***********************
 ** File:    Driver.cpp
 ** Project: CMSC 341 Project 1, Fall 2016
 ** Author:  Marinna Ricketts-Uy
 ** Date:    10/4/16
 ** Section: 02
 ** E-mail:  pd12778@umbc.edu
 **
 ** This file is used to test my Llama class and show
 ** that each of my functions work properly.
 ************************/

#include <iostream>
#include <string>
using namespace std;

#include "Llama.h"

int main()
{
  // ** Testing with a string linked list **
  Llama<string, 4> S;
  string letter;

  // ** Testing throw exception for pop **
  try 
    {
      S.push("A") ;
      S.push("B") ;
      
      letter = S.pop() ;
      letter = S.pop() ;
      letter = S.pop() ;
      
  } catch (LlamaUnderflow &e) 
    {
      cerr << "*****\n" ;
      cerr << "Llama Stack error: " << e.what() << endl ;
      cerr << "*****\n" ;
    }

  // ** Push a bunch of strings **

  S.push("K");
  S.push("J");
  S.push("I");
  S.push("H");
  
  S.push("G");
  S.push("F");
  S.push("E");
  S.push("D");
  
  S.push("C");
  S.push("B");
  S.push("A");

  S.dump();


  // ** Testing Peek function **

  cerr << "\n***** Dump using peek *****" ;
  int size = S.size() ;
  cerr << "\nsize = " << size << endl ;

  for (int i=0 ; i < S.size() ; i++)
    {
      cerr << i << ": " << S.peek(i) << endl ;
    }

  // ** Pop some strings off **
  string s1;

  cerr << "\n***** Pop Test *****\n";
  s1 = S.pop();
  cerr << "popped " << s1 << endl;
  s1 = S.pop();
  cerr << "popped " << s1 << endl;
  s1 = S.pop();
  cerr << "popped " << s1 << endl;
  S.dump(); // should have an extra node.

  cerr << "\n***** Push Test *****\n" ;
  S.push("adf") ;
  cout << "Pushing adf" << endl;
  S.push("umbc") ;
  cout << "Pushing umbc" << endl;
  S.push("ghfi") ;
  cout << "Pushing ghfi" << endl;

  // ** Testing swap() function **
  cout << "\n Before swapping..." << endl;
  S.dump();
  S.swap(); // ghfi and umbc should be swapped
  cout << "\n After swapping..." << endl;
  S.dump() ;

  cerr << "\n***** Pop Test *****\n" ;
  s1 = S.pop() ;
  cerr << "popped " << s1 << endl ;
  s1 = S.pop() ;
  cerr << "popped " << s1 << endl ;

  // ** Testing dup() function **
  cout << "\n Before dup..." << endl;
  S.dump();
  S.dup();
  cout << "\n After dup..." << endl;
  S.dump(); // adf should be duplicated

  cerr << "\n***** Pop Test *****\n" ;
  s1 = S.pop() ;
  cerr << "popped " << s1 << endl ;
  s1 = S.pop() ;
  cerr << "popped " << s1 << endl ;

  // ** Testing rot() function **
  cout << "\n Before rot..." << endl;
  S.dump();
  S.rot();
  cout << "\n After rot..." << endl;
  S.dump(); // DEF -> FDE

  // ** Testing copy constructor **
  cerr << "***** TESTING COPY CONSTRUCTOR *****" << endl;
  Llama<string, 4> T(S);
  cerr << "\nORIGINAL S LINKED LIST:" << endl;
  S.dump();

  cout << "\n COPIED T LINKED LIST:" << endl;
  T.dump();

  // ** Testing assignment operator **
  cerr << "***** TESTING ASSIGNMENT OPERATOR *****" << endl;
  Llama<string, 4> W;

  W = S;
  cerr << "\nORIGINAL S LINKED LIST:" << endl;
  S.dump();

  cerr << "\n ASSIGNED W LINKED LIST:" << endl;
  W.dump();

  // *** Creating another linked list with a different type ***
  // testing that it is templated
  Llama<int,3> N;

  N.push(1);
  N.push(2);
  N.push(3);

  N.push(4);
  N.push(5);
  N.push(6);

  N.push(7);
  N.push(8);
  N.push(9);

  N.push(10);

  N.dump();

  return 0;
}
