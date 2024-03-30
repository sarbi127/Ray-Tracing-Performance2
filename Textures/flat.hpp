#ifndef FLAT_H
#define FLAT_H

#include "texturebase.hpp"

namespace qbRT
{
	namespace Texture
	{
		class Flat : public TextureBase
		{
			public:
				// Constructor / destructor.
				Flat();
				virtual ~Flat() override;
				
				// Function to return the color.
				virtual qbVector4<double> GetColor(const qbVector2<double> &uvCoords) override;
				
				// Function to set the color.
				void SetColor(const qbVector4<double> &inputColor);
				
			private:
				qbVector4<double> m_color;
				
		};
	}
}

#endif


