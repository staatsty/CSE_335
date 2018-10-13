/* 
 * ExpParser class, goes through and builds expression tree
 */
/* 
 * File:   ExpParser.h
 * Author: Tyler Staats
 *
 * Created on March 18, 2018, 10:14 AM
 */
#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <iostream>
#include "Builder.h"
using namespace std;
class ExpParser{
protected:
    Builder* m_expBuilder; //uses builder pointers to build tree
public:
    void setBuilder(ExpBuilder* builder){
        m_expBuilder=builder;
    }
    
    void parse(string exp){      //same as code from the example
        string literal;
        for(int i=0; i<exp.size(); i++){
            switch(exp[i]){
                case '(':
                    if(literal.size() > 0){
                        m_expBuilder->addLiteral(literal);
                        literal.clear();
                    }
                    m_expBuilder->addLeftParenthesis();
                    break;
                case ')':
                    if(literal.size() > 0){
                        m_expBuilder->addLiteral(literal);
                        literal.clear();
                    }
                    m_expBuilder->addRightParenthesis();
                    break;
                case '+':
                    if(literal.size() > 0){
                        m_expBuilder->addLiteral(literal);
                        literal.clear();
                    }
                    m_expBuilder->addOperand("+");
                    break;
                case '-':
                    if(literal.size() > 0){
                        m_expBuilder->addLiteral(literal);
                        literal.clear();
                    }
                    m_expBuilder->addOperand("-");
                    break;
                case '*':
                    if(literal.size() > 0){
                        m_expBuilder->addLiteral(literal);
                        cout<<literal<<endl;
                        literal.clear();
                    }
                    m_expBuilder->addOperand("*");
                    break;
                case '/':
                    if(literal.size() > 0){
                        m_expBuilder->addLiteral(literal);
                        literal.clear();
                    }
                    m_expBuilder->addOperand("/");
                    break;
                default:
                    literal.push_back(exp[i]);
                    break;
            }
        }
    }
};

#endif /* PARSER_H */

