#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <string>

class Customer {
	public:
		Customer(std::string kname, std::string kcusNumber, std::string kaddress, double kwallet);
		std::string GetName();
		std::string GetCusNumber();
		std::string GetAddress();
		double GetWallet();
		std::string print();
	private:
		std::string name;
		std::string cusNumber;
		std::string address;
		double wallet;
};
#endif