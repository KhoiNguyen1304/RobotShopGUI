#ifndef __TORSO_H
#define __TORSO_H 2016

#include "RobotPart.h"

class Torso: public RobotPart {
	public:
		Torso(std::string kname, int kpartNumber, double kweight, double kcost,
			  std::string kdescription, int kpartType, int kBatteryCompartments);
		int GetBatteryCompartmentSize();
		std::string print();
	private:
		int BatteryCompartments;

};
#endif