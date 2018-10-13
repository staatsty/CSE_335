/*
* finds sum using stack method
 */

/* 
 * File:   builder.h
 * Author: Tyler Staats
 *
 * Created on March 18, 2018, 10:14 AM
 */
#ifndef BUILDER_H
#define BUILDER_H
#include "Node.h"
#include <string>

class Builder{ //same builder class from example code used to make tree
public:
    virtual void addOperand(string operand)=0;
    virtual void addLiteral(string literal)=0;
    virtual void addLeftParenthesis()=0;
    virtual void addRightParenthesis()=0;
    virtual Node* getExpression()=0;
};


#endif /* BUILDER_H */

