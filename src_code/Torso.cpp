#include "Torso.h"
#include <iostream>
#include <sstream>

using namespace std;

Torso::Torso(std::string kname, int kpartNumber, double kweight, double kcost,
			  std::string kdescription, int kpartType, int kBatteryCompartments) :
RobotPart(kname, kpartNumber, kweight, kcost, kdescription, kpartType), BatteryCompartments(kBatteryCompartments) {}

int Torso::GetBatteryCompartmentSize() {return BatteryCompartments;}

std::string Torso::print()
{
	ostringstream of;

	of << "Part name: " << GetName() 
	<< endl << "Part #: " << GetPartNumber() 
	<< endl << "Weight: " << GetWeight() 
	<< endl << "Cost: " << GetCost()
	<< endl << "Battery Comp: " << GetBatteryCompartmentSize()
	<< endl << "Description: " << GetDescription() << endl;

	return of.str();
}