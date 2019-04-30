#include <iostream>
#include <random>
#include <list>
#include <ctime>
#include "vehicle.h"

using namespace std;


Vehicle::Vehicle( const Vehicle &src){
    this-> Tid = src.Tid;
    this-> gParts = gParts;
    this-> bParts = bParts;
    this-> repairTime = repairTime;
}

int Vehicle::getRepairTime(){
	return repairTime;
}

void Vehicle::setRepairTime(int hours){
	repairTime = hours;
}

void Vehicle::displayParts(){
    cout << "Vehicle Type: " << Tid << endl;
    Pitr = gParts.begin();
    cout<<" Accept list [ ";
    while(Pitr!=gParts.end())
    {
        cout<<*Pitr;
        Pitr++;
        if(Pitr!=gParts.end()){cout<<", ";}
        else{cout<<" ";}
    }
    cout<<"] "<<endl;
    cout<<" Reject list [ ";
    Pitr=bParts.begin();
    while(Pitr!=bParts.end())
    {
      cout<<*Pitr;
        Pitr++;
        if(Pitr!=bParts.end()){cout<<", ";}
        else{cout<<" ";}
    }
    cout<<"] "<<endl<<endl;

}


list<int> Vehicle::getWorkingParts(){
    return gParts;
}

list<int> Vehicle::getBrokenParts(){
    return bParts;
}
