// vehicle.h
#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>
#include <random>
#include <list>
#include <ctime>
#include <fstream>


using namespace std;

class Vehicle{
protected:
    int Tid;
    list<int> gParts;
    list<int>::iterator Pitr;
    list<int> bParts;
    int repairTime = 0;



public:
    Vehicle(){Tid=0;}
    Vehicle(int i){Tid=i;}
    Vehicle( const Vehicle &src);
    int getType(){return Tid;}
    int getRepairTime();
    void setRepairTime(int hoursRequired);
    void displayParts();
    list<int> getWorkingParts();
    list<int> getBrokenParts();
    //void setStatus(const char* status, ofstream& out);
};
/*
inline
std::ofstream& operator<<(std::ofstream &out, Vehicle &vee){
    vee.displayParts();
    return out;
}*/

#endif // VEHICLE_H_INCLUDED
