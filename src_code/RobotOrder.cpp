#include "RobotOrder.h"

RobotOrder::RobotOrder(int korderNumber, std::string kdate, double kTotalPrice, double kShippingPrice) :
	orderNumber(korderNumber), date(kdate), TotalPrice(kTotalPrice), ShippingPrice(kShippingPrice) {}

int RobotOrder::GetOrderNumber() { return orderNumber; }

std::string RobotOrder::GetDate() { return date; }
double RobotOrder::GetTotalPrice() { return TotalPrice; }
//double Order::GetShippingPrice() { return ShippingPrice; }