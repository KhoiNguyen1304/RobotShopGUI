#include "RobotPart.h"
#include "RobotModel.h"
#include <string>

RobotModel::RobotModel(std::string kname, int kmodelNumber, double kprice) :
					   name(kname), modelNumber(kmodelNumber), price(kprice) {}
std::string RobotModel::GetName() { return name; }
int RobotModel::GetModelNumber() { return modelNumber; }
double RobotModel::GetPrice() { return price; }