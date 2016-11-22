#ifndef __TRACKINGPART_H
#define __TRACKINGPART_H 2016

#include <string>

class TrackingParts {
	public:
		TrackingParts(std::string kTorsoName, std::string kHeadName, std::string oArmName,
		 std::string LocomotorName, std::string BatteryName);

		std::string GetTorsoName();

		std::string GetHeadName();

		std::string GetArmName();

		std::string GetLocomotorName();

		std::string GetBatteryName();

		std::string print();

	private:

		std::string TorsoName;

		std::string HeadName;

		std::string ArmName;

		std::string LocomotorName;

		std::string BatteryName;

};

#endif