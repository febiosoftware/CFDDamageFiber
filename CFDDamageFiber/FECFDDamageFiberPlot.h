#pragma once
#include <FECore/FEPlotData.h>

class FEPlotCFDFiberDamage : public FEPlotDomainData
{
public:
	FEPlotCFDFiberDamage(FEModel* pfem);
	bool Save(FEDomain& m, FEDataStream& a) override;
};
