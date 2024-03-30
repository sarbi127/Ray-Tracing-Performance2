#ifndef CAMERA_H
#define CAMERA_H

#include "qbVector.h"
#include "qbVector2.h"
#include "qbVector3.h"
#include "qbVector4.h"
#include "ray.hpp"

namespace qbRT
{
	class Camera
	{
		public:
			// The default constructor.
			Camera();
			
			// Functions to set camera parameters.
			void SetPosition	(const qbVector3<double> &newPosition);
			void SetLookAt		(const qbVector3<double> &newLookAt);
			void SetUp				(const qbVector3<double> &upVector);
			void SetLength		(double newLength);
			void SetHorzSize	(double newSize);
			void SetAspect		(double newAspect);
			
			// Functions to return camera parameters.
			qbVector3<double>	GetPosition();
			qbVector3<double>	GetLookAt();
			qbVector3<double>	GetUp();
			qbVector3<double>	GetU();
			qbVector3<double>	GetV();
			qbVector3<double>	GetScreenCentre();
			double						GetLength();
			double						GetHorzSize();
			double						GetAspect();
			
			// Function to generate a ray.
			bool GenerateRay(float proScreenX, float proScreenY, qbRT::Ray &cameraRay);
			
			// Function to update the camera geometry.
			void UpdateCameraGeometry();
			
		private:
			qbVector3<double> m_cameraPosition	{3};
			qbVector3<double> m_cameraLookAt		{3};
			qbVector3<double> m_cameraUp				{3};
			double m_cameraLength;
			double m_cameraHorzSize;
			double m_cameraAspectRatio;
			
			qbVector3<double> m_alignmentVector				{3};
			qbVector3<double> m_projectionScreenU			{3};
			qbVector3<double> m_projectionScreenV			{3};
			qbVector3<double> m_projectionScreenCentre	{3};
			
	};
}

#endif
