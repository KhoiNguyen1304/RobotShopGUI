#include "RobotPart.h"
#include "Locomotor.h"
#include <iostream>
#include <sstream>

using namespace std;

Locomotor::Locomotor(std::string name, int partNumber, double weight, double cost,
			std::string description, int partType, double kPowerConsumeW, double kMaxSpeed) :
			RobotPart(name, partNumber, weight, cost, description, partType), PowerConsumeW(kPowerConsumeW), MaxSpeed(kMaxSpeed) {};

double Locomotor::GetMaxSpeed() {return MaxSpeed;};

double Locomotor::GetPowerConsumeW() {return PowerConsumeW;};

std::string Locomotor::print()
{
	ostringstream of;

	of << "Part name: " << GetName() 
	<< endl << "Part #: " << GetPartNumber() 
	<< endl << "Weight: " << GetWeight() 
	<< endl << "Cost: " << GetCost()
	<< endl << "Power consume: " << GetPowerConsumeW()
	<< endl << "Max speed: " << GetMaxSpeed()
	<< endl << "Description: " << GetDescription() << endl;

	return of.str();
}			 