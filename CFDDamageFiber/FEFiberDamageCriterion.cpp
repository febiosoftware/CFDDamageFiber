#include "FEFiberDamageCriterion.h"
#include <FEBioMech/FEElasticMaterialPoint.h>
#include "FECFDDamageFiber.h"

void FEFiberDamageCriterion::SetFiberMaterial(FEFiberMaterial* fiber)
{
	assert(m_fiber == nullptr);
	m_fiber = fiber;
}

bool FEFiberDamageCriterion::Init()
{
	if (FEMaterialProperty::Init() == false) return false;

	FECoreBase* parent = GetParent();
	if (parent == nullptr) return false;

	if (m_fiber == nullptr)
	{
		m_fiber = parent->ExtractProperty<FEFiberMaterial>(false);
		if (m_fiber == nullptr) return false;
	}

	return true;
}

double FEFiberStretchCriterion::Criterion(FEMaterialPoint& mp, const vec3d& a0)
{
	FEElasticMaterialPoint& ep = *mp.ExtractData<FEElasticMaterialPoint>();
	FECFDDamageFiber::Point& fp = *mp.ExtractData<FECFDDamageFiber::Point>();

	mat3d& F = ep.m_F;
	vec3d a = F * a0;
	double l = a.unit();

	return l;
}

double FEFiberStrainCriterion::Criterion(FEMaterialPoint& mp, const vec3d& a0)
{
	FEElasticMaterialPoint& ep = *mp.ExtractData<FEElasticMaterialPoint>();
	FECFDDamageFiber::Point& fp = *mp.ExtractData<FECFDDamageFiber::Point>();

	mat3d& F = ep.m_F;
	vec3d a = F * a0;
	double l = a.unit();

	return l - 1;
}

double FEFiberStressCriterion::Criterion(FEMaterialPoint& mp, const vec3d& a0)
{
	FEElasticMaterialPoint& ep = *mp.ExtractData<FEElasticMaterialPoint>();
	FECFDDamageFiber::Point& fp = *mp.ExtractData<FECFDDamageFiber::Point>();

	mat3d& F = ep.m_F;
	vec3d a = F * a0;
	double l = a.unit();

	mat3ds sigma = m_fiber->FiberStress(mp, a0);
	double s = a * (sigma * a);

	return s;
}
