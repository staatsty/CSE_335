/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cat.h
 * Author: Tyler Staats
 *
 * Created on February 11, 2018, 12:53 PM
 */

#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>
using namespace std;

class Cat: public Pet{
public:
 Cat(string a, string b, float c, int d, bool e):Pet(a,b,c,d),m_Fluffy(e){ //ctor ofCircle
       
    };   
   
 unsigned int GetWeight()const{
     return m_Weight;          
 }
 float GetPrice()const{
        return m_Price;
 }
 string GetType()const{
     return m_Type;
 } 
 string GetName() const{
     return m_Name;
 }
 void print() const{
     cout<<"Name:    "<<m_Name<<" Type:    "<<m_Type<<"   Weight:    "<<m_Weight<<"   Price:    "<<m_Price<<"  Fluffy    "<<m_Fluffy<<endl;
 }
protected:
bool m_Fluffy;
};



#endif /* CAT_H */

