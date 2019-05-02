#include <iostream>
#include <fstream>
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

void Vehicle::displayParts(ofstream& out){

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

void Vehicle::setStatus(const char* status, ofstream& out){
    status = status;
  //  display(cout);
  //  displayToFile(out);
}

void Vehicle::breakPart(){
    int numberOfWorkingParts = gParts.size();
    uniform_int_distribution<int> breakRandomPart(0, numberOfWorkingParts - 1);
    int brokenIndex = breakRandomPart(*engine);
    int part = gParts[brokenIndex];
    bParts.push_back(part);
    gParts.erase(gParts.begin() + brokenIndex);
    repairTime = 0;
    for (auto aBrokenPart: bParts)
    {
      repairTime += aBrokenPart;
    }
}

void Vehicle::minusTimeReq(){
  if (m_hoursNeeded >0)
    m_hoursNeeded=m_hoursNeeded-1;
}


void Vehicle::display(ostream &outs)
{
    /cout << "Vehicle: " << Tid << " has status: " << status << "\n";
    cout << "type: " << Tid << " vehicle" <<endl;
    cout << "Repair Time: " << repairTime<< endl;
    cout << endl;
}

bool Vehicle::operator<( Vehicle *rhs){
   return this->repairTime < rhs->getRepairTime();
}

bool Vehicle::operator ==(const Vehicle *rhs) const{
  return rhs.getType() == Tid;
}

bool Vehicle::operator !=(Vehicle *rhs){
  return (!(this->Tid == rhs->getType()));
}
