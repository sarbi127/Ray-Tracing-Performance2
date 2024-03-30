#include "gradient.hpp"

// Constructor.
qbRT::Texture::Gradient::Gradient()
{

}

// Destructor.
qbRT::Texture::Gradient::~Gradient()
{

}

// Function to return the color.
qbVector4<double> qbRT::Texture::Gradient::GetColor(const qbVector2<double> &uvCoords)
{
	// Apply the local transform to the (u,v) coordinates.
	qbVector2<double> inputLoc = uvCoords;
	qbVector2<double> newLoc = ApplyTransform(inputLoc);
	double newU = std::min((newLoc.GetElement(1) + 1.0) / 2.0, 1.0);
	return m_colorMap.GetColor(newU);
}

// Function to return the value.
double qbRT::Texture::Gradient::GetValue(const qbVector2<double> &uvCoords)
{
	// Apply the local transform to the (u,v) coordinates.
	qbVector2<double> inputLoc = uvCoords;
	qbVector2<double> newLoc = ApplyTransform(inputLoc);
	return std::min((newLoc.GetElement(0) + 1.0) / 2.0, 1.0);	
}

// Function to set the stops for the color map
void qbRT::Texture::Gradient::SetStop(double position, const qbVector4<double> &value)
{
	m_colorMap.SetStop(position, value);
}
