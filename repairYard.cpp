#include "repairYard.h"
#include "repairBay.h"
using namespace std;

#include <random>
#include <iostream>
#include <fstream>

RepairYard::RepairYard(string filename){
  	out.open(filename);
}

RepairYard::~RepairYard(){
  	out.close();
}

void RepairYard::generateVehicles(ofstream& out){

    uniform_int_distribution<int> vehicleType(1, 6);
    srand(time(NULL));
    int randNum = (rand() % 5) + 1;
    for(int i = 1; i <= randNum; i++ ){
      int v = vehicleType(*gptr);
        if(v == 1){
            tptr = new Tank(1);
            tptr->addParts(gptr);
            vptr = tptr;
            MyVehicles.push_back(vptr);
            //i++;
        }
        else if(v == 2 ){
            tptr = new Tank(2);
            tptr->addParts(gptr);
            vptr = tptr;
            MyVehicles.push_back(vptr);
            //i++;
        }
        else if(v == 3 ){
            tptr = new Tank(3);
            tptr->addParts(gptr);
            vptr = tptr;
            MyVehicles.push_back(vptr);
            //i++;
        }
        else if(v == 4 ){
            wptr = new Wheeled(4);
            wptr->addParts4(gptr);
            vptr = wptr;
            MyVehicles.push_back(vptr);
            //i++;
        }
        else if(v == 5 ){
            wptr = new Wheeled(5);
            wptr->addParts5(gptr);
            vptr = wptr;
            MyVehicles.push_back(vptr);
            //i++;
        }
        else{
            hptr = new HalfTrack(6);
            hptr->addParts(gptr);
            vptr = hptr;
            MyVehicles.push_back(vptr);
            //i++;
        }
        vitr = MyVehicles.begin();
        while(vitr != MyVehicles.end()){
            t = (*vitr)->getType();
            if(t == 1){
                tptr = (Tank*) *vitr;
                tptr->displayParts(out);
            }
            else if(t == 2){
                tptr = (Tank*)*vitr;
                tptr->displayParts(out);
            }
            else if(t == 3){
                tptr = (Tank*)*vitr;
                tptr->displayParts(out);
            }
            else if(t == 4){
                wptr = (Wheeled*)*vitr;
                wptr->displayParts(out);
            }
            else if(t == 5){
                wptr = (Wheeled*)*vitr;
                wptr->displayParts(out);
            }
            else if(t == 6){
                hptr = (HalfTrack*)*vitr;
                hptr->displayParts(out);
            }
        vitr++;}

    }


}
