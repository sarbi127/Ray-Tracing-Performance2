#ifndef COMPOSITEBASE_H
#define COMPOSITEBASE_H

#include "objectbase.hpp"
#include "box.hpp"

namespace qbRT
{
	namespace SHAPES
	{
		class CompositeBase : public ObjectBase
		{
			public:
				// Default constructor.
				CompositeBase();
				
				// The destructor.
				virtual ~CompositeBase() override;
				
				// Function to add a sub-shape.
				void AddSubShape(std::shared_ptr<qbRT::ObjectBase> subShape);
				
				// Override the GetExtents function.
				virtual void GetExtents(qbVector2<double> &xLim, qbVector2<double> &yLim, qbVector2<double> &zLim) override;
				
				// Override the function to test for intersections.
				virtual bool TestIntersection(const qbRT::Ray &castRay, qbRT::DATA::hitData &hitData) override;
																
				// Function to update the bounds after sub-shapes have been modified.
				void UpdateBounds();
				
			private:
				// Test for intersections with the list of sub-objects.
				int TestIntersections(	const qbRT::Ray &castRay,
																const qbRT::Ray &bckRay,
																qbVector3<double> &intPoint,
																double &currentDist,
																qbRT::DATA::hitData &hitData	);			
																
			public:
				// Bounding box.
				qbRT::Box m_boundingBox = qbRT::Box();
				bool m_useBoundingBox = true;
			
				// List of sub-objects.
				std::vector<std::shared_ptr<qbRT::ObjectBase>> m_shapeList;

				// Object limits.
				qbVector2<double> m_xLim;
				qbVector2<double> m_yLim;
				qbVector2<double> m_zLim;
				
		};
	}
}

#endif