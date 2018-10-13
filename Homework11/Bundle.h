/*
 bundle class derived from entity. composed of different derived classes
 */

/* 
 * File:   Bundle.h
 * Author: Tyler Staats
 *
 * Created on March 10, 2018, 11:15 AM
 */

#ifndef BUNDLE_H
#define BUNDLE_H
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Entity.h"
using namespace std;

class Bundle:public Entity{ //derived from entity
protected:
    vector<Entity*> entries;
    double m_rate;
    
public:
    Bundle(string name,double rate):Entity(name,0),m_rate(rate){} //ctor of bundle
    virtual ~Bundle(){
      for(int i = 0; i<entries.size();i++){ //dtor of bundle
          delete entries[i];
      }  
    }
    
    virtual void addItem(Entity* item){ //adds item into the vector
        entries.push_back(item);
        m_price+=item->getPrice()*m_rate;

    }
    
    virtual void removeItem(Entity* item){ //removes item from  vector
        remove(entries.begin(),entries.end(),item);
        m_price -= item ->getPrice()*m_rate;
    }
    

    
    virtual void print() const{
        cout<<"Bundle "<<m_name<<" contains:(";
        for(int i = 0; i<entries.size();i++){ //prints out all elements within the bundle
            entries[i]->print();
        }
        cout<<"; Bundle price ="<<m_price<<"):";
    }
};

#endif /* BUNDLE_H */

