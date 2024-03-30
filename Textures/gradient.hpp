#ifndef GRADIENT_H
#define GRADIENT_H

#include "texturebase.hpp"
#include "colormap.hpp"
#include "../qbVector2.h"
#include "../qbVector3.h"
#include "../qbVector4.h"

namespace qbRT
{
	namespace Texture
	{
		class Gradient : public TextureBase
		{
			public:
				// Constructor / destructor.
				Gradient();
				virtual ~Gradient() override;
				
				// Function to return the color.
				virtual qbVector4<double> GetColor(const qbVector2<double> &uvCoords) override;
				
				// *** Function to return the value.
				virtual double GetValue(const qbVector2<double> &uvCoords) override;				
				
				// Function to set stops for the color map.
				void SetStop(double position, const qbVector4<double> &value);
				
			private:
				qbRT::Texture::ColorMap m_colorMap;
		};		
	}
}

#endif