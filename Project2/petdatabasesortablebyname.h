/*
 *class derived from sortable vector base class
 * sorts for pet object by name
 */

/*
 * File:   PetDatabaseSortableByName.h
 * Author: Tyler Staats ,Samuel Batali
 *
 * Created on February 11, 2018, 12:54 PM
 */

#ifndef PETDATABASESORTABLEBYNAME_H
#define PETDATABASESORTABLEBYNAME_H

#include <string>
#include <iostream>
#include <iomanip>
#include "SortableVector.h"
#include <vector>
using namespace std;
class PetDatabaseSortableByName: public SortableVector{

protected:
    PetDatabaseSortableByName()= default;//default ctor protected so client cant access
    vector<Pet*> m_PetVector;
    int m_query;  //data values
public:

    PetDatabaseSortableByName(const PetDatabaseSortableByName& petDatabaseSortableByName) = default;//copy ctor
    PetDatabaseSortableByName& operator=(const PetDatabaseSortableByName& petDatabaseSortableByName) = default; //"=" overload
    PetDatabaseSortableByName(vector<Pet*> petVector ){//ctor PetDatabaseSortableByName
        m_PetVector = petVector;

    }

     unsigned int getSize() const{//function that returns vector size
            return m_PetVector.size();
    }


    bool smaller(int i, int j) const{ //virtual function that returns if an
        if(m_PetVector[i]->GetName()<m_PetVector[j]->GetName()){     //value is less then the other value
           return true;
        }
       else{
            return false;
       }
    }

    void setQuery(const int& query){ // function that sets current query value
        m_query = query;
    }

    int getQuery()const{ //returns query
        return m_query;
    }

    void swap(int i, int j){ //function that swaps two elements
        Pet* temp = m_PetVector[i];
        m_PetVector[i]=m_PetVector[j];
        m_PetVector[j]=temp;
    }

    vector<Pet*> getVector(){ //returns a vector
        return m_PetVector;
    }

    virtual ~PetDatabaseSortableByName(){//dtor of PetDatabaseSortableByName

    }
};

#endif /* PETDATABASESORTABLEBYNAME_H */

