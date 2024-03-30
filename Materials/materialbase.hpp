#ifndef MATERIALBASE_H
#define MATERIALBASE_H

#include <memory>
#include "../Normals/normalbase.hpp"
#include "../Textures/texturebase.hpp"
#include "../Primatives/objectbase.hpp"
#include "../Lights/lightbase.hpp"
#include "../qbVector.h"
#include "../qbVector2.h"
#include "../qbVector3.h"
#include "../qbVector4.h"
#include "../ray.hpp"

namespace qbRT
{
	class MaterialBase
	{
		public:
			MaterialBase();
			virtual ~MaterialBase();
			
			// Function to return the color of the material.
			virtual qbVector3<double> ComputeColor(	const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																							const std::vector<std::shared_ptr<qbRT::LightBase>> &lightList,
																							const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																							const qbVector3<double> &intPoint, const qbVector3<double> &localNormal,
																							const qbRT::Ray &cameraRay);
																							
			// Function to compute diffuse color.
			static qbVector3<double> ComputeDiffuseColor(	const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																										const std::vector<std::shared_ptr<qbRT::LightBase>> &lightList,
																										const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																										const qbVector3<double> &intPoint, const qbVector3<double> &localNormal,
																										const qbVector3<double> &baseColor);
																										
			// Function to compute the reflection color.
			qbVector3<double> ComputeReflectionColor(	const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																								const std::vector<std::shared_ptr<qbRT::LightBase>> &lightList,
																								const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																								const qbVector3<double> &intPoint, const qbVector3<double> &localNormal,
																								const qbRT::Ray &incidentRay);
															
			// *************************************************************************************																								
			// Function that combines the computation of diffuse and specular components (faster).
			qbVector3<double> ComputeSpecAndDiffuse(	const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
																							const std::vector<std::shared_ptr<qbRT::LightBase>> &lightList,
																							const std::shared_ptr<qbRT::ObjectBase> &currentObject,
																							const qbVector3<double> &intPoint, const qbVector3<double> &localNormal,
																							const qbVector3<double> &baseColor, const qbRT::Ray &cameraRay);																								
																										
			// Function to cast a ray into the scene.
			bool CastRay(	const qbRT::Ray &castRay, const std::vector<std::shared_ptr<qbRT::ObjectBase>> &objectList,
										const std::shared_ptr<qbRT::ObjectBase> &thisObject,
										std::shared_ptr<qbRT::ObjectBase> &closestObject,
										qbRT::DATA::hitData &closestHitData);
										
			// Function to assign a texture.
			void AssignTexture(const std::shared_ptr<qbRT::Texture::TextureBase> &inputTexture);
			
			// Function to assign a normal map.
			void AssignNormalMap(const std::shared_ptr<qbRT::Normal::NormalBase> &inputNormalMap);			
			
			// Function to return the color due to the textures at the given (u,v) coordinate.
			qbVector3<double> GetTextureColor(const qbVector2<double> &uvCoords);

			// *** Function to perturb the object normal to give the material normal.
			qbVector3<double> PerturbNormal(const qbVector3<double> &normal, const qbVector2<double> &uvCoords, const qbVector3<double> &upVector);			
			
			// Function to blend RGBA colors (blends into color1).
			void BlendColors(qbVector4<double> &color1, const qbVector4<double> &color2);			
										
		public:
			// Counter for the number of relection rays.
			inline static int m_maxReflectionRays;
			inline static int m_reflectionRayCount;
			
			// The ambient lighting conditions.
			inline static qbVector3<double> m_ambientColor {std::vector<double> {1.0, 1.0, 1.0}};
			inline static double m_ambientIntensity = 0.2;
			
			// List of texures assigned to this material.
			std::vector<std::shared_ptr<qbRT::Texture::TextureBase>> m_textureList;
			
			// *** List of normal maps assigned to this material.
			std::vector<std::shared_ptr<qbRT::Normal::NormalBase>> m_normalMapList;			
			
			// Flat to indicate whether at least one texture has been assigned.
			bool m_hasTexture = false;
			
			// *** Flag to indicate whether at least one normal map has been assigned.
			bool m_hasNormalMap = false;
		
			// *** Store the material normal at the current point.
			qbVector3<double> m_localNormal;		
			
			// ***
			// Values for specular hightlights.
			double m_specular = 0.0;		
			double m_shininess = 0.0;				
		
		private:
		
	};
}

#endif