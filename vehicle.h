// vehicle.h
#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>
#include <random>
#include <list>
#include <ctime>
#include <fstream>
#include <iostream>


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
    Vehicle( const Vehicle &src);

    int getType(){return Tid;}
    void minusTimeReq();
    int getRepairTime();
    void setRepairTime(int hoursRequired);
    void setStatus(const char* status, ofstream& out);
    void displayParts(ofstream& out);

    void display(ostream &outs);
    bool operator ==(Vehicle *rhs);
    bool operator<( Vehicle *rhs);

    bool operator !=(Vehicle *rhs);
    list<int> getWorkingParts();
    list<int> getBrokenParts();
    void breakPart();

    bool operator()(const Vehicle* lhs, const Vehicle* rhs) const
    {
        std::cout << "hoursNeeded lhs: " << lhs->repairTime << "\n";
        std::cout << "hoursNeeded rhs: " << rhs->repairTime << "\n";
        return lhs->repairTime > rhs->repairTime;
    }
    //void setStatus(const char* status, ofstream& out);
};

inline
std::ofstream& operator<<(std::ofstream &out, Vehicle &vee){
    vee.displayParts(out);
    return out;
}

inline
std::ostream& operator<<(std::ostream &outs, Vehicle &veh)
{
    veh.display(outs);

    return outs;
}

#endif // VEHICLE_H_INCLUDED
