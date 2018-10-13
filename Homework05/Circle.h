

/* 
 * File:   Circle.h
 * Author: Tyler Staats
 *
 * Created on January 24, 2018, 2:50 PM
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include <iostream>
#include <iomanip>

#include "Shape.h"   
using namespace std;


/*
 * This class is called Circle
 * This class is derived from the Shape base class
 * Uses the same variables as shape with and added radius variable
 */
class Circle: public Shape{
public:
    float m_Radius;  //radius of circle
    const float pi = 3.1415926535897; //const pi used to find area
    Circle(int a, int b, string c, float d):Shape(a,b,c),m_Radius(d){ //ctor ofCircle
       cout<< "In Circle constructor with parameters  "<<endl;
    };
    Circle(){ //default ctor
        m_Radius = 0;
        x = 0;
        y = 0;
        m_Color = "";
        cout<< "In Circle constructor without parameters  "<<endl;
    };
    
    Circle(const Circle& circle):Shape(circle){ //copy ctor
        if(this!=&circle){
        m_Radius = circle.getRadius();
        cout<< "In Circle copy constructor" <<endl;
        }
        
    else{
        cout<< "In Circle copy constructor Self-copying"<<endl;
    }
    }
        
    Circle& operator=(const Circle& circle){ //"=" operator overload
    if(this!=&circle){
        Shape::operator =(circle);
        m_Radius = circle.getRadius();
        cout<< "In Circle assignment operator"<<endl;
    }
    else{
        cout<< "In Circle assignment operator Self-copying"<<endl;
    }
    return *this;
    }  
    
    virtual ~Circle(){
    cout<< "In Circle destructor "<<endl;
    
    }
    
    int getRadius() const{
        return m_Radius; //function that returns radius
    }
    float computeArea() {return pi * (m_Radius * m_Radius);}//uses virtual function to compute area of Circle
    
};

#endif /* CIRCLE_H */

