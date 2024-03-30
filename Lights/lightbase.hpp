#ifndef LIGHTBASE_H
#define LIGHTBASE_H

#include <memory>
#include "../qbVector.h"
#include "../ray.hpp"
#include "../Primatives/objectbase.hpp"

namespace qbRT
{
	class LightBase
	{
		public:
			// Constructor / destructor.
			LightBase();
			virtual ~LightBase();
			
			// Function to compute illumination contribution.
			virtual bool ComputeIllumination(	const qbVector3<double> &intPoint, const qbVector3<double> &localNormal,
																				const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																				const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																				qbVector3<double> &color, double &intensity);
																				
		public:
			qbVector3<double>	m_color			{3};
			qbVector3<double>	m_location	{3};
			double						m_intensity;
	};
}

#endif

