#ifndef SDFUNC_H
#define SDFFUNC_H

#include "../qbVector.h"
#include "../qbVector2.h"
#include "../qbVector3.h"
#include "../qbVector4.h"

namespace qbRT
{
	namespace RM
	{
		namespace SDF
		{
			double Sphere(const qbVector3<double> &p, const qbVector3<double> &center, const qbVector3<double> &parms);
			double Torus(const qbVector3<double> &p, const qbVector3<double> &center, const qbVector3<double> &parms);
			double Box(const qbVector3<double> &p, const qbVector3<double> &center, const qbVector3<double> &parms);
		}
	}
}

#endif

