#ifndef __HEAD_H
#define __HEAD_H 2016

#include "RobotPart.h"

class Head: public RobotPart {
	public:
		Head(std::string name, int partNumber, double weight, double cost,
			 std::string description, int partType);
};

#endif