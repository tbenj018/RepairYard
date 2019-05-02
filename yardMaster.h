#ifndef YARDMASTER_H_INCLUDED
#define YARDMASTER_H_INCLUDED

#include <iostream>
#include <fstream>
#include "vehicle.h"
#include "tank.h"
#include "wheeled.h"
#include "halfTrack.h"
//#include "repairYard.h"

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

    bool checkForParts(Vehicle *vehicle, ofstream& out);

    void addVehicleToBay(Vehicle Vehicle);

    void beginNewDay(ofstream& out);

    bool isVehInWaitinglist(Vehicle* vehicle);

    int numberOfArrivals;

    //RepairYard *repairYard;

  //uniform_int_distribution<int> Pdist(1,100);

public:
    YardMaster(string filename);
    YardMaster();

  //YardMaster(RepairYard *repairYard, int desiredDays,  string fileName);
    ~YardMaster();
    void addHour(ofstream& out);
    void manageYard(ofstream& out);
    void anotherRun();


  //RepairYard* getRepairYard();

    ofstream out;


};

#endif // YARDMASTER_H_INCLUDED
