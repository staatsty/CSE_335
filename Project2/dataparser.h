/*
 * File:   dataparser.h
 * Author: Tyler Staats,Samuel Batali
 *
 *
 */
#ifndef DATAPARSER_H
#define DATAPARSER_H
#include <string>

#include "builder.h"
#include <iostream>     // std::cout
#include <fstream>
#include <QDebug>
#include <QFile>
#include <QDir>
using namespace std;
class DataParser{
protected:
    Builder* m_dataBuilder; //uses builder pointers to database
public:
    void setBuilder(DataBuilder* builder){//sets builder
        m_dataBuilder=builder;
    }

    void parseInv(string exp){ //this sets up normal inv, not bundles
        string literal;
        ifstream file(exp);
            if (file.is_open()) {
                 string line;
                 while (getline(file, line))   {
                     vector<string>v=split(line,',');
                     string type = v[0];
                     string name = v[1];
                     string breed = v[2];
                     double price = stod(v[4]);
                     bool truth;
                     if(v[5] =="true"){ //goes through file and adds data as needed
                         truth = true;
                     }
                     if(v[5] =="false"){
                         truth = false;
                     }

                     if (type == "Dog"){
                         m_dataBuilder->addDog(name,price,breed,type,v[5]);
                     }
                     if (type == "Bird"){
                         m_dataBuilder->addBird(name,price,breed,type,truth);
                     }
                     if (type == "Cat"){
                         m_dataBuilder->addCat(name,price,breed,type,truth);
                     }
                     if (type == "Fish"){
                         m_dataBuilder->addFish(name,price,breed,type,v[5]);
                     }

                    }
              file.close();

           }
}

    void parseBundle(string file1){ //this goes through bundle file and adds data as needed
        ifstream file(file1);
            if (file.is_open()) {
                 string line;
                 while (getline(file, line))   {
                     vector<string>v=split(line,',');
                     vector<string> names;
                     for(unsigned int i = 2; i< v.size();i++){
                         names.push_back(v[i]);
                     }
                     double price = stod(v[1]);
                     m_dataBuilder->addBundle(v[0],price,names);

                 }
                 file.close();
            }
    }

    vector<string> split(const string &s, char delim){ //split function taken from cse232 old project
        string::size_type start = 0;
        vector<string> vec_str;//some variables
        auto pos = s.find(delim,start);
        while(pos != string::npos){// loops through and extracts string based on
            vec_str.push_back(s.substr(start,pos-start));//the split char
            start= pos+1;                             //puts the string into a vec
            pos=s.find(delim,start);
        }
        if (start!= s.size()){
        vec_str.push_back(s.substr(start));}

    return vec_str;}
};
#endif // DATAPARSER_H
