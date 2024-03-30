#ifndef COLORMAP_H
#define COLORMAP_H

#include "../qbVector.h"
#include "../qbVector2.h"
#include "../qbVector3.h"
#include "../qbVector4.h"

namespace qbRT
{
	namespace Texture
	{
		class ColorMap
		{
			public:
				// Constructor / destructor.
				ColorMap();
				~ColorMap();
				
				// Function to set a stop as a color.
				void SetStop(double position, const qbVector4<double> &value);
				
				// Function to get the color at a particular position.
				qbVector4<double> GetColor(double position);
				
			private:
				std::vector<double> m_stopPositions;
				std::vector<qbVector4<double>> m_stopValues;
		};
	}
}

#endif
