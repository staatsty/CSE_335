
/* 
 * File:   Shape.h
 * Author: Tyler Staats
 *
 * Created on January 22, 2018, 2:51 PM
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
using namespace std;

/*
 * This class called shaped is the base class
 * takes 2 ints for x and y value and a string representing color
 * and open the template in the editor.
 */
class Shape{
public:
   int x;
   int y;
   string color;
Shape(int a , int b, string c):x(a),y(b),color(c){//ctor of Shape class
        
 }
virtual float computeArea()  = 0; //pure virtual function for determining area

void printColor(){
    cout<<color<<endl; //function that prints the color
}
};


#endif /* SHAPE_H */

