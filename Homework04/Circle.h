

/* 
 * File:   Circle.h
 * Author: Tyler Staats
 *
 * Created on January 22, 2018, 3:15 PM
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include <iostream>
#include <iomanip>   
using namespace std;


/*
 * This class is called Circle
 * This class is derived from the Shape base class
 * Uses the same variables as shape with and added radius variable
 */
class Circle: public Shape{
public:
    float radius;  //radius of circle
    const float pi = 3.1415926535897; //const pi used to find area
    Circle(int a, int b, string c, float d):Shape(a,b,c),radius(d){ //ctor ofCircle
       
    }
    float computeArea() {return pi * (radius * radius);}//uses virtual function to compute area of Circle
    
};

#endif /* CIRCLE_H */

