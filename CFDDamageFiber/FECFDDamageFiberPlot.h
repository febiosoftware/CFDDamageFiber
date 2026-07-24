#pragma once
#include <FECore/FEPlotData.h>

class FEPlotCFDFiberDamageAvg : public FEPlotDomainData
{
public:
	FEPlotCFDFiberDamageAvg(FEModel* pfem);
	bool Save(FEDomain& m, FEDataStream& a) override;
};

class FEPlotCFDDamagedFiberDamageAvg : public FEPlotDomainData
{
public:
	FEPlotCFDDamagedFiberDamageAvg(FEModel* pfem);
	bool Save(FEDomain& m, FEDataStream& a) override;
};

class FEPlotCFDFiberDamageMax : public FEPlotDomainData
{
public:
	FEPlotCFDFiberDamageMax(FEModel* pfem);
	bool Save(FEDomain& m, FEDataStream& a) override;
};

class FEPlotCFDPctFailedFibers : public FEPlotDomainData
{
public:
	FEPlotCFDPctFailedFibers(FEModel* pfem);
	bool Save(FEDomain& m, FEDataStream& a) override;
};

class FEPlotCFDPctDamagedFibers : public FEPlotDomainData
{
public:
	FEPlotCFDPctDamagedFibers(FEModel* pfem);
	bool Save(FEDomain& m, FEDataStream& a) override;
};

class FEPlotCFDAvgFiberStretch : public FEPlotDomainData
{
public:
	FEPlotCFDAvgFiberStretch(FEModel* pfem);
	bool Save(FEDomain& m, FEDataStream& a) override;
};
