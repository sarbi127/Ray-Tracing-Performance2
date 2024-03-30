#include "flat.hpp"

// Constructor / destructor.
qbRT::Texture::Flat::Flat()
{
	m_color = qbVector4<double>{std::vector<double> {1.0, 0.0, 0.0, 1.0}};
}

qbRT::Texture::Flat::~Flat()
{

}

// Function to return the color.
qbVector4<double> qbRT::Texture::Flat::GetColor(const qbVector2<double> &uvCoords)
{
	return m_color;
}

// Function to set the color.
void qbRT::Texture::Flat::SetColor(const qbVector4<double> &inputColor)
{
	m_color = inputColor;
}


