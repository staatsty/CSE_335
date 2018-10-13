/*
 *Class that sorts in decreasing order by using bubble sort
 * inherits from bubblesorttemplate base class
 * Same as Homework 9
 */

/*
 * File:   BubbleSortDecreasing.h
 * Author: Tyler Staats, Samuel Batali
 *
 *
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "BubbleSortTemplate.h"
#include <vector>
using namespace std;
#ifndef BUBBLESORTDECREASING_H
#define BUBBLESORTDECREASING_H

class BubbleSortDecreasing : public BubbleSortTemplate{
public:
    bool needSwap(SortableVector* sortableVector,int i, int j) const{
        return !sortableVector -> smaller(i,j);    //function that returns true if elements need to be swapped
    }
};


#endif /* BUBBLESORTDECREASING_H */

