/*
*Visitor class to implement visitor patern
 */

/* 
 * File:   Visitor.h
 * Author: Tyler Staats
 *
 * Created on March 18, 2018, 10:14 AM
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

class NonTerminalNode;
class TerminalNode;
using namespace std;

#ifndef VISITOR_H
#define VISITOR_H
class Visitor{
public:
    Visitor(){};
    virtual ~Visitor(){};//dtor
    virtual void visitNonTerminalNode(NonTerminalNode*)=0;//pure virtuals to implement
    virtual void visitTerminalNode(TerminalNode*)=0;
};


#endif /* VISITOR_H */

