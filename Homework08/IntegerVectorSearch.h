/*
 *
 */

/* 
 * File:   IntergerVectorSearch.h
 * Author: Tyler Staats
 *
 * Created on February 6, 2018, 10:21 AM
 */

#ifndef INTERGERVECTORSEARCH_H
#define INTERGERVECTORSEARCH_H

#include <string>
#include <iostream>
#include <iomanip>
#include "SearchableVector.h"
#include <vector>
using namespace std;
class IntegerVectorSearchable: public SearchableVector{
        
protected:
    vector<int> m_IntegerVector;
    int m_query;  //data values 
public:
        
    IntegerVectorSearchable(){//ctor 
        vector<int> m_IntegerVector;
        int query = 0;
    }
    
    IntegerVectorSearchable(vector<int>& intergerVectorSearch){
          m_IntegerVector = intergerVectorSearch;
    }   
        
     unsigned int getSize() const{//function that returns vector size
            return m_IntegerVector.size();
    }
    
    insertInteger(int i){//function that inserts a int into the vector
        m_IntegerVector.push_back(i);
    }
    
     void print() const{ //function that prints out the queue
      for(int i=0;i<getSize();i++){
          cout<<m_IntegerVector[i]<<"; ";
          if (i == getSize()-1){
              cout<<""<<endl;
          }
      }  
      cout<<endl;
    }
    
     bool smaller(int i, int j) const{ //virtual function that returns if an
        if(getInteger(i)<getInteger(j)){     //value is less then the other value
            return true;
        }
        else{
            return false;
        }
    }
    
    int getInteger(int i)const{ //virtual function that returns a integer from queue at given element
        return m_IntegerVector[i];
    }
    
    void setQuery(int x){ // function that sets current query value
        m_query = x;
    }
    
    unsigned int compareAt(int i)const{ //virtual function used to compare values in binary
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
    
    unsigned int getValue(int i) const{//virtual function the returns int value in vector
        return m_IntegerVector[i];
    }
    
    int getMiddle(){ //function that returns middle value of queue
        return m_IntegerVector.size()/2;
    }
    
};

#endif /* INTERGERVECTORSEARCH_H */

