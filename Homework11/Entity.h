/*
 Entity base class
 * used to show composite pattern
 */

/*
 * File:   Entity.h
 * Author: Tyler Staats
 *
 * Created on March 10, 2018, 11:14 AM
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Entity{
protected:
string m_name;
double m_price;
Entity(string name, double price): m_name(name), m_price(price){}//ctor

public:
    virtual string getName() const{//returns name
        return m_name;
    }
   
    virtual int getPrice() const{ //return price
        return m_price;
    }
    virtual void print() const = 0; //pure virtual used in derived classes for printing
};

#endif /* ENTITY_H */

