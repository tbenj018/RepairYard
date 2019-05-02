#ifndef REPAIRYARD_H_INCLUDED
#define REPAIRYARD_H_INCLUDED
#include <list>
#include <queue>
#include <random>
#include <time.h>
#include "repairBay.h"
#include "vehicle.h"
#include "tank.h"
#include "wheeled.h"
#include "halfTrack.h"
#include "partsInventory.h"
#include <tuple>
#include <fstream>

using namespace std;

struct LessThanByP
{
    bool operator()( Vehicle * lhs, Vehicle * rhs)
    {
        return lhs->getRepairTime() > rhs->getRepairTime();
    }
};

class RepairYard
{
protected:
    list<Vehicle*> MyVehicles;
    list<Vehicle*>::iterator vitr;
    default_random_engine* gptr = new default_random_engine(time(NULL));

    Tank * tptr;
    Wheeled * wptr;
    HalfTrack * hptr;
    Vehicle * vptr;

    int t;
public:
    RepairYard(PartsInventory *passedInInventory);
    RepairYard(string filename);
    ~RepairYard();
    default_random_engine *  randomEngine = new default_random_engine(time(NULL));


private:
        // inventory pointer
    PartsInventory *inventory;
    list<RepairBay*>::iterator bayItr;
        // Three repair bays should be stored in vector or list
    list<RepairBay*> repairBays;
        // Priority Que to store vehicles
    priority_queue<Vehicle*,vector<Vehicle*>, LessThanByP> pQueue;
        // vehicle pointer
    Vehicle *vPtr;
        // list of arrived vehicles that were generated that day in the class.
    std::vector<Vehicle*>arrived;

    int totalFixed;
    int fixedToday;
    int numberOfDays;
    int numberOfArrivals;

public:

        /*
        *  Generates a list of tanks that have broken parts
        *  this uses the vehicle classes create tank function.
        *  This function uses that capability and stores them.
        */
        void generateNewArrivals();
        void generateVehicles(ofstream& out);
        // returns repair bay objects
        vector<RepairBay*> getRepairBays();

        // returns total fixed since start of application
        int getTotalFixed();

        // get numberFixed that day
        int getFixedToday();

        // adds to the number of fixed in a day
        void addFixed( int numberOfFixed);

        // rests number of finished in a day and adds one to days
        void endOfDay(ofstream &out);

        // displays the vehicles that are in the arrived vector
        void displayArrived(ostream &out, ofstream& outs);

        // displays a bay that is contained in the repairYard
        void displayBay(ostream &out, ofstream& outs);

        // displays what is waiting to be fixed
        void displayQueue(ostream &out);

        // adds one to the number of fixed
        void addFixed();

        // removes the first element of the arrived list.
        void removeFromArrived();

        // returns the inventory pointer
        PartsInventory* getInventory();

        // checks if there is an open bay and returns the open bays.
        list<RepairBay*> checkBays();

        // returns the arrived vector
        list<Vehicle*> getArrived();

        priority_queue<Vehicle*,vector<Vehicle*>, LessThanByP>* getPQueue();

        ofstream out;
};
#endif
