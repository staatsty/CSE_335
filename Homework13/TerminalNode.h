/*
 *leaf node of tree
 */

/* 
 * File:   TerminalNode.h
 * Author: Tyler Staats
 *
 * Created on March 18, 2018, 10:14 AM
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Node.h"
#include "NonTerminalNode.h"
using namespace std;

#ifndef TERMINALNODE_H
#define TERMINALNODE_H
class TerminalNode : public Node{//derived from node
public:
    TerminalNode(string value):Node(value){}//ctor
    virtual ~TerminalNode(){};//dtor
    virtual void Accept(Visitor* v){v->visitTerminalNode(this);}//uses visitor for pattern
     void setLeftChild(Node* left){cout<<"not used"; }
     void setRightChild(Node* left){cout<<"not used"; }//implemented virtual functions

void print(){ //prints node data
        cout<<m_value;
    }
};
#endif /* TERMINALNODE_H */

