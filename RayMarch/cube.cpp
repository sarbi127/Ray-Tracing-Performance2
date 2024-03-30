#include "cube.hpp"

// Constructor.
qbRT::RM::Cube::Cube()
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
																									qbVector3<double>{std::vector<double>{1.2, 1.2, 1.2}} } );

}

// Destructor.
qbRT::RM::Cube::~Cube()
{

}

// The private object function.
double qbRT::RM::Cube::ObjectFcn(qbVector3<double> *location, qbVector3<double> *parms)
{	
	qbVector3<double> center = std::vector<double>{0.0, 0.0, 0.0};
	qbVector3<double> intParms = std::vector<double>{1.0, 1.0, 1.0};
	return qbRT::RM::SDF::Box(*location, center, intParms);		
}


