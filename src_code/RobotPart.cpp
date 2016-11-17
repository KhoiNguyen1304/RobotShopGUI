#include "RobotPart.h"


RobotPart::RobotPart(std::string kname, int kpartNumber, double kweight, double kcost,
					 std::string kdescription, int kpartType) : name(kname),
    partNumber(kpartNumber), weight(kweight), cost(kcost), description(kdescription), partType(kpartType) {}

std::string RobotPart::GetName() {return name;}

int RobotPart::GetPartNumber() {return partNumber;}

double RobotPart::GetWeight() {return weight;}

double RobotPart::GetCost() {return cost;}

std::string RobotPart::GetDescription() {return description;}

int RobotPart::getPartType() {return partType;}

std::string RobotPart::PartType_toString() {
	switch(getPartType()) {
		case(TORSO) : return "Torso";
		case(HEAD) : return "Head";
		case(ARM) : return "Arm";
		case(LOCOMOTOR) : return "Locomotor";
		case(BATTERY) : return "Battery";
	}
	return 0;
}