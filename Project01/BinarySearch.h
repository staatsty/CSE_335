/*
 *class binary search
 * implements the binary search algorithm within a class
 */

/* 
 * File:   BinarySearch.h
 * Author: Tyler Staats
 *
 * Created on February 6, 2018, 10:21 AM
 */

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <string>
#include <iostream>
#include <iomanip>
#include "SearchableVector.h"

#include <vector>

using namespace std;

class BinarySearch{
public:          //used same concept from example code given in slides
    int search(SearchableVector* searchableVector) {
        int left = 0 ; //takes first and last values of the vector
        int right = searchableVector->getSize();
        
      while (left<= right) {
          int middle =  (left+right)/2; //takes the middle value in the
            if (searchableVector->compareAt(middle) == 0){
                return middle - 1; //returns the index if middle values match
            }                     //uses compareAt to get back conditional value

                 
            else if (searchableVector->compareAt(middle) ==1){
                  right = middle - 1; //reduces the right value to the middle - 1
            }

            else{
                  left = middle + 1; //increases the left value to middle+1
                  
            }
          
      }

      return -1; //returns -1 if not found

}
    
};
#endif /* BINARYSEARCH_H */

