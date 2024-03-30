#ifndef Constant_H
#define Constant_H

#include "normalbase.hpp"
#include <random>

namespace qbRT
{
	namespace Normal
	{
		class Constant : public NormalBase
		{
			public:
				// Constructor / Destructor.
				Constant();
				virtual ~Constant() override;
			
				// Function to compute the perturbation.
				virtual qbVector3<double> ComputePerturbation(const qbVector3<double> &normal, const qbVector2<double> &uvCoords) override;
				
			public:
				qbVector3<double> m_displacement {3};
				
			private:
				
				
		};
	}
}

#endif

