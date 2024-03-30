#ifndef RAY_H
#define RAY_H

#include "qbVector.h"
#include "qbVector2.h"
#include "qbVector3.h"
#include "qbVector4.h"

namespace qbRT
{
	class Ray
	{
		public:
			Ray();
			Ray(const qbVector3<double> &point1, const qbVector3<double> &point2);
			
			qbVector3<double> GetPoint1() const;
			qbVector3<double> GetPoint2() const;
			
		public:
			qbVector3<double> m_point1;
			qbVector3<double> m_point2;
			qbVector3<double> m_lab;
			
	};
}

#endif
