// MainMenu.h
#include <iostream>
#include <random>
#include <list>
#include "yardMaster.h"
#include "vehicle.h"
#include "tank.h"
#include "wheeled.h"
#include "halfTrack.h"


using namespace std;

YardMaster::YardMaster(){

}

YardMaster::YardMaster(string filename){
  	out.open(filename);
}

YardMaster::~YardMaster(){
    out.close();
}

void YardMaster::manageNewArrivals(list<Vehicle*> MyVehicles, ofstream& out){
  //  generateVehicles();
    for(auto vee: MyVehicles){
        list<int>brokenParts = vee->getBrokenParts();
        list<int>goodParts = vee->getWorkingParts();

        int totalPartHours=0;
        int totalBrokenParts=0;
		    int totalWorkingParts=0;
		    int i = 0;

        for(auto partsWorking: vee->getWorkingParts()){
            totalPartHours += partsWorking;
            totalWorkingParts += partsWorking;
            i++;
        }

        for(auto partsBroken: vee->getBrokenParts()){
            totalPartHours += partsBroken;
            totalWorkingParts += partsBroken;
            i++;
        }

        vee->setRepairTime(totalBrokenParts);


    }
}
/*
void YardMaster::repairOrScrap(Vehicle * vehicle, int partsRatio, ofstream& out){

	if (partsRatio <= .7)
	{
		bool partsAvailable = checkForParts(vehicle, out);
		if (partsAvailable== true)
		{
			//repairYard->getPQueue()->push(aVeh);
			vehicle->setStatus("In RepairQueue", out);
		}
	}
	else
	{

		vehicle->setStatus("being stripped for parts and thrown away.", out);

	}
}*/
/*
bool YardMaster::checkForParts(Vehicle * vehicle, ofstream& out){
	list<int> brokenParts = vehicle->getBrokenParts();
	Inventory* inventory = repairYard->getInventory();
	list<int> newParts = inventory->getNewParts();
	list<int> usedParts = inventory->getUsedParts();
	list<int>::iterator partsItr;
	bool foundEveryPart = true;
	// Used to check if the part is in the list
	auto checkForPart = [](list<int>::iterator& itr, list<int>& parts, bool& pf, int bp) {
        itr = parts.begin();
        while (itr != parts.end())
        {
            if (*itr == bp)
            {
                pf = true;
                break;
            }
            itr++;
        }
	};
	// Checking if every broken part has an associated used/new part
	for (int brokenPart : brokenParts)
    {
        bool partFound = false;
        checkForPart(partsItr, usedParts, partFound, brokenPart);
        if (partFound) continue; // No need to check new parts if it was found in the used parts
        checkForPart(partsItr, newParts, partFound, brokenPart);
        // If the part is still not found it needs to go to the waiting list
        if (!partFound)
        {
            foundEveryPart = false;
            break;
        }
    }

    if (foundEveryPart)
    {
        return true;
    }
    else
    {
    	if (isVehInWaitinglist(vehicle)== false)
    	{
    	auto aVehicleTuple = make_tuple(vehicle,0);
    	vehicle->setStatus("in waiting list for part", out);
        repairYard->getWaitingVehicles()->push_back(aVehicleTuple);
    	}
        return false;
    }
}*/
