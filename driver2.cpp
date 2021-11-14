// File: driver2cpp
//
// CMSC 341 Fall 2018 Project 2
//
// Simple driver program to call the Sally Forth interpreter
// This version accepts user input for filename of Sally Forth
// source code.
//


#include <iostream>
#include <fstream>
using namespace std ;

#include "Sally.h"

int main() {
   string fname ;

   string dir = "../sally_files/";

   cout << "Enter file name: " ;
   cin >> fname ;
   fname = dir + fname;
   ifstream ifile(fname.c_str()) ;
   if (ifile) {
	   std::cout << "File Opened" << endl;
   }
   Sally S(ifile) ;

   S.mainLoop() ;

   ifile.close() ;
   return 0 ;
}
