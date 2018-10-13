

/* 
 * File:   BubbleSortIncreasing.h
 * Author: Tyler Staats
 *
 * Created on February 10, 2018, 10:31 AM
 */
#include <string>
#include <iostream>
#include <iomanip>

#include <vector>
using namespace std;
#ifndef BUBBLESORTINCREASING_H
#define BUBBLESORTINCREASING_H

class BubbleSortIncreasing : public BubbleSortTemplate{
public:
    bool needSwap(SortableVector* sortableVector,int i, int j) const{
        return !sortableVector -> smaller(i,j); //sorts in increasing order
    }
};

#endif /* BUBBLESORTINCREASING_H */

