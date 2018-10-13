/*
* builder class used to build database
 */

/*
 * File:   builder.h
 * Author: Tyler Staats,Samuel Batali
 *
 *
 */
#ifndef BUILDER_H
#define BUILDER_H
#include "pet.h"
#include <string>

class Builder{ //same builder class from example code
public:
    virtual void addBird(string name,double price,string breed, string type, bool noct)=0; //virtuals to implement when building database
    virtual void addCat(string name,double price,string breed, string type, bool noct)=0;
    virtual void addDog(string name,double price,string breed, string type, string cate)=0;
    virtual void addFish(string name,double price,string breed, string type, string cate)=0;
    virtual void addBundle(string name,double price,vector<string>)=0;

    virtual vector<Pet*> getExpression()=0;

};


#endif /* BUILDER_H */

