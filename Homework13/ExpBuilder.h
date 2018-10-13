/*
* builder class that builds the tree
 */
/* 
 * File:   ExpBuilder.h
 * Author: Tyler Staats
 *
 * Created on March 18, 2018, 10:14 AM
 */
#ifndef EXPRESSIONBUILDER_H
#define EXPRESSIONBUILDER_H
#include <stack>
#include <iostream>
#include "Node.h"
#include "Builder.h"
#include "NonTerminalNode.h"
#include "TerminalNode.h"
using namespace std;
class ExpBuilder: public Builder{//inherits from builder class
protected:                       //similar class to example code
    stack<Node*> expStack; 
public:
    virtual void addOperand(string operand){ //adds operand to stack
        Node* newOperand = new NonTerminalNode(operand);
        expStack.push(newOperand);
    };
    
    virtual void addLiteral(string literal){ //adds literal to stack
        Node* newOperand = new TerminalNode(literal);
        expStack.push(newOperand);
    };
    
    virtual void addLeftParenthesis(){};//implemented virtual
    
    virtual void addRightParenthesis(){//adds node to stack
        Node* rightChild = expStack.top();
        expStack.pop();
        Node* parent = expStack.top();
        expStack.pop();
        Node* leftChild = expStack.top();
        expStack.pop();
        parent->setLeftChild(leftChild);
        parent->setRightChild(rightChild);
        expStack.push(parent);
    };
    
    virtual Node* getExpression(){//getter for expression
        Node* root = expStack.top();
        expStack.pop();
        return root;
    };
};
#endif /* EXPRESSIONBUILDER_H */