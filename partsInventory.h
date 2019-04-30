#ifndef PARTSINVENTORY_H
#define PARTSINVENTORY_H

#include "vehicle.h"
#include <list>
#include <random>

using namespace std;

class PartsInventory
{
    public:
        partsInventory();

        list<int> getNewParts();

        list<int> getUsedParts();

        int numberOfNewParts();

        int numberOfUsedParts();

        void ArrivingParts();

    private:
        list<int> newParts;
        list<int> usedParts;
        default_random_engine *engine = new default_random_engine(rand());

};

#endif // PARTSINVENTORY_h
