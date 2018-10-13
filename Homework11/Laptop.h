/*
 * laptop class derived from entity
 */

/* 
 * File:   Laptop.h
 * Author: Tyler Staats
 *
 * Created on March 10, 2018, 11:15 AM
 */

#ifndef LAPTOP_H
#define LAPTOP_H
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Entity.h"
using namespace std;

class Laptop: public Entity{ // derived from entity
protected:
    string m_power;
public:
    Laptop(string name, double price, string power):Entity(name,price),m_power(power){} // ctor of laptop
    virtual void print() const{
        cout<<"(Laptop name="<<m_name<<",Laptop price="<<m_price<<");"; //prints out laptop data
    }
};


#endif /* LAPTOP_H */

