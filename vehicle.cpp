#include <iostream>
#include <random>
#include <list>
#include <ctime>
#include "vehicle.h"

using namespace std

void Vehicle::display(ofstream& out){
    out << "Vehicle Type: " << Tid << endl;
    Pitr = gParts.begin();
    out<<" Accept list [ ";
    while(Pitr!=gParts.end())
    {
        out<<*Pitr;
        Pitr++;
        if(Pitr!=gParts.end()){out<<", ";}
        else{out<<" ";}
    }
    out<<"] "<<endl;
    out<<" Reject list [ ";
    Pitr=bParts.begin();
    while(Pitr!=bParts.end())
    {
        out<<*Pitr;
        Pitr++;
        if(Pitr!=bParts.end()){out<<", ";}
        else{out<<" ";}
    }
    out<<"] "<<endl<<endl;

}



list<int> Vehicle::getWorkingParts(){
    return gParts;
}

list<int> Vehicle::getBrokenParts(){
    return bParts;
}
