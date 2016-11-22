#include "RobotOrder.h"
#include <sstream>

using namespace std;

RobotOrder::RobotOrder(int korderNumber, std::string kdate, double kTotalPrice) :
	orderNumber(korderNumber), date(kdate), TotalPrice(kTotalPrice) {}

int RobotOrder::GetOrderNumber() { return orderNumber; }

std::string RobotOrder::GetDate() { return date; }
double RobotOrder::GetTotalPrice() { return TotalPrice; }
//double Order::GetShippingPrice() { return ShippingPrice; }

std::string RobotOrder::print()
{
	ostringstream of;

	of << "Order's #: " << GetOrderNumber() 
	<< endl << "Order's date: " << GetDate()
	<< endl << "Order's price: " << GetTotalPrice() << endl;

	return of.str();
}