#include "FECFDDamageFiberPlot.h"
#include "FECFDDamageFiber.h"
#include <FECore/FEDomain.h>

FEPlotCFDFiberDamageAvg::FEPlotCFDFiberDamageAvg(FEModel* pfem) : FEPlotDomainData(pfem, PLT_FLOAT, FMT_ITEM)
{

}

bool FEPlotCFDFiberDamageAvg::Save(FEDomain& dom, FEDataStream& a)
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
			D += pmc->AverageDamage(mp);
		}
		D /= ni;

		a << D;
	}
	return true;
}

FEPlotCFDFiberDamageMax::FEPlotCFDFiberDamageMax(FEModel* pfem) : FEPlotDomainData(pfem, PLT_FLOAT, FMT_ITEM)
{

}

bool FEPlotCFDFiberDamageMax::Save(FEDomain& dom, FEDataStream& a)
{
	FEMaterial* pm = dom.GetMaterial();
	if (pm == nullptr) return false;

	FECFDDamageFiber* pmc = pm->ExtractProperty<FECFDDamageFiber>();
	if (pmc == nullptr) return false;

	int NE = dom.Elements();
	for (int i = 0; i < NE; ++i)
	{
		FEElement& el = dom.ElementRef(i);
		double maxD = 0;
		int ni = el.GaussPoints();
		for (int i = 0; i < ni; ++i)
		{
			FEMaterialPoint& mp = *el.GetMaterialPoint(i);
			double D = pmc->MaxDamage(mp);
			if (D > maxD) maxD = D;
		}
		a << maxD;
	}
	return true;
}
