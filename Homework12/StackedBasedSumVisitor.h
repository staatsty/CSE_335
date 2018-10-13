/*
* finds sum using stack method
 */

/* 
 * File:   StackedBasedSumVistor.h
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

#ifndef STACKBASEDSUMVISITOR_H
#define STACKBASEDSUMVISITOR_H
class StackBasedSumVisitor: public Visitor{ //derived from vistor class
protected:
    stack<int> m_stack;
public:
    StackBasedSumVisitor(){};//ctor
    virtual ~StackBasedSumVisitor(){};//dtor
    virtual void visitTerminalNode(TerminalNode* trn){
        m_stack.push(trn->getValue()); //gets value from terminal node
    };
    virtual void visitNonTerminalNode(NonTerminalNode* ntrn){
        int sum = ntrn->getValue();
            for(int i = 0; i< ntrn->getChildrenSize(); i++){
                ntrn->getChildren(i)->Accept(this); //loops trhough all elements
            }
             for(int i = 0; i< ntrn->getChildrenSize(); i++){
                 sum += m_stack.top();
                 m_stack.pop(); //adds item in the stack
             }
            m_stack.push(sum);}; //addds sum to the stack
            
    int getResult(){
        int result = m_stack.top();m_stack.pop(); return result;};//returns sum from the stack
        
        
    
};


#endif /* STACKBASEDSUMVISITOR_H */

