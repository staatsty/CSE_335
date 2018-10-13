/*
*Base class for tree
 * visitor pattern class
 */

/* 
 * File:   Node.h
 * Author: Tyler Staats
 *
 * Created on March 18, 2018, 10:13 AM
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Visitor.h"
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node{
    public:
        string m_value;
        
        Node(string value):m_value(value){}//ctor
        virtual ~Node(){}; //dtor
        virtual void Accept(Visitor* ) =0; //pure virtual function
        virtual void setLeftChild(Node*)= 0;
        virtual void setRightChild(Node*)= 0;
        virtual void print() = 0;
        string getValue()const{
            return m_value;
        }
       
};

#endif /* NODE_H */

