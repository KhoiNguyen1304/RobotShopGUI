#ifndef __ROBOTORDER_H
#define __ROBOTORDER_H 2016

#include <string>

class RobotOrder {
	public:
		RobotOrder(int korderNumber, std::string kdate, double kTotalPrice);

		int GetOrderNumber();
		std::string GetDate();
		double GetTotalPrice();
		//double GetShippingPrice();
		std::string print();

	private:
		int orderNumber;
		std::string date;
		double TotalPrice;
		double ShippingPrice;
};

#endif