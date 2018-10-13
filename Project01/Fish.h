/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fish.h
 * Author: Tyler Staats
 *
 * Created on February 11, 2018, 12:54 PM
 */

#ifndef FISH_H
#define FISH_H

#include <string>
#include <iostream>
using namespace std;

class Fish: public Pet{
public:
 Fish(string a, string b, float c, int d, string e):Pet(a,b,c,d),m_Water(e){ //ctor ofCircle
       
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
     cout<<"Name:    "<<m_Name<<" Type:    "<<m_Type<<"   Weight:    "<<m_Weight<<"   Price:    "<<m_Price<<"  WaterType    "<<m_Water<<endl;
 }
protected:
string m_Water;
};


#endif /* FISH_H */

