/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tyler Staats
 *
 * Created on March 20, 2018, 12:40 PM
 */

#include <cstdlib>
#include "Node.h"
#include "Builder.h"
#include "ExpBuilder.h"
#include "ExpParser.h"
#include "StackBasedCalVisitor.h"
using namespace std;

int main(int argc, char** argv) {
 ExpBuilder builder;
 ExpParser parser;
 parser.setBuilder(&builder);
 string input="(((30+500)*70)-(60/50))";
 parser.parse(input);
 Node* root = builder.getExpression();
 cout<<input<<endl;
 root->print();

 StackBasedCalVisitor sbsv;
 root->Accept(&sbsv);
 cout<<endl<<"StackBasedSumVisitor Result: "<<fixed<<setprecision(1)<<sbsv.getResult()<<endl;
 return 0;
}

