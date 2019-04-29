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
    const char* status;


public:
    Vehicle(){Tid=0;}
    Vehicle(int i){Tid=i;}
    int getType(){return Tid;}
    int  getRepairTime();

    void setRepairTime(int hoursRequired);

    void minusTimeReq();

    Vehicle( const Vehicle &src);

    void display(ofstream& out);

    list<int> getWorkingParts();

    list<int> getBrokenParts();

    bool operator <  (Vehicle *rhs);

    bool operator != (Vehicle *rhs);

    bool operator == (Vehicle *rhs);

    void setStatus(const char* status, ofstream& out);
};

inline
std::ofstream& operator<<(std::ofstream &out, Vehicle &vee){
    vee.display(out);
    return out;
}

#endif // VEHICLE_H_INCLUDED
