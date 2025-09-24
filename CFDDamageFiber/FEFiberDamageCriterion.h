#pragma once
#include <FECore/FEMaterial.h>
#include <FEBioMech/FEFiberMaterial.h>

// Base class for fiber damage criterion
class FEFiberDamageCriterion : public FEMaterialProperty
{
public:
	FEFiberDamageCriterion(FEModel* fem) : FEMaterialProperty(fem) {}
	virtual double Criterion(FEMaterialPoint& mp, const vec3d& a0) = 0;

	void SetFiberMaterial(FEFiberMaterial* fiber);

	bool Init() override;

	FECORE_BASE_CLASS(FEFiberDamageCriterion);

protected:
	FEFiberMaterial* m_fiber = nullptr;
};

// stretch-based criterion
class FEFiberStretchCriterion : public FEFiberDamageCriterion
{
public:
	FEFiberStretchCriterion(FEModel* fem) : FEFiberDamageCriterion(fem) {}
	double Criterion(FEMaterialPoint& mp, const vec3d& a0) override;
};

// strain-based criterion
class FEFiberStrainCriterion : public FEFiberDamageCriterion
{
public:
	FEFiberStrainCriterion(FEModel* fem) : FEFiberDamageCriterion(fem) {}
	double Criterion(FEMaterialPoint& mp, const vec3d& a0) override;
};

// stress-based criterion
class FEFiberStressCriterion : public FEFiberDamageCriterion
{
public:
	FEFiberStressCriterion(FEModel* fem) : FEFiberDamageCriterion(fem) {}
	double Criterion(FEMaterialPoint& mp, const vec3d& a0) override;
};
