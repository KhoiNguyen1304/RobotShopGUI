#ifndef __ROBOTPART_H
#define	__ROBOTPART_H 2016

#include <string>

class RobotPart {
	public:

		RobotPart(std::string kname, int kpartNumber, double kweight, double kcost,
			      std::string kdescription, int kpartType);
		
		std::string GetName();
		int GetPartNumber();
		double GetWeight();
		double GetCost();
		std::string GetDescription();
		int getPartType();
		std::string PartType_toString();

		static const int TORSO = 0;
		static const int HEAD = 1;
		static const int ARM = 2;
		static const int LOCOMOTOR = 3;
		static const int BATTERY = 4;

	protected:

		std::string name;
		int partNumber;
		double weight;
		double cost;
		std::string description;
		int partType;
};
#endif