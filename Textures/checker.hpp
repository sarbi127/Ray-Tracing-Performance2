#ifndef CHECKER_H
#define CHECKER_H

#include "texturebase.hpp"

namespace qbRT
{
	namespace Texture
	{
		class Checker : public TextureBase
		{
			public:
				// Constructor / destructor.
				Checker();
				virtual ~Checker() override;
			
				// Function to return the color.
				virtual qbVector4<double> GetColor(const qbVector2<double> &uvCoords) override;
			
				// Function to set the colors.
				void SetColor(const qbVector4<double> &inputColor1, const qbVector4<double> &inputColor2);
				void SetColor(const std::shared_ptr<qbRT::Texture::TextureBase> &inputColor1, const std::shared_ptr<qbRT::Texture::TextureBase> &inputColor2);
			
		private:
			std::shared_ptr<qbRT::Texture::TextureBase> m_p_color1;
			std::shared_ptr<qbRT::Texture::TextureBase> m_p_color2;
			
		};
	}
}

#endif



