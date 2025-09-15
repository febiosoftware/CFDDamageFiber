#include "FECFDDamageFiberPlot.h"
#include "FECFDDamageFiber.h"
#include <FECore/FEDomain.h>

FEPlotCFDFiberDamage::FEPlotCFDFiberDamage(FEModel* pfem) : FEPlotDomainData(pfem, PLT_FLOAT, FMT_ITEM)
{

}

bool FEPlotCFDFiberDamage::Save(FEDomain& dom, FEDataStream& a)
{
	FEMaterial* pm = dom.GetMaterial();
	if (pm == nullptr) return false;

	FECFDDamageFiber* pmc = pm->ExtractProperty<FECFDDamageFiber>();
	if (pmc == nullptr) return false;

	int NE = dom.Elements();
	for (int i = 0; i < NE; ++i)
	{
		FEElement& el = dom.ElementRef(i);
		double D = 0;
		int ni = el.GaussPoints();
		for (int i = 0; i < ni; ++i)
		{
			FEMaterialPoint& mp = *el.GetMaterialPoint(i);
			D += pmc->CumulativeDamage(mp);
		}
		D /= ni;

		a << D;
	}

	return true;
}
