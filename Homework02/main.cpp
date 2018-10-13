/*
 * Homework02
 * Show different cases of class inheritance
 */

/* 
 * File:   main.cpp
 * Author: Tyler Staats
 *
 * Created on January 13, 2018, 1:09 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
/*
 Base class used to 
 */
class X{
public:
    int publicValue;
    X(int a,int b,int c):publicValue(a),protectedValue(b),privateValue(c){//ctor for X
    }
    int doubleValue(int num){
       return num*2;    //simple double function
   }  
protected:
    int protectedValue;
    int halfValue(int num){   //simple half function
        return num/2;
    }
    
private:
    int privateValue;
    int squaredValue(int num){  // simple square function
        return num*num;
    }       
    
 };
 
class PublicY: public X{ //derived class of x public inhert
public:
   PublicY(int a, int b, int c):X(a,b,c){
       
   } 
   void cantAddToPrivate(){// error function cant access private
       //int value = privateValue+1;
       //int value2 = squaredValue(publicValue);
   }
   int publicDoubled(){
       int num = doubleValue(publicValue);
       return num;
   }
   int protectedHalfedThenTripled(){
       int num = halfValue(protectedValue);
       return num*3;
   }
   
 }; 

class PublicZ: public PublicY{ //derived class of PublicY public inhert
public:
    PublicZ(int a, int b, int c):PublicY(a,b,c){
        
    }
    int publicTripled(){ //functions that show public and protected are accessible
       int num = doubleValue(publicValue)+ publicValue;
       return num;
   }
    int protectedHalfedThenDoubled(){
       int num = halfValue(protectedValue);
       return num*2;
    }
    
};

class ProtectedY: protected X{//derived class protected inhert
public:
   ProtectedY(int a, int b, int c):X(a,b,c){
       
   }
   int protectedPlusPublic(){
       int sum = protectedValue+publicValue;
       return sum;
   }
   void cantPrivate(){ //error function to show cant access private
       //int y = squaredValue(2);
       //int z = y + privateValue;
   }
 
};

class ProtectedZ: protected ProtectedY{ //derived class protected inhert
public:
   ProtectedZ(int a, int b, int c):ProtectedY(a,b,c){
       
   } 
   int protectedPublicPlusOne(){
       int x = publicValue;
       int y = protectedValue;
       return x+y+1;
   }
};

class PrivateY: private X{ //derived class private inhert
public:
  PrivateY(int a, int b, int c): X(a,b,c){
       
   }  
  
  int publicTimesProtected(){
      //cout<<privateValue<<endl; error show cant access private
      int x = publicValue;
      int y = protectedValue;
      return x*y;
  }
};

class PrivateZ: private PrivateY{//derived class private inhert
public:
  PrivateZ(int a, int b, int c): PrivateY(a,b,c){
       
   }
  void publicTimesProtected2(){//error function to show cant access private
     //int x = publicValue;
     //int y = protectedValue;
     }
  };

 
int main(int argc, char** argv) {
    X testval(2,3,4);
    PublicY testval2(5,6,7);
    PublicZ testval3(8,9,10);
    ProtectedY testval4(11,12,13);
    ProtectedZ testval5(14,15,16);
    PrivateY testval6(17,18,19); 
    PrivateZ testval7(20,21,22);
    cout<<testval2.publicValue<<endl;
    cout<<testval2.protectedHalfedThenTripled()<<endl;
    cout<<testval3.protectedHalfedThenDoubled()<<endl;
    cout<<testval4.protectedPlusPublic()<<endl;
    cout<<testval5.protectedPublicPlusOne()<<endl;
    cout<<testval6.publicTimesProtected()<<endl;
  //cout<<testval6.publicValue<<endl; //error for private  
    return 0;
}

