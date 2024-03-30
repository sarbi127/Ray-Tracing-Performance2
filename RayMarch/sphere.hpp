#ifndef RM_SPHERE_H
#define RM_SPHERE_H

#include "raymarchbase.hpp"

namespace qbRT
{
	namespace RM
	{
		class Sphere : public RayMarchBase
		{
			public:
				// Constructor.
				Sphere();
				
				// Destructor.
				virtual ~Sphere() override;
				
			private:
				// Private object function.
				double ObjectFcn(qbVector3<double> *location, qbVector3<double> *parms);
				
		};
	}
}

#endif


