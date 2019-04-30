#include <iostream>
#include <fstream>
#include <list>

#include "vehicle.h"
#include "tank.h"
#include "wheeled.h"
#include "halfTrack.h"
#include "yardMaster.h"

using namespace std;

int main(){
  string filename;

  cout << "Enter file name: ";
  cin >> filename;

  YardMaster master(filename);

  master.VehicleList();

}
