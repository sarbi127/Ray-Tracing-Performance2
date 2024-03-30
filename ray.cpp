#include "ray.hpp"

qbRT::Ray::Ray()
{
	//m_point1 = qbVector3<double>{std::vector<double>{0.0, 0.0, 0.0}};
	//m_point2 = qbVector3<double>{std::vector<double>{0.0, 0.0, 1.0}};
	//m_lab = m_point2 - m_point1;
	m_point1 = qbVector3<double>{0.0, 0.0, 0.0};
	m_point2 = qbVector3<double>{0.0, 0.0, 1.0};
	m_lab = qbVector3<double>{0.0, 0.0, 1.0};
}

qbRT::Ray::Ray(const qbVector3<double> &point1, const qbVector3<double> &point2)
{
	m_point1 = point1;
	m_point2 = point2;
	m_lab = m_point2 - m_point1;
}

qbVector3<double> qbRT::Ray::GetPoint1() const
{
	return m_point1;
}

qbVector3<double> qbRT::Ray::GetPoint2() const
{
	return m_point2;
}



