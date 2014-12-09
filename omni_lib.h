#ifndef OMNI_LIB_H
#define OMNI_LIB_H

#include <vector>

#pragma once

namespace WMRA{
	class Pose;
	typedef unsigned int HHD;
};

namespace WMRA{
	class omni{
	public:
		omni();
		~omni();
		WMRA::Pose getDeltaPose();
		bool checkButton1();
		bool checkButton2();
		int isInitialized();
		bool forceToOrigin();
		bool setForceFeedback(double X, double Y, double Z);
		bool setForceFeedback(double forceMag);
		std::vector<double> getTorqueData();
		std::vector<double> getPositionData();
		std::vector<double> getOrientationData();
		std::vector<double> getVelocityData();
	private:
		HHD hHD;
		int initialized;
	};
};

#endif;