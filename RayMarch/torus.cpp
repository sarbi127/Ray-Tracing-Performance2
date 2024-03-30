#include "torus.hpp"

qbRT::RM::Torus::Torus()
{
	// Create a function pointer for our object function.
	std::function<double(qbVector3<double>*, qbVector3<double>*)> f = [=](qbVector3<double> *location, qbVector3<double> *parms)
	{
  	return this->ObjectFcn(location, parms);
	};
	
	// Assign the object function.
	SetObjectFcn(f);

	// Modify the bounding box.
	m_boundingBox.SetTransformMatrix(qbRT::GTform { qbVector3<double>{std::vector<double>{0.0, 0.0, 0.0}},
																									qbVector3<double>{std::vector<double>{0.0, 0.0, 0.0}},
																									qbVector3<double>{std::vector<double>{1.3, 1.3, 1.3}} } );
}

qbRT::RM::Torus::~Torus()
{

}

// Function to set the radii.
void qbRT::RM::Torus::SetRadii(double r1, double r2)
{
	m_parms.SetElement(0, r1);
	m_parms.SetElement(1, r2);
	UpdateBounds();
}

// Function to update the bounding box.
void qbRT::RM::Torus::UpdateBounds()
{
	m_boundingBox.SetTransformMatrix(qbRT::GTform { qbVector3<double>{std::vector<double>{0.0, 0.0, 0.0}},
																									qbVector3<double>{std::vector<double>{0.0, 0.0, 0.0}},
																									qbVector3<double>{std::vector<double>{m_r1+m_r2+0.3, m_r1+m_r2+0.3, m_r2 + 0.2}} } );	
}

// The private object function.
double qbRT::RM::Torus::ObjectFcn(qbVector3<double> *location, qbVector3<double> *parms)
{	
	qbVector3<double> center = std::vector<double>{0.0, 0.0, 0.0};
	return qbRT::RM::SDF::Torus(*location, center, *parms);	

}
