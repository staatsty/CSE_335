/*
*Visitor class to implement visitor patern
 */

/*
 * File:   Visitor.h
 * Author: Tyler Staats, Samuel Batali
 *
 *
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

class Cat;
class Dog;
class Fish;
class Bird;
class Bundle;
using namespace std;

#ifndef VISITOR_H
#define VISITOR_H
class Visitor{
public:
    Visitor(){};//ctor
    virtual ~Visitor(){};//dtor
    virtual void visitCat(Cat*)=0;//pure virtuals to implement
    virtual void visitDog(Dog*)=0;
    virtual void visitBird(Bird*)=0;
    virtual void visitFish(Fish*)=0;
    virtual void visitBundle(Bundle*)=0;
};


#endif /* VISITOR_H */

