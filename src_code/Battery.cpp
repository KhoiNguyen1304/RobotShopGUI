#include "RobotPart.h"
#include "Battery.h"
#include <iostream>
#include <sstream>

using namespace std;

Battery::Battery(std::string name, int partNumber, double weight, double cost,
			 std::string description, int partType, double kilowattHours) :
			 RobotPart(name, partNumber, weight, cost, description, partType), KilowattHours(kilowattHours) {};

double Battery::GetKilowattHours() {return KilowattHours;};

std::string Battery::print()
{
	ostringstream of;

	of << "Part name: " << GetName() 
	<< endl << "Part #: " << GetPartNumber() 
	<< endl << "Weight: " << GetWeight() 
	<< endl << "Cost: " << GetCost()
	<< endl << "KiloWatt/Hour: " << GetKilowattHours()
	<< endl << "Description: " << GetDescription() << endl;

	return of.str();
}