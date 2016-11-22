#include "sale.h"
#include <sstream>

using namespace std;

Sale::Sale(std::string kname, std::string kENumber) :
		name(kname), ENumber(kENumber) {}

std::string Sale::GetName() { return name; }
std::string Sale::GetENumber() { return ENumber; }

std::string Sale::print()
{
	ostringstream of;

	of << "Employee's name: " << GetName() 
	<< endl << "Employee's number: " << GetENumber() << endl;

	return of.str();
}