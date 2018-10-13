/*
 * finds the sum using non stack
 */

/* 
 * File:   NonStacked.h
 * Author: Tyler Staats
 *
 * Created on March 18, 2018, 10:14 AM
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include "Visitor.h"
#include "TerminalNode.h"
#include "NonTerminalNode.h"
using namespace std;

#ifndef NONSTACKBASEDSUMVISITOR_H
#define NONSTACKBASEDSUMVISITOR_H
class NonStackBasedSumVisitor: public Visitor{ //derivied from visitor
protected:
    int sum;
 
public:
   NonStackBasedSumVisitor(){sum=0;};//ctor
   virtual ~NonStackBasedSumVisitor(){}; //dtor
   virtual void visitTerminalNode(TerminalNode* trn){
       sum += trn -> getValue();        //gets value in terminal node
   };
   virtual void visitNonTerminalNode(NonTerminalNode* ntrn){
       sum+= ntrn->getValue();  //loops through all elements of nonterminal
       for(int i = 0; i< ntrn->getChildrenSize(); i++){
                ntrn->getChildren(i)->Accept(this);
            }
   };
   int getResult(){ //returns sum result
       int result = sum;
       sum = 0;
       return result;
   }
};


#endif /* NONSTACKBASEDSUMVISITOR_H */

