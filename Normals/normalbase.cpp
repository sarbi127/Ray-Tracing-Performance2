#include "normalbase.hpp"

// Constructor / destructor.
qbRT::Normal::NormalBase::NormalBase()
{

}

qbRT::Normal::NormalBase::~NormalBase()
{

}

qbVector3<double> qbRT::Normal::NormalBase::ComputePerturbation(const qbVector3<double> &normal, const qbVector2<double> &uvCoords)
{
	// The default response.
	return qbVector3<double>{std::vector<double>{0.0, 0.0, 0.0}};
}

qbVector3<double> qbRT::Normal::NormalBase::PerturbNormal(const qbVector3<double> &normal, const qbVector3<double> &perturbation)
{
	// Decide upon an appropriate up vector.
	qbVector3<double> newUpVector = std::vector<double> {0.0, 0.0, -1.0};
	if ((normal.GetElement(2) > 0.99) || (normal.GetElement(2) < -0.99))
		newUpVector = std::vector<double> {1.0, 0.0, 0.0};

	// Compute the directions (based on the tangent plane).
	qbVector3<double> pV = qbVector3<double>::cross(newUpVector, normal);
	pV.Normalize();
	qbVector3<double> pU = qbVector3<double>::cross(normal, pV);
	pU.Normalize();
	
	// Apply the perturbation.
	qbVector3<double> output = normal + (pU * perturbation.GetElement(0)) + (pV * perturbation.GetElement(1)) + (normal * perturbation.GetElement(2));
	
	// Normalize the output.
	output.Normalize();
	
	// And return.
	return output;
}

void qbRT::Normal::NormalBase::SetAmplitude(double amplitude)
{
	m_amplitudeScale = amplitude;
}

// Function to perform numerical differentiation of a texture in UV space.
qbVector2<double> qbRT::Normal::NormalBase::TextureDiff(const std::shared_ptr<qbRT::Texture::TextureBase> &inputTexture, const qbVector2<double> &uvCoords)
{
	// We will use the symmetric difference quotient to estimate the partial derivatives of the texture
	// at the point f(u,v).
	// uGrad = f(u+h, v) - f(u-h, v) / 2h
	// vGrad = f(u, v+h) - f(u, v-h) / 2h
	double h = 0.001;
	qbVector2<double> uDisp = std::vector<double> {h, 0.0};
	qbVector2<double> vDisp = std::vector<double> {0.0, h};
	double uGrad = (inputTexture->GetValue(uvCoords + uDisp) - inputTexture->GetValue(uvCoords - uDisp)) / (2.0 * h);
	double vGrad = (inputTexture->GetValue(uvCoords + vDisp) - inputTexture->GetValue(uvCoords - vDisp)) / (2.0 * h);
	
	/* Form a vector for the output. 
	*/
	qbVector2<double> output = std::vector<double> {uGrad, vGrad};
	return output;
}

// Function to apply the transform.
qbVector2<double> qbRT::Normal::NormalBase::ApplyTransform(const qbVector2<double> &inputVector)
{
	// Copy the input vector and modify to have three elements.
	qbVector3<double> newInput;
	newInput.SetElement(0, inputVector.GetElement(0));
	newInput.SetElement(1, inputVector.GetElement(1));
	
	// Apply the transform.
	qbVector3<double> result = m_transformMatrix * newInput;
	
	// Produce the output.
	qbVector2<double> output;
	output.SetElement(0, result.GetElement(0));
	output.SetElement(1, result.GetElement(1));
	
	return output;
}

// Function to set the transform matrix.
void qbRT::Normal::NormalBase::SetTransform(const qbVector2<double> &translation, const double &rotation, const qbVector2<double> &scale)
{
	// Build the transform matrix.
	qbMatrix2<double> rotationMatrix = {3, 3, std::vector<double> {
																			cos(rotation), -sin(rotation), 0.0,
																			sin(rotation), cos(rotation), 0.0,
																			0.0, 0.0, 1.0}};
																			
	qbMatrix2<double> scaleMatrix = {	3, 3, std::vector<double> {
																		scale.GetElement(0), 0.0, 0.0,
																		0.0, scale.GetElement(1), 0.0,
																		0.0, 0.0, 1.0}};
																		
	qbMatrix2<double> translationMatrix = {	3, 3, std::vector<double> {
																					1.0, 0.0, translation.GetElement(0),
																					0.0, 1.0, translation.GetElement(1),
																					0.0, 0.0, 1.0}};
																					
	// And combine to form the final transform matrix.
	m_transformMatrix = translationMatrix * rotationMatrix * scaleMatrix;
}
