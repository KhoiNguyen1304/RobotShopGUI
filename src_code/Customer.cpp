#include "Customer.h"
#include <sstream>	

using namespace std;

Customer::Customer(std::string kname, std::string kcusNumber, std::string kaddress, double kwallet) :
		name(kname), cusNumber(kcusNumber), address(kaddress), wallet(kwallet) {}

std::string Customer::GetName() { return name; }
std::string Customer::GetCusNumber() { return cusNumber; }
std::string Customer::GetAddress() { return address; }
double Customer::GetWallet() { return wallet; }

std::string Customer::print()
{
	ostringstream of;

	of << "Customer's name: " << GetName() 
	<< endl << "Phone #: " << GetCusNumber() 
	<< endl << "Address: " << GetAddress()
	<< endl << "Wallet: " << GetWallet() << endl;

	return of.str();
}