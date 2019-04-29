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
  //menu(menu->out);
  ofstream& report = ("Report.txt", ofstream::out );
  YardMaster vee;
  vee.generateVehicles(report);
}
