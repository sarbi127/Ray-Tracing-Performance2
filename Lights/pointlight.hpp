#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "lightbase.hpp"

namespace qbRT
{
	class PointLight : public LightBase
	{
		public:
			// The default constructor.
			PointLight();
			
			// Override the default destructor.
			virtual ~PointLight() override;
			
			// Function to compute illumination.
			virtual bool ComputeIllumination(	const qbVector3<double> &intPoint, const qbVector3<double> &localNormal,
																				const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																				const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																				qbVector3<double> &color, double &intensity) override;
	};
}

#endif
