/*
 *
 * Phone class derived from Entity
 *
 */

/* 
 * File:   Phone.h
 * Author: Tyler Staats
 *
 * Created on March 10, 2018, 11:14 AM
 */

#ifndef PHONE_H
#define PHONE_H
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Entity.h"
using namespace std;

class Phone: public Entity{//derived from Entity
protected:
    int m_year;
public:
    Phone(string name, double price,int year):Entity(name,price),m_year(year){}// ctor of phone
    virtual void print() const{
        cout<<"(Phone name="<<m_name<<",Phone price="<<m_price<<");"; //prints phone data
    }
};

#endif /* PHONE_H */

