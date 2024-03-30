#ifndef RAYMARCHBASE_H
#define RAYMARCHBASE_H

#include <functional>
#include "sdfunc.hpp"
#include "../Primatives/objectbase.hpp"
#include "../Primatives/box.hpp"
#include "../qbVector2.h"
#include "../qbVector3.h"
#include "../qbVector4.h"

namespace qbRT
{
	namespace RM
	{
		class RayMarchBase : public ObjectBase, public std::enable_shared_from_this<qbRT::RM::RayMarchBase>
		{
			public:
				// Default constructor.
				RayMarchBase();
				
				// Destructor.
				virtual ~RayMarchBase() override;
				
				// Override the function to test for intersections.
				virtual bool TestIntersection(	const qbRT::Ray &castRay, qbRT::DATA::hitData &hitData) override;
				
				// Function to set the object function.
				void SetObjectFcn( std::function<double(qbVector3<double>*, qbVector3<double>*)> objectFcn);
				
				// Function to evaluate the Signed Distance Function (SDF) at the given coordinates.
				double EvaluateSDF(	qbVector3<double> *location, qbVector3<double> *parms );
												
			public:
				// Bounding box.
				qbRT::Box m_boundingBox = qbRT::Box();
				
				// Parameters.
				qbVector3<double> m_parms {3};
				
			private:
				// Pointer to object function.
				std::function<double(qbVector3<double> *, qbVector3<double> *)> m_objectFcn;			
			
				bool m_haveObjectFcn = false;
				double m_epsilon;
				int m_maxSteps;
				
				const double m_h = 0.001;
				qbVector3<double> m_xDisp {std::vector<double>{m_h, 0.0, 0.0}};
				qbVector3<double> m_yDisp {std::vector<double>{0.0, m_h, 0.0}};
				qbVector3<double> m_zDisp {std::vector<double>{0.0, 0.0, m_h}};
																						
		};
	}
}

#endif
