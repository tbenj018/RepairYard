// MainMenu.h
#include <iostream>
#include <random>
#include <list>
#include "yardMaster.h"
#include "vehicle.h"
#include "tank.h"
#include "wheeled.h"
#include "halfTrack.h"


using namespace std;

YardMaster::YardMaster(string filename){
  out.open(filename);
}

YardMaster::~YardMaster()
{
	out.close();
}

void YardMaster::VehicleList(){
  generateVehicles();
  
}

void YardMaster::generateVehicles(){

    uniform_int_distribution<int> vehicleType(1, 8);
    int v = vehicleType(*gptr);
    for(int i = 1; i <= 6; i++ ){
        if(i = 1){
            tptr = new Tank(1);
            tptr->addParts(gptr);
            vptr = tptr;
            MyVehicles.push_back(vptr);}
        else if(i = 2 ){
            tptr = new Tank(2);
            tptr->addParts(gptr);
            vptr = tptr;
            MyVehicles.push_back(vptr);}
        else if(i = 3 ){
            tptr = new Tank(3);
            tptr->addParts(gptr);
            vptr = tptr;
            MyVehicles.push_back(vptr);}
        else if(i = 4 ){
            wptr = new Wheeled(4);
            wptr->addParts4(gptr);
            vptr = wptr;
            MyVehicles.push_back(vptr);}
        else if(i = 5 ){
            wptr = new Wheeled(5);
            wptr->addParts5(gptr);
            vptr = wptr;
            MyVehicles.push_back(vptr);}
        else if(i = 6 ){
            hptr = new HalfTrack(6);
            hptr->addParts(gptr);
            vptr = hptr;
            MyVehicles.push_back(vptr);}
        else
            cout << "error" << endl;
    }
    vitr = MyVehicles.begin();
    while(vitr != MyVehicles.end()){
        t = (*vitr)->getType();
        if(t == 1){
            tptr = (Tank*) *vitr;
            tptr->displayParts();
        }
        else if(t == 2){
            tptr = (Tank*)*vitr;
            tptr->displayParts();
        }
        else if(t == 3){
            tptr = (Tank*)*vitr;
            tptr->displayParts();
        }
        else if(t == 4){
            wptr = (Wheeled*)*vitr;
            wptr->displayParts();
        }
        else if(t == 5){
            wptr = (Wheeled*)*vitr;
            wptr->displayParts();
        }
        else if(t == 6){
            hptr = (HalfTrack*)*vitr;
            hptr->displayParts();
        }
    vitr++;}

}
