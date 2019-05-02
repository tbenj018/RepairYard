#include <iostream>
#include <fstream>
#include <list>

#include "vehicle.h"
#include "tank.h"
#include "wheeled.h"
#include "halfTrack.h"
#include "yardMaster.h"
#include "repairYard.h"
#include "repairBay.h"

using namespace std;

int main(){
  string filename;
/*	// creates the yardmaster to manage the repair yard
	YardMaster *yardMaster = new YardMaster(repairYard, days, filename);

	// executes his job of managing the yard.
	yardMaster->manageYard(yardMaster->out);*/
  cout << "Please enter a file name: ";
  cin >> filename;

  RepairYard *master = new RepairYard(filename);

  Vehicle vee;

  master->generateVehicles(master->out);

}
