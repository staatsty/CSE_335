
/* 
 * File:   Square.h
 * Author: Tyler Staats
 *
 * Created on January 22, 2018, 3:06 PM
 */

#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <iostream>
using namespace std;

/*
 * This class is called Square and is derived from the Shape base class
 * Takes the same variables as shape with the added edgeLength variable
 */
class Square: public Shape{
public:
    float edgeLength;
    Square(int a, int b, string c, float d):Shape(a,b,c),edgeLength(d){// ctor for square
       
    }
    float  computeArea()   {return edgeLength * edgeLength;} //squares the edge length to find area
                                                             //uses virtual function from Shape class
};

#endif /* SQUARE_H */

