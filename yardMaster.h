#ifndef YARDMASTER_H_INCLUDED
#define YARDMASTER_H_INCLUDED

#include <iostream>
#include <fstream>
#include "vehicle.h"
#include "tank.h"
#include "wheeled.h"
#include "halfTrack.h"

class YardMaster{
private:
    // A private pointer to the repair yard passed into the constructor
    RepairYard *repairYard;

  // This is the number days that the
  // program should run for
    int desiredDays;

  // running total of days
  // number of days since start of simulation.
  // the yard master is the bad boss that hovers over your shoulder and says
  // is the iPhone fixed yet and you say no I am testing it
  // and then she says well the lady is waiting in the lobby and looks
  // annoyed. Then comes through every hour and sticks her nose in everyones business
  // and complains about how we are slow and suck.
    int numDays;

  // simulation runs on military time
    int hours2400;

  // decides which new arrivals are any good
    void manageNewArrivals(list<Vehicle*> newArrivals, ofstream& out);

  // places vehicles that are awaiting a part in the repair queue.
    void manageWaitlist(ofstream& out);

    void repairOrScrap(Vehicle * aVeh, int partsRatio, ofstream& out);

    void sendToScrap();

    bool checkStatus();

    bool checkForParts(Vehicle *aVeh, ofstream& out);

    bool checkInventory();

    void addVehicleToBay(Vehicle Vehicle);

    void beginNewDay(ofstream& out);

    bool isVehInWaitinglist(Vehicle* vehicle);
protected:
    list<Vehicle*> MyVehicles;
    list<Vehicle*>::iterator vitr;
    default_random_engine* gptr = new default_random_engine(time(NULL));

    Tank * tptr;
    Wheeled * wptr;
    HalfTrack * hptr;
    Vehicle * vptr;


    int t;

//uniform_int_distribution<int> Pdist(1,100);

public:
    yardMaster();
    void generateVehicles(ofstream& out);
    YardMaster(RepairYard *repairYard, int desiredDays,  string fileName);
        ~YardMaster();
        void addHour(ofstream& out);

        void manageYard(ofstream& out);
        void anotherRun();

        RepairYard* getRepairYard();

        ofstream out;

};

#endif // YARDMASTER_H_INCLUDED
