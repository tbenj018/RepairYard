#ifndef REPAIRBAY_H_INCLUDED
#define REPAIRBAY_H_INCLUDED
#include "partsInventory.h"
#include "vehicle.h"
#include <iostream>
#include <queue>
#include <vector>       // std::vector
#include <random>
#include <fstream>
class RepairBay
{
  public:
    static int bayNumber;

    PartsInventory *inventory;

    priority_queue<Vehicle,vector<Vehicle*>> *pQueue;

    default_random_engine * engine = new default_random_engine(time(NULL));

    ~RepairBay();

    RepairBay(PartsInventory* passedInventory);

    void repairAndTest();
    //returns whether a vehicle passed tests
    bool  testVehicle(ofstream& out);

    bool  isOccupied();

    // changes the status of vehicle to in repair
    void changeStatus();

    // subtracts one time unit from the vehicle
    void minusTimeReq();

    void setComplete(ofstream& out);

    Vehicle* returnComplete();

    // display information about the bay
    void display(ostream &out);

    bool isPartAvailable();

    void placeInBay(Vehicle *vehicle, ofstream&);

    bool wasTested();

  private:
    //vehicle pointer
    // the vehicle in repair
    Vehicle* vPtr;
    int id;
    bool tested;

};
// sets the static variable.
#endif
