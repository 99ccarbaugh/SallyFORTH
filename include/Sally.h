// File: Sally.h
//
// CMSC 341 Fall 2018 Project 2
//
// Class declarations for Sally Forth interpreter
//

#ifndef _SALLY_H_
#define _SALLY_H_

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <map>
#include <stdexcept>
using namespace std ;


// thrown by lexical parser when end of file reached
//
class EOProgram : public runtime_error {
public:
   EOProgram(const string& what) : runtime_error(what) { }
} ;


enum TokenKind { UNKNOWN, KEYWORD, INTEGER, VARIABLE, STRING } ;


// lexical parser returns a token 
// programs are lists of tokens
//
class Token {

public:

   Token(TokenKind kind=UNKNOWN, int val=0, string txt="" ) ;
   TokenKind m_kind ;
   int m_value ;      // if it's a known numeric value
   string m_text ;    // original text that created this token

} ;



// type of a C++ function that does the work 
// of a Sally Forth operation.
//
class Sally;
	typedef void(*operation_t)(Sally *Sptr);


// entry in the symbol table has this type
//
class SymTabEntry {
public:
   SymTabEntry(TokenKind kind=UNKNOWN, int val=0, operation_t fptr=NULL) ;
   TokenKind m_kind ;
   int m_value ;            // variables' values are stored here
   operation_t m_dothis ;   // pointer to a function that does the work
} ;



// Main Sally Forth class
//
class Sally {

public:

   Sally(istream& input_stream=cin) ;  // make a Sally Forth interpreter

   void mainLoop() ;  // do the main interpreter loop


private:

   // Where to read the input
   //
   istream& istrm ;

   bool record = false;

   // List to hold rcoreded tokens
   list<Token> savedBuffer;

   // Sally Forth operations to be interpreted
   //
   list<Token> tkBuffer ;   


   // Sally Forth parameter stack
   //
   stack<Token> params ;    


   // Sally Forth symbol table
   // keywords and variables are store here
   //
   map<string,SymTabEntry> symtab ;   


   // add tokens from input to tkBuffer
   //
   bool fillBuffer() ;


   // give me one more token.
   // calls fillBuffer() for you if needed.
   //
   Token nextToken() ;


   // static member functions that do what has
   // to be done for each Sally Forth operation
   // 
   // pointers to these functions are stored 
   // in the symbol table
   //
   static void doDUMP(Sally *Sptr) ;    // for debugging

   static void doPlus(Sally *Sptr) ;
   static void doMinus(Sally *Sptr) ;
   static void doTimes(Sally *Sptr) ;
   static void doDivide(Sally *Sptr) ;
   static void doMod(Sally *Sptr) ;
   static void doNEG(Sally *Sptr) ;

   static void doDot(Sally *Sptr) ;
   static void doSP(Sally *Sptr) ;
   static void doCR(Sally *Sptr) ;

   // STACK OPERATIONS ++++++++++++++
   static void doDUP(Sally* Sptr);
   static void doDROP(Sally* Sptr);
   static void doSWAP(Sally* Sptr);
   static void doROT(Sally* Sptr);

   // VARIABLE OPERATIONS ++++++++++++
   static void doSET(Sally* Sptr);
   static void doAT(Sally* Sptr);
   static void doUPDATE(Sally* Sptr);

   // COMPARISON OPERATIONS +++++++++
   static void doLESS(Sally* Sptr);
   static void doLESSEQ(Sally* Sptr);
   static void doEQUAL(Sally* Sptr);
   static void doNOTEQ(Sally* Sptr);
   static void doGREATEQ(Sally* Sptr);
   static void doGREATER(Sally* Sptr);

   // LOGIC OPERATIONS ++++++++++++
   static void doAND(Sally* Sptr);
   static void doOR(Sally* Sptr);
   static void doNOT(Sally* Sptr);


   // IFTHEN ++++++++++
   static void doIFTHEN(Sally* Sptr);
   static void doELSE(Sally* Sptr);
   static void doENDIF(Sally* Sptr);

   // DO UNTIL ++++++++++
   static void doDO(Sally* Sptr);
   static void doUNTIL(Sally* Sptr);

} ;

#endif
