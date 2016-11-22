#include "RobotPart.h"
#include "RobotModel.h"
#include <string>
#include <sstream>

using namespace std;

RobotModel::RobotModel(std::string kname, int kmodelNumber, double kprice) :
					   name(kname), modelNumber(kmodelNumber), price(kprice) {}
std::string RobotModel::GetName() { return name; }
int RobotModel::GetModelNumber() { return modelNumber; }
double RobotModel::GetPrice() { return price; }

std::string RobotModel::print()
{
	ostringstream of;

	of << "Model's name: " << GetName() 
	<< endl << "Model's number: " << GetModelNumber()
	<< endl << "Model's price: " << GetPrice() << endl;

	return of.str();
}