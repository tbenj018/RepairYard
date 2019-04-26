// vehicle.h
#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>
#include <random>
#include <list>
#include <ctime>

using namespace std;

class Vehicle{
protected:
  int Tid;
  list<int> gParts;
  list<int>::iterator Pitr;
  list<int> bParts;

public:
  Vehicle(){Tid=0;}
  Vehicle(int i){Tid=i;}
  int getType(){return Tid;}
  /*
  Tanks: type 1 has parts that have id numbers 1 through 11
                type 2 has parts that are even numbered 2 through 22
                type 3 has parts that are numbered 3 through 33 but are multiples of 3
  wheeled: type 1 has parts that are numbered 31 through 40
                     type 2 has parts that are numbered 36 through 45
  half track vehicles have parts numbered 1 through 5 and 31 through 40
  The average number of damaged parts is 3 with standard deviation of 1 for tanks
  and 5 with standard deviation of 2 for wheeled AND half tracks.
    base class is vehicles
  */
/*  void addParts(default_random_engine* gptr){
      uniform_int_distribution<int> Pdist(1,100);
      for(int i = 1; i < 40; i++){
        for(int j = 1; i < 12; i++){
          int p = Pdist(*gptr);
              if(p > 66){
                  bParts.push_back(i * Tid);
              }
              else{
                  gParts.push_back(i * Tid);
              }
      }}
  }*/
  void display(){
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
      cout<<" ] "<<endl;
      cout<<" Reject list [ ";
      Pitr=bParts.begin();
      while(Pitr!=bParts.end())
      {
          cout<<*Pitr;
          Pitr++;
          if(Pitr!=bParts.end()){cout<<", ";}
          else{cout<<" ";}
      }
      cout<<" ] "<<endl<<endl;

  }
};

#endif // VEHICLE_H_INCLUDED
