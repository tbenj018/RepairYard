// wheeled.h
#ifndef WHEELED_H_INCLUDED
#define WHEELED_H_INCLUDED

#include <iostream>

using namespace std;

class Wheeled:public Vehicle{
public:
    Wheeled(){}
    Wheeled(int w){Tid = w;}
    void display(){
      cout<<"Wheeled: ";
      Vehicle::display();
    }
};

#endif // WHEELED_H_INCLUDED
