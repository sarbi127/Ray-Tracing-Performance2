#include "texturenormal.hpp"

// Constructor / destructor.
qbRT::Normal::TextureNormal::TextureNormal()
{

}

qbRT::Normal::TextureNormal::~TextureNormal()
{

}

// Function to assign a base texture.
void qbRT::Normal::TextureNormal::AssignBaseTexture(const std::shared_ptr<qbRT::Texture::TextureBase> &inputTexture)
{
	m_p_baseTexture = inputTexture;
	m_haveTexture = true;
}

qbVector3<double> qbRT::Normal::TextureNormal::ComputePerturbation(const qbVector3<double> &normal, const qbVector2<double> &uvCoords)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	if (m_haveTexture)
	{
		qbVector2<double> uvGrad = TextureDiff(m_p_baseTexture, uvCoords);
		if (!m_reverse)
		{
			x = -uvGrad.GetElement(0) * m_scale;
			y = -uvGrad.GetElement(1) * m_scale;
		}
		else
		{
			x = uvGrad.GetElement(0) * m_scale;
			y = uvGrad.GetElement(1) * m_scale;		
		}
	}
	
	qbVector3<double> perturbation = std::vector<double> {x, y, z};
	return PerturbNormal(normal, perturbation);
}
