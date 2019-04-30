#ifndef YARDMASTER_H_INCLUDED
#define YARDMASTER_H_INCLUDED

#include <iostream>
#include <fstream>
#include "vehicle.h"
#include "tank.h"
#include "wheeled.h"
#include "halfTrack.h"

class YardMaster{
protected:
    list<Vehicle*> MyVehicles;
    list<Vehicle*>::iterator vitr;
    default_random_engine* gptr = new default_random_engine(time(NULL));

    Tank * tptr;
    Wheeled * wptr;
    HalfTrack * hptr;
    Vehicle * vptr;

    int t;
private:
    void manageNewArrivals(list<Vehicle*> newArrivals, ofstream& out);

    void repairOrScrap(Vehicle * vee, int partsRatio, ofstream& out);

    void sendToScrap();

    bool checkStatus();

    bool checkForParts(Vehicle *vee, ofstream& out);

    bool checkInventory();

    void addVehicleToBay(Vehicle Vehicle);

    void beginNewDay(ofstream& out);

    bool isVehInWaitinglist(Vehicle* vehicle);

    int numberOfArrivals;

  //uniform_int_distribution<int> Pdist(1,100);

public:
    //YardMaster();
    YardMaster(string filename);

  //YardMaster(RepairYard *repairYard, int desiredDays,  string fileName);
    ~YardMaster();
    void addHour(ofstream& out);

    void VehicleList();

    void manageYard(ofstream& out);
    void anotherRun();
    void generateVehicles();

  //RepairYard* getRepairYard();

    ofstream out;


};

#endif // YARDMASTER_H_INCLUDED
