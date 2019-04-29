// wheeled.h
#ifndef WHEELED_H_INCLUDED
#define WHEELED_H_INCLUDED

#include <iostream>

using namespace std;

class Wheeled:public Vehicle{
public:
    Wheeled(){}
    Wheeled(int w){Tid = w;}
    void display(ofstream& out){
      cout<<"Wheeled: ";
      Vehicle::display(out);
    }
    void addParts4(default_random_engine* gptr){
        uniform_int_distribution<int> Pdist(1,100);
          for(int i = 31; i < 41; i++){
            int p = Pdist(*gptr);
                if(p > 66){
                    bParts.push_back(i);
                }
                else{
                    gParts.push_back(i);
                }
        }
    }
    void addParts5(default_random_engine* gptr){
        uniform_int_distribution<int> Pdist(1,100);
          for(int i = 36; i < 46; i++){
            int p = Pdist(*gptr);
                if(p > 66){
                    bParts.push_back(i);
                }
                else{
                    gParts.push_back(i);
                }
        }
    }
};

#endif // WHEELED_H_INCLUDED
