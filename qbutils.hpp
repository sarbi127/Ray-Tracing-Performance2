#ifndef QBRT_UTILS_H
#define QBRT_UTILS_H

#include <memory>
#include "qbVector.h"
#include "qbVector2.h"
#include "qbVector3.h"
#include "qbVector4.h"

namespace qbRT
{
	// Forward-declare the object base class.
	class ObjectBase;

	namespace DATA
	{
		struct hitData
		{
			qbVector3<double> poi		{3};
			qbVector3<double> normal	{3};
			qbVector3<double> color		{3};
			qbVector3<double> localPOI	{3};
			qbVector2<double> uvCoords	{2};
			std::shared_ptr<qbRT::ObjectBase> hitObject;
		};
	}

	namespace UTILS
	{
		void PrintVector(const qbVector3<double> &inputVector);
	}
}

#endif

