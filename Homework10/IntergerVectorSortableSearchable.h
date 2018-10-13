/*
 * IntergerVectorSortable class
 * makes use of both binary search and bubble sort algorithm using adapter pattern
 */

/* 
 * File:   IntergerVectorSortableSearchable.h
 * Author: Tyler Staats
 *
 * Created on February 14, 2018, 11:33 AM
 */
#include "IntegerVectorSortable.h"
#include "SearchableVector.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#ifndef INTERGERVECTORSORTABLESEARCHABLE_H
#define INTERGERVECTORSORTABLESEARCHABLE_H
using namespace std;

class   IntegerVectorSortableSearchable: public IntegerVectorSortable, public SearchableVector { //inherits both IntegerVectorSortable and Searchable Vector
    protected:
    vector<int> m_IntegerVector;
    int m_query;  //data values 
public:
        
    IntegerVectorSortableSearchable(){//ctor 
        vector<int> m_IntegerVector;
        int query = 0;
    }
    
    IntegerVectorSortableSearchable(vector<int>& intergerVectorSearch){
          m_IntegerVector = intergerVectorSearch;
    }   
        
     unsigned int getSize() const{//function that returns vector size
            return m_IntegerVector.size();
    }
     
     bool smaller(int i, int j) const{ //virtual function that returns if an
        if(getInteger(i)<getInteger(j)){ //value is less then the other value
            return true;
        }
        else{
            return false;
        }
    }
    void print() { //function that prints out the vector
      for(int i=0;i<getSize();i++){
         cout<<m_IntegerVector[i]<<"; ";
    
      }  
      cout<<""<<endl;
     }
    
      unsigned int compareAt(int i)const{  //virtual function used to compare values in binary
        if(i == m_query){                      //search class
            return 0;
        }
        if(smaller(m_query-1,i)){
            return 1;
        }
        else{
            return 2;
        }
    }
     void insertInteger(int i){//function that inserts a int into the vector
        m_IntegerVector.push_back(i);
    }
     
      int getValue(int i) const{//virtual function the returns int value in vector
        return m_IntegerVector[i];
    }
      
      int getInteger(int i) const{ // function that returns a integer from queue at given element
        return m_IntegerVector[i];
    }
      
      void swap(int i, int j){ //virtual function that swaps values
        int temp = m_IntegerVector[i];
        m_IntegerVector[i]=m_IntegerVector[j];
        m_IntegerVector[j]=temp;
    }
    void setQuery(int x){ // function that sets current query value
        m_query = x;
    }
};
#endif /* INTERGERVECTORSORTABLESEARCHABLE_H */

