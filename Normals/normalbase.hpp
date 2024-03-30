#ifndef NORMALBASE_H
#define NORMALBASE_H

#include <memory>
#include "../qbMatrix.h"
#include "../ray.hpp"
#include "../Textures/texturebase.hpp"
#include "../qbVector.h"
#include "../qbVector2.h"
#include "../qbVector3.h"
#include "../qbVector4.h"

namespace qbRT
{
	namespace Normal
	{
		class NormalBase
		{
			public:
				// Constructor / destructor.
				NormalBase();
				virtual ~NormalBase();
				
				// Function to compute the perturbation.
				virtual qbVector3<double> ComputePerturbation(const qbVector3<double> &normal, const qbVector2<double> &uvCoords);
				
				// Function to perturb the given normal.
				qbVector3<double> PerturbNormal(const qbVector3<double> &normal, const qbVector3<double> &perturbation);
				
				// *** Function to perform numerical differentiation of a texture in UV space.
				qbVector2<double> TextureDiff(const std::shared_ptr<qbRT::Texture::TextureBase> &inputTexture, const qbVector2<double> &uvCoords);				
				
				// Function to set the amplitude scale.
				void SetAmplitude(double amplitude);
				
				// Function to set transform.
				void SetTransform(const qbVector2<double> &translation, const double &rotation, const qbVector2<double> &scale);				
				
				// Function to apply the local transform to the given input vector.
				qbVector2<double> ApplyTransform(const qbVector2<double> &inputVector);				
				
			public:
				// Store the amplitude scale factor.
				double m_amplitudeScale = 1.0;	
			
			private:
				// Initialise the transform matrix to the identity matrix.
				qbMatrix2<double> m_transformMatrix {3, 3, std::vector<double>{1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0}};
				
		};
	}
}

#endif