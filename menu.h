/*#ifndef YARDMASTER_H_INCLUDED
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
    ofstream& out;

    int t;

public:
void generateVehicles();
char menuDisplay();
// User chooses to generate specific vehicles








};

#endif // YARDMASTER_H_INCLUDED*/
