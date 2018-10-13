/*
 *class derived from node
 */

/* 
 * File:   NonTerminalNode.h
 * Author: Tyler Staats
 *
 * Created on March 18, 2018, 10:13 AM
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Node.h"
using namespace std;

#ifndef NONTERMINALNODE_H
#define NONTERMINALNODE_H
class NonTerminalNode : public Node{ //public inheritance
protected:
    vector<Node*> m_vector;
public:
    
    
    NonTerminalNode(int value):Node(value){}//ctor
    virtual ~NonTerminalNode(){};//dtor
    virtual void Accept(Visitor* v){v->visitNonTerminalNode(this);} //accept function from slides
    
    virtual void addChild(Node* t){ //adds child node
        m_vector.push_back(t);
    }
    virtual unsigned int getChildrenSize()const{ //returns size of node
        return m_vector.size();
    }
    virtual Node* getChildren(int i)const{ //returns child node
        return m_vector[i];
    }
    
    
};


#endif /* NONTERMINALNODE_H */

