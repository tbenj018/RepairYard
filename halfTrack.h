// halfTrack.h
#ifndef HALFTRACK_H_INCLUDED
#define HALFTRACK_H_INCLUDED

#include <iostream>

using namespace std;

class HalfTrack:public Vehicle{
public:
    HalfTrack(){}
    HalfTrack(int h){Tid = h;}
    void display(){
      cout<<"HalfTrack: ";
      Vehicle::display();
    }
};

#endif // HALFTRACK_H_INCLUDED
