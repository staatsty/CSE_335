/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pet.h
 * Author: Tyler Staats
 *
 * Created on February 11, 2018, 12:53 PM
 */

#ifndef PET_H
#define PET_H

#include <string>
#include <iostream>
using namespace std;

class Pet{
protected:
    string m_Name;
    string m_Type;
    int m_Weight;
    float m_Price;
    
    
public:
    Pet(string a, string b, float c, int d):m_Name(a), m_Type(b), m_Price(c), m_Weight(d){ //ctor ofCircle
     
    };
    
    virtual unsigned int GetWeight() const = 0;
    virtual float GetPrice() const = 0;
    virtual string GetType() const = 0; //pure virtual functions
    virtual string GetName() const = 0;
    virtual void print() const = 0;
    
    //virtual void DisplayRecords() const = 0;
    
};


    
#endif /* PET_H */

