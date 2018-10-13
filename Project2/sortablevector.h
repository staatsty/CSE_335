/*
 * sortable vector class used to show bubble sort
 * base class
 */

/*
 * File:   SortableVector.h
 * Author: Tyler Staats,Samuel Batali
 *
 *
 */
#include <string>
#include <iostream>
#include <iomanip>

#include <vector>
using namespace std;
#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H

class SortableVector{
public:
    virtual unsigned int getSize() const = 0;
    virtual bool smaller(int i, int j) const = 0; //pure virtual functions used in derived classes
    virtual void swap(int i, int j) = 0;
    virtual ~SortableVector(){ //dtor of SortableVector

    }

};


#endif /* SORTABLEVECTOR_H */

