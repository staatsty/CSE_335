/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tyler Staats
 *
 * Created on March 18, 2018, 10:12 AM
 */

#include <cstdlib>

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Node.h"
#include "NonStackBasedSumVisitor.h"
#include "NonTerminalNode.h"
#include "StackedBasedSumVisitor.h"
#include "TerminalNode.h"
#include "Visitor.h"
//class StackBasedSumVisitor;
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
 NonTerminalNode* root = new NonTerminalNode(0);
 NonTerminalNode* ntrn1 = new NonTerminalNode(1);
 NonTerminalNode* ntrn2 = new NonTerminalNode(2);
 NonTerminalNode* ntrn3 = new NonTerminalNode(3);

 root->addChild(ntrn1);
 root->addChild(ntrn2);
 root->addChild(ntrn3);

 ntrn1->addChild(new TerminalNode(4));
 ntrn1->addChild(new TerminalNode(5));
 ntrn1->addChild(new TerminalNode(6));

 ntrn2->addChild(new TerminalNode(7));
 ntrn2->addChild(new TerminalNode(8));
 ntrn2->addChild(new TerminalNode(9));

 ntrn3->addChild(new TerminalNode(10));
 ntrn3->addChild(new TerminalNode(11));
 ntrn3->addChild(new TerminalNode(12));
StackBasedSumVisitor sbsv;

 root->Accept(&sbsv);
 cout<<"StackBasedSumVisitor Result: "<<sbsv.getResult()<<endl;

 NonStackBasedSumVisitor nsbsv;
 root->Accept(&nsbsv);
 cout<<"NonStackBasedSumVisitor Result: "<<nsbsv.getResult();

 return 0;
}
  
