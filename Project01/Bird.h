/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bird.h
 * Author: Tyler Staats
 *
 * Created on February 11, 2018, 12:54 PM
 */

#ifndef BIRD_H
#define BIRD_H

#include <string>
#include <iostream>
using namespace std;

class Bird: public Pet {
 public:
 Bird(string a, string b, int c, float d, bool e):Pet(a,b,c,d),m_Nocturnality(e){ //ctor ofCircle
       
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
     cout<<"Name:    "<<m_Name<<" Type:    "<<m_Type<<"   Weight:    "<<m_Weight<<"   Price:    "<<m_Price<<"   Nocturnal    "<<m_Nocturnality<<endl;
 }
 

protected:
bool m_Nocturnality;
};


#endif /* BIRD_H */

