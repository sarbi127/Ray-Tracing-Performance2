#include "lightbase.hpp"

// Constructor.
qbRT::LightBase::LightBase()
{

}

// Destructor.
qbRT::LightBase::~LightBase()
{

}

// Function to compute illumination.
bool qbRT::LightBase::ComputeIllumination(	const qbVector3<double> &intPoint, const qbVector3<double> &localNormal,
																						const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																						const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																						qbVector3<double> &color, double &intensity)
{
	return false;
}
