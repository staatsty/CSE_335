/*
 * searchable vector class
 * base class also pure virtual
 */

/* 
 * File:   SearchableVector.h
 * Author: Tyler Staats
 *
 * Created on February 6, 2018, 9:57 AM
 */

#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H
using namespace std;
class SearchableVector{
public:
    virtual unsigned int getSize() const = 0;
    virtual bool smaller(int i, int j) const = 0; //pure virtual functions
    virtual int getValue(int i) const = 0;//used in derived class
    virtual unsigned int compareAt(int i) const = 0 ;
};

#endif /* SEARCHABLEVECTOR_H */

