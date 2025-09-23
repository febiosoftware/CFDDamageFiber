#include <FEBioMech/FEFiberMaterial.h>
#include <FEBioMech/FEFiberMaterialPoint.h>
#include <FEBioMech/FEDamageCDF.h>
#include "FEFiberDamageCriterion.h"

class FEFiberIntegrationTriangle;
class FEFiberDensityDistribution;

class FEDeltaDamageCDF : public FEDamageCDF
{
public:
	FEDeltaDamageCDF(FEModel* fem);

	//! cumulative distribution function
	double cdf(FEMaterialPoint& mp, const double X) override { return (X < m_mu ? 0 : 1.0); }

	//! probability density function
	double pdf(FEMaterialPoint& mp, const double X) override { assert(false); return 0.0; }

private:
	double m_mu = 0.0;

	DECLARE_FECORE_CLASS();
};

class FECFDDamageFiber : public FEFiberMaterial
{
public:
	class Point : public FEFiberMaterialPoint
	{
	public:
		Point();

		void Init() override;

		void Update(const FETimeInfo& timeInfo) override;

	public:
		std::vector<double> m_D, m_Dp; // damage at fiber integration points for next time step
	};

public:
	FECFDDamageFiber(FEModel* fem);

	~FECFDDamageFiber();

	bool Init() override;

	bool Validate() override;

	FEMaterialPointData* CreateMaterialPointData() override;

	double FiberStrainEnergyDensity(FEMaterialPoint& mp, const vec3d& a);

	mat3ds FiberStress(FEMaterialPoint& mp, const vec3d& a);

	tens4ds FiberTangent(FEMaterialPoint& mp, const vec3d& a);

	double CumulativeDamage(FEMaterialPoint& mp);

private:
	FEFiberMaterial* m_fiber;	// base fiber material
	FEFiberDamageCriterion* m_criterion; // damage criterion
	FEDamageCDF* m_cdf;

	FEFiberDensityDistribution* m_R = nullptr;
	FEFiberIntegrationTriangle* m_rule = nullptr;

	friend class Point;

	DECLARE_FECORE_CLASS();
};
