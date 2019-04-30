// halfTrack.h
#ifndef HALFTRACK_H_INCLUDED
#define HALFTRACK_H_INCLUDED

#include <iostream>

using namespace std;

class HalfTrack:public Vehicle{
private:
    int hParts[15] = {1,2,3,4,5,31,32,33,34,35,36,37,38,39,40};
public:
    HalfTrack(){}
    HalfTrack(int h){Tid = h;}
    void display(){
      cout<<"HalfTrack: ";
      Vehicle::displayParts();
    }
    void addParts(default_random_engine* gptr){
        uniform_int_distribution<int> Pdist(1,100);
          for(int i = 0; i < 15; i++){
            int p = Pdist(*gptr);
                if(p > 66){
                    bParts.push_back(hParts[i]);
                }
                else{
                    gParts.push_back(hParts[i]);
                }
        }
    }
};

#endif // HALFTRACK_H_INCLUDED
