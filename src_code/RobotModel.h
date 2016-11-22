#ifndef __ROBOTMODEL_H
#define	__ROBOTMODEL_H 2016

#include "RobotPart.h"
#include <string>


class RobotModel {
	public:
		RobotModel(std::string kname, int kmodelNumber, double kprice);
		std::string GetName();
		int GetModelNumber();
		double GetPrice();
		std::string print();

	private:
		std::string name;
		int modelNumber;
		double price;
};

#endif