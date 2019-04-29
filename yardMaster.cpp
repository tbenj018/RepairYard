// MainMenu.h
#include <iostream>
#include <list>
#include "menu.h"
#include "vehicle.h"
#include "tank.h"
#include "wheeled.h"
#include "halfTrack.h"

using namespace std;

void YardMaster::generateVehicles(ofstream& out){
    tptr = new Tank(1);
    tptr->addParts(gptr);
    tptr = new Tank(2);
    tptr->addParts(gptr);
    tptr = new Tank(3);
    tptr->addParts(gptr);
    wptr = new Wheeled(4);
    wptr->addParts4(gptr);
    wptr = new Wheeled(5);
    wptr->addParts5(gptr);
    hptr = new HalfTrack(6);
    hptr->addParts(gptr);
    vptr = tptr;
    vptr = wptr;
    vptr = hptr;
    MyVehicles.push_back(vptr);

  vitr = MyVehicles.begin();
  while(vitr != MyVehicles.end()){
      t = (*vitr)->getType();
      if(t == 1){
          tptr = (Tank*)*vitr;
          tptr->display(out);
      }
      else if(t == 2){
          tptr = (Tank*)*vitr;
          tptr->display(out);
      }
      else if(t == 3){
          tptr = (Tank*)*vitr;
          tptr->display(out);
      }
      else if(t == 4){
          wptr = (Wheeled*)*vitr;
          wptr->display(out);
      }
      else if(t == 5){
          wptr = (Wheeled*)*vitr;
          wptr->display(out);
      }
      else if(t == 6){
          hptr = (HalfTrack*)*vitr;
          hptr->display(out);
      }
  vitr++;}
}
/*
void menu(ofstream& out){
    list<Vehicle*> MyVehicles;
    list<Vehicle*>::iterator vitr;
    default_random_engine* gptr = new default_random_engine(time(NULL));

    Tank * tptr;
    Wheeled * wptr;
    HalfTrack * hptr;
    Vehicle * vptr;

    int t;
    char menuOption;

    while (menuOption != '8'){
      menuOption = menuDisplay();
      switch (menuOption) {
          case '1':{
              tptr = new Tank(1);
              tptr->addParts(gptr);
              vptr = tptr;
              MyVehicles.push_back(vptr);}
              break;
          case '2':{
              tptr = new Tank(2);
              tptr->addParts(gptr);
              vptr = tptr;
              MyVehicles.push_back(vptr);}
              break;
          case '3':{
              tptr = new Tank(3);
              tptr->addParts(gptr);
              vptr = tptr;
              MyVehicles.push_back(vptr);}
              break;
          case '4':{
              wptr = new Wheeled(4);
              wptr->addParts4(gptr);
              vptr = wptr;
              MyVehicles.push_back(vptr);}
              break;
          case '5':{
              wptr = new Wheeled(5);
              wptr->addParts5(gptr);
              vptr = wptr;
              MyVehicles.push_back(vptr);}
              break;
          case '6':{
              hptr = new HalfTrack(6);
              hptr->addParts(gptr);
              vptr = hptr;
              MyVehicles.push_back(vptr);}
              break;
          case '7':{
              vitr = MyVehicles.begin();
              while(vitr != MyVehicles.end()){
                  t = (*vitr)->getType();
                  if(t == 1){
                      tptr = (Tank*) *vitr;
                      tptr->display(out);
                  }
                  else if(t == 2){
                      tptr = (Tank*)*vitr;
                      tptr->display(out);
                  }
                  else if(t == 3){
                      tptr = (Tank*)*vitr;
                      tptr->display(out);
                  }
                  else if(t == 4){
                      wptr = (Wheeled*)*vitr;
                      wptr->display(out);
                  }
                  else if(t == 5){
                      wptr = (Wheeled*)*vitr;
                      wptr->display(out);
                  }
                  else if(t == 6){
                      hptr = (HalfTrack*)*vitr;
                      hptr->display(out);
                  }
              vitr++;}
              break;
          case '8':
              break;
          default:
              cout << "Invalid option selected!" << endl;
              break;
          }
      }
    }
}
*/
char menuDisplay(){
      char menuOption;

      cout << "Please Choose" << endl;
      cout << "1  To Generate and Add a Tank Type 1." << endl;
      cout << "2  To Generate and Add a Tank Type 2." << endl;
      cout << "3  To Generate and Add a Tank Type 3." << endl;
      cout << "4  To Generate and Add a Wheeled Vehicle Type 1." << endl;
      cout << "5  To Generate and Add a Wheeled Vehicle Type 2." << endl;
      cout << "6  To Generate and Add a HalfTrack" << endl;
      cout << "7  To Display All Vehicles." << endl;
      cout << "8  To Exit." << endl;

      cin >> menuOption;
      return menuOption;

}
