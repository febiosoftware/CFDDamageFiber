#pragma once
#include <FECore/FEPlotData.h>

class FEPlotCFDFiberDamageAvg : public FEPlotDomainData
{
public:
	FEPlotCFDFiberDamageAvg(FEModel* pfem);
	bool Save(FEDomain& m, FEDataStream& a) override;
};

class FEPlotCFDFiberDamageMax : public FEPlotDomainData
{
public:
	FEPlotCFDFiberDamageMax(FEModel* pfem);
	bool Save(FEDomain& m, FEDataStream& a) override;
};
