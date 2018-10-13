/*
 * finds the sum using non stack
 */

/*
 * File:   NonStacked.h
 * Author: Tyler Staats, Samuel Batali
 *
 *
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include "Visitor.h"
#include "bird.h"
#include "cat.h"
#include "dog.h"
#include "fish.h"
using namespace std;

#ifndef NONSTACKBASEDSUMVISITOR_H
#define NONSTACKBASEDSUMVISITOR_H
class NonStackBasedSumVisitor: public Visitor{ //derivied from visitor
protected:
    double sum;

public:
   NonStackBasedSumVisitor(){sum=0;};//ctor
   virtual ~NonStackBasedSumVisitor(){}; //dtor
   virtual void visitCat(Cat* cat){
       sum += cat -> GetPrice();        //gets value in terminal node
   };
   virtual void visitDog(Dog* dog){
       sum+= dog->GetPrice();  //loops through all elements of nonterminal
   };
   virtual void visitFish(Fish* fish){
       sum+= fish->GetPrice();  //loops through all elements of nonterminal
   };
   virtual void visitBird(Bird* bird){
       sum+= bird->GetPrice();  //loops through all elements of nonterminal
   };
   virtual void visitBundle(Bundle* bundle){
       sum+= bundle->GetPrice();
   };
   double getResult(){ //returns sum result
       double result = sum;
       sum = 0;
       return result;
   }
};


#endif /* NONSTACKBASEDSUMVISITOR_H */

