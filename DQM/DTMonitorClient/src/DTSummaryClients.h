#ifndef DTSummaryClients_H
#define DTSummaryClients_H


/** \class DTSummaryClients
 * *
 *  DQM Client for global summary
 *
 *  \author  G. Mila - INFN Torino
 *
 *  threadsafe version (//-) oct/nov 2014 - WATWanAbdullah -ncpp-um-my
 *
 *   
 */


#include "FWCore/Framework/interface/Frameworkfwd.h"
#include <FWCore/Framework/interface/EDAnalyzer.h>
#include "DataFormats/Common/interface/Handle.h"
#include <FWCore/Framework/interface/ESHandle.h>
#include <FWCore/Framework/interface/Event.h>
#include <FWCore/Framework/interface/MakerMacros.h>
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <FWCore/Framework/interface/LuminosityBlock.h>

#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Framework/interface/Run.h"

#include <DQMServices/Core/interface/DQMEDHarvester.h>

#include <memory>
#include <string>

//-class DTSummaryClients: public edm::EDAnalyzer{
class DTSummaryClients: public DQMEDHarvester{

public:

  /// Constructor
  DTSummaryClients(const edm::ParameterSet& ps);
  
  /// Destructor
  virtual ~DTSummaryClients();

protected:

  /// BeginRun
//-  void beginRun(edm::Run const& run, edm::EventSetup const& eSetup);


  /// EndRun
//-  void endRun(edm::Run const& run, edm::EventSetup const& eSetup);

  /// EndJob
//-  void endJob(void);
  void dqmEndJob(DQMStore::IBooker &, DQMStore::IGetter &) override;

  /// Analyze
//-  void analyze(const edm::Event& e, const edm::EventSetup& c);

  /// DQM Client Diagnostic
//-  void endLuminosityBlock(edm::LuminosityBlock const& lumiSeg, edm::EventSetup const& c);
  void dqmEndLuminosityBlock(DQMStore::IBooker &, DQMStore::IGetter &, edm::LuminosityBlock const &, edm::EventSetup const &);

private:

  int nevents;
  DQMStore* dbe;

  MonitorElement*  summaryReport;
  MonitorElement*  summaryReportMap;
  std::vector<MonitorElement*>  theSummaryContents;

    bool bookingdone;
};

#endif
