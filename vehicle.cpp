#include <iostream>
#include <random>
#include <list>
#include <ctime>
#include "vehicle.h"

using namespace std

int Vehicle::getHoursReq()
{
	return repairTime;
}

void Vehicle::setHoursReq(int hours)
{
	repairTime = hours;
}

void Vehicle::displayToFile(ofstream &out)
{
    out << "Vehicle: " << m_idNum << " has status: " << m_status << "\n";
    out << "type: " << m_type << " vehicle" <<endl;
    out << "Repair Time: " << m_hoursNeeded<< endl;
    out << endl;
}

void Vehicle::displayParts(){
    cout << "Vehicle Type: " << Tid << endl;
    Pitr = gParts.begin();
    cout<<" Accept list [ ";
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
