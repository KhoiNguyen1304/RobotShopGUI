#ifndef __SALE_H
#define __SALE_H 2016

#include <string>

class Sale {
	public:
		Sale(std::string kname, std::string kENumber);
		std::string GetName();
		std::string GetENumber();
		std::string print();
	private:
		std::string name;
		std::string ENumber;
};
#endif