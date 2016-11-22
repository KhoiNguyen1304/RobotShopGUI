#include "TrackingParts.h"
#include <string>
#include <sstream>

using namespace std;

TrackingParts::TrackingParts(std::string kTorsoName, std::string kHeadName, std::string kArmName,
		std::string kLocomotorName, std::string kBatteryName) :
		TorsoName(kTorsoName), HeadName(kHeadName), ArmName(kArmName),
		LocomotorName(kLocomotorName), BatteryName(kBatteryName) {}

std::string TrackingParts::GetTorsoName() { return TorsoName; }

std::string TrackingParts::GetHeadName() { return HeadName; }

std::string TrackingParts::GetArmName() { return ArmName; }

std::string TrackingParts::GetLocomotorName() { return LocomotorName; }

std::string TrackingParts::GetBatteryName() { return BatteryName; }

std::string TrackingParts::print()
{
	ostringstream of;

	of << "Torso name: " << GetTorsoName()
	<< endl << "Head name: " << GetHeadName()
	<< endl << "Arm name: " << GetArmName()
	<< endl << "Locomotor name: " << GetLocomotorName()
	<< endl << "Battery name: " << GetBatteryName() << endl;

	return of.str();
}
