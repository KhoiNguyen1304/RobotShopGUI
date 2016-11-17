#include "TrackingParts.h"
#include <string>

TrackingParts::TrackingParts(std::string kTorsoName, double kTorsoPrice, std::string kHeadName, double kHeadPrice, std::string kArmName,
		double kArmPrice, std::string kLocomotorName, double kLocomotorPrice, std::string kBatteryName, double kBatteryPrice) :
		TorsoName(kTorsoName), TorsoPrice(kTorsoPrice), HeadName(kHeadName), HeadPrice(kHeadPrice), ArmName(kArmName), ArmPrice(kArmPrice),
		LocomotorName(kLocomotorName), LocomotorPrice(kLocomotorPrice), BatteryName(kBatteryName), BatteryPrice(kBatteryPrice) {}

std::string TrackingParts::GetTorsoName() { return TorsoName; }
double TrackingParts::GetTorsoPrice() { return TorsoPrice; }
std::string TrackingParts::GetHeadName() { return HeadName; }
double TrackingParts::GetHeadPrice() { return HeadPrice; }
std::string TrackingParts::GetArmName() { return ArmName; }
double TrackingParts::GetArmPrice() { return ArmPrice; }
std::string TrackingParts::GetLocomotorName() { return LocomotorName; }
double TrackingParts::GetLocomotorPrice() { return LocomotorPrice; }
std::string TrackingParts::GetBatteryName() { return BatteryName; }
double TrackingParts::GetBatteryPrice() { return BatteryPrice; }