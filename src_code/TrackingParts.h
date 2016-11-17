#ifndef __TRACKINGPART_H
#define __TRACKINGPART_H 2016

#include <string>

class TrackingParts {
	public:
		TrackingParts(std::string kTorsoName, double kTorsoPrice, std::string kHeadName, double kHeadPrice, std::string oArmName,
		 double kArmPrice, std::string LocomotorName, double kLocomotorPrice, std::string BatteryName, double kBatteryPrice);

		std::string GetTorsoName();
		double GetTorsoPrice();
		std::string GetHeadName();
		double GetHeadPrice();
		std::string GetArmName();
		double GetArmPrice();
		std::string GetLocomotorName();
		double GetLocomotorPrice();
		std::string GetBatteryName();
		double GetBatteryPrice();
	private:

		std::string TorsoName;
		double TorsoPrice;
		std::string HeadName;
		double HeadPrice;
		std::string ArmName;
		double ArmPrice;
		std::string LocomotorName;
		double LocomotorPrice;
		std::string BatteryName;
		double BatteryPrice;
};

#endif