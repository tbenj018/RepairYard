#include "partsInventory.h"
#include <random>
#include <ctime>

PartsInventory::partsInventory()
{
    generateArrivingParts();
}

list<int> PartsInventory::getNewParts()
{
    return newParts;
}

list<int> PartsInventory::getUsedParts()
{
    return usedParts;
}

void PartsInventory::addVehicleToStrip(Vehicle *vee)
{
    list<int> workingParts = vee->getWorkingParts();
    for (unsigned int i = 0; i < workingParts.size(); i++)
    {
        usedParts.push_back(workingParts[i]);
    }
}

int PartsInventory::numberOfNewParts()
{
    return newParts.size();
}

int PartsInventory::numberOfUsedParts()
{
    return usedParts.size();
}

void PartsInventory::ArrivingParts()
{
    rand();
    if (usedParts.size() %18 == 0)
        srand(time(NULL)+usedParts.size());
    else if (usedParts.size() %8 == 1)
        srand(time(NULL)+rand());
    else srand(time(NULL));
    engine = new default_random_engine(rand());
    uniform_int_distribution<int> numNewPartsRan(1, 6);
    int numNewParts = numNewPartsRan(*engine);
    uniform_int_distribution<int> genNewParts(1, 45);
    for (int i = 0; i < numNewParts; i++)
    {
        newParts.push_back(genNewParts(*engine));
    }
}
