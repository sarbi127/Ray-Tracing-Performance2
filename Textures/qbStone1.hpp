#ifndef QBSTONE1_H
#define QBSTONE1_H

#include "../Noise/valnoisegenerator.hpp"
#include "texturebase.hpp"
#include "colormap.hpp"
#include "../qbVector2.h"
#include "../qbVector3.h"
#include "../qbVector4.h"

namespace qbRT
{
	namespace Texture
	{
		class qbStone1 : public TextureBase
		{
			public:
				// Constructor / destructor.
				qbStone1();
				virtual ~qbStone1() override;
				
				// Function to return the color.
				virtual qbVector4<double> GetColor(const qbVector2<double> &uvCoords) override;
				
				// Function to return the value.
				virtual double GetValue(const qbVector2<double> &uvCoords) override;
				
				// Function to set the color map.
				void SetColorMap(const std::shared_ptr<qbRT::Texture::ColorMap> &colorMap);
				
				// Function to set the amplitude.
				void SetAmplitude(double amplitude);
				
				// Function to set the scale.
				void SetScale(int scale);
				
			public:
				// Store the color map.
				std::shared_ptr<qbRT::Texture::ColorMap> m_colorMap;
				bool m_haveColorMap = false;
				
				// We need a NoiseGenerator instance.
				qbRT::Noise::ValNoiseGenerator m_noiseGenerator1;
				qbRT::Noise::ValNoiseGenerator m_noiseGenerator2;
				
				// Store the amplitude.
				double m_amplitude1 = 8.0;
				double m_amplitude2 = 4.0;
				
				// Store the scale.
				int m_scale1 = 6;
				int m_scale2 = 30;
				
				// Store the min and max values.
				double m_minValue, m_maxValue;
				
		};
	}
}

#endif