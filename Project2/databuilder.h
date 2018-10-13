/*
 * File:   databuilder.h
 * Author: Tyler Staats,Samuel Batali
 *builds database for tables
 *
 */
#ifndef DATABUILDER_H
#define DATABUILDER_H
#include <stack>
#include <iostream>
#include "pet.h"
#include "Builder.h"
#include "bundle.h"

using namespace std;
class DataBuilder: public Builder{//inherits from builder class
protected:                       //similar class to example code
    vector<Pet*> petVector;
    vector<string> petNames;
public:
    virtual void addBird(string name,double price,string breed,string type, bool noct){ //adds bird to table
        Pet* newOperand = new Bird(name,price,breed,type,noct);
        petVector.push_back(newOperand);
    };

    virtual void addDog(string name,double price,string breed,string type, string cate){ //adds dog to table
        Pet* newOperand = new Dog(name,price,breed,type,cate);
        petVector.push_back(newOperand);
    };

    virtual void addCat(string name,double price,string breed,string type, bool noct){//adds cat to table
        Pet* newOperand = new Cat(name,price,breed,type,noct);
        petVector.push_back(newOperand);
    };

    virtual void addFish(string name,double price,string breed,string type, string cate){//adds fish to table
        Pet* newOperand = new Fish(name,price,breed,type,cate);
        petVector.push_back(newOperand);
    };
    virtual void addBundle(string name,double price,vector<string>names){//adds bundle tot able
        Pet* newOperand = new Bundle(name,price,names);
        petVector.push_back(newOperand);
    };

    virtual vector<Pet*> getExpression(){//returns vector of pets
        return petVector;
    }

};
#endif // DATABUILDER_H
