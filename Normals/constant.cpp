#include "constant.hpp"

// Constructor / destructor.
qbRT::Normal::Constant::Constant()
{

}

qbRT::Normal::Constant::~Constant()
{

}

qbVector3<double> qbRT::Normal::Constant::ComputePerturbation(const qbVector3<double> &normal, const qbVector2<double> &uvCoords)
{
	return PerturbNormal(normal, m_displacement);
}

