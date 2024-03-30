#ifndef TEXTUREBASE_H
#define TEXTUREBASE_H

#include<memory>
#include "../qbMatrix.h"
#include "../qbVector.h"
#include "../qbVector2.h"
#include "../qbVector3.h"
#include "../qbVector4.h"
#include "../ray.hpp"

namespace qbRT
{
	namespace Texture
	{
		class TextureBase
		{
			public:
				// Constructor / destructor.
				TextureBase();
				virtual ~TextureBase();
				
				// Function to retrun the color at a given point in the (u,v) coordinate system.
				// Note that the color is returned as a 4-dimensional vector (RGBA).
				virtual qbVector4<double> GetColor(const qbVector2<double> &uvCoords);
				
				// *** Function to return the actual texture value at a given point in the (u,v) coordinate system.
				virtual double GetValue(const qbVector2<double> &uvCoords);				
				
				// Function to set transform.
				void SetTransform(const qbVector2<double> &translation, const double &rotation, const qbVector2<double> &scale);
				
				// Function to blend RGBA colors, returning a 3-dimensional (RGB) result.
				static qbVector3<double> BlendColors(const std::vector<qbVector3<double>> &inputColorList);
				
				// Function to apply the local transform to the given input vector.
				qbVector2<double> ApplyTransform(const qbVector2<double> &inputVector);
				
			private:
			
			private:
				// Initialise the transform matrix to the identity matrix.
				qbMatrix2<double> m_transformMatrix {3, 3, std::vector<double>{1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0}};
				
		};
	}
}

#endif