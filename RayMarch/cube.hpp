#ifndef RM_CUBE
#define RM_CUBE

#include "raymarchbase.hpp"
#include "../qbVector.h"
#include "../qbVector2.h"
#include "../qbVector3.h"
#include "../qbVector4.h"

namespace qbRT
{
	namespace RM
	{
		class Cube : public RayMarchBase
		{
			public:
				// Constructor.
				Cube();
				
				// Destructor.
				virtual ~Cube() override;
				
			private:
				// Private object function.
				double ObjectFcn(qbVector3<double> *location, qbVector3<double> *parms);				
		};
	}
}

#endif


