#include "Head.h"
#include "RobotPart.h"
#include <sstream>
#include <iostream>

using namespace std;

Head::Head(std::string name, int partNumber, double weight, double cost,
		   std::string description, int partType) :
	RobotPart(name, partNumber, weight, cost, description, partType) {};

std::string Head::print()
{
	ostringstream of;

	of << "Part name: " << GetName() 
	<< endl << "Part #: " << GetPartNumber() 
	<< endl << "Weight: " << GetWeight() 
	<< endl << "Cost: " << GetCost()
	<< endl << "Battery Comp: " << GetDescription() << endl;

	return of.str();
}