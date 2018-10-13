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
using namespace std;

#ifndef TERMINALNODE_H
#define TERMINALNODE_H
class TerminalNode : public Node{//derived from node
public:
    TerminalNode(int value):Node(value){}//ctor
    virtual ~TerminalNode(){};//dtor
    virtual void Accept(Visitor* v){v->visitTerminalNode(this);}
    
};


#endif /* TERMINALNODE_H */

