/*
 * Base class for all pets
 * Stores pet like attributes and functions used in a pet store database
 */

/*
 * File:   Pet.h
 * Author: Tyler Staats, Samuel Batali
 *
 *
 */

#ifndef PET_H
#define PET_H
#include <QTableWidget>
#include <string>
#include <iostream>
#include "visitor.h"
using namespace std;

class Pet{
protected:
    Pet()= default; //default ctor is protected so client cannot access
    string m_Name;
    string m_Type; //data values for pet class
    double m_Price;
    string m_Class;
    int m_Discount;


public:
    Pet(string a, double c, string b,string d):m_Name(a), m_Type(b), m_Price(c),m_Class(d){ //ctor of Pet

    };

    void SetDiscount(const int& discount){ //sets weight
        m_Discount = discount;
    }

    void SetName(const string& name){ //sets name
        m_Name = name;
    }

    void SetPrice(const double& price){ //sets price
        m_Price = price;
    }

    void SetType(const string& type){ //sets type
        m_Type = type;
    }

   int GetDiscount()const{ //returns weight
     return m_Discount;
    }

   double GetPrice()const{ //returns price
        return m_Price;
    }

   string GetType()const{ //returns type
     return m_Type;
    }

   string GetName() const{ //returns name
     return m_Name;
    }
     virtual void Accept(Visitor* ) =0;//accept for visitor pattern

    virtual void addtotable(QTableWidget*,int i) const = 0;//virtual to add a pet object to the table
   virtual vector<string> getVec() const = 0;//needed for bundle
  virtual ~Pet(){//dtor pet

  }

};



#endif /* PET_H */

