#include "Customer.h"	

Customer::Customer(std::string kname, std::string kcusNumber, double kwallet) :
		name(kname), cusNumber(kcusNumber), wallet(kwallet) {}

std::string Customer::GetName() { return name; }
std::string Customer::GetCusNumber() { return cusNumber; }
double Customer::GetWallet() { return wallet; }