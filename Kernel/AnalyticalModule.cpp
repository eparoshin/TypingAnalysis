#include "AnalyticalModule.h"

#include <algorithm>
#include <cassert>

#include "AppDebug/PerformanceLogger.h"
#include "ParallelModuleAccess.h"

namespace NSApplication {
namespace NSKernel {

void CFunctionData::set(CContainer&& Samples) {
  Samples_ = std::move(Samples);
  PlotData_.fillPlots(Samples_);
}

const CPlotData& CFunctionData::plotData() const {
  return PlotData_;
}

namespace NSAnalyticalModuleDetail {
CAnalyticalModuleImpl::CAnalyticalModuleImpl()
    : TextData_([this](const CTextData& Data) { handleTextData(Data); }),
      DensityOut_([this]() -> CPlotDataGetType {
        return std::cref(SpeedData_.plotData());
      }) {
}

CAnalyticalModuleImpl::CTextDataObserver*
CAnalyticalModuleImpl::textDataInput() {
  return &TextData_;
}

void CAnalyticalModuleImpl::subscribeToSpeedData(CPlotDataObserver* obs) {
  assert(obs);
  DensityOut_.subscribe(obs);
}

void CAnalyticalModuleImpl::handleTextData(const CTextData& Data) {
  NSAppDebug::CTimeAnchor Anchor("math & notify time =");

  // preliminary implementation
  CContainer Samples = getSpeedData(Data);
  SpeedData_.set(std::move(Samples));
  DensityOut_.notify();
}

CAnalyticalModuleImpl::CContainer
CAnalyticalModuleImpl::getSpeedData(const CTextData& Data) const {
  CContainer SpeedData;
  switch (Data.textMode()) {
  case ETextMode::Raw:
    SpeedData = getSpeedData(Data.rawSession());
    break;
  case ETextMode::Full:
    SpeedData = getSpeedData(Data.textConstFullView());
    break;
  case ETextMode::Printed:
    SpeedData = getSpeedData(Data.textConstPrintedView());
    break;
  default:
    assert(false);
  }
  return SpeedData;
}

template<class TText>
CAnalyticalModuleImpl::CContainer
CAnalyticalModuleImpl::getSpeedData(const TText& TextView) const {
  CContainer SpeedData;
  if (TextView.empty())
    return SpeedData;
  SpeedData.reserve(TextView.size());
  auto iter = TextView.begin();
  CTime PreviousTime = iter->getPressingTime();
  for (; iter != TextView.end(); ++iter) {
    if (!iter->isAutoRepeat()) {
      CTime ResponseTime = iter->getPressingTime() - PreviousTime;
      // Need filter here
      if (ResponseTime > CTime())
        SpeedData.push_back(1. / ResponseTime.toMinutesF());
      PreviousTime = iter->getPressingTime();
    }
  }
  return SpeedData;
}

} // namespace NSAnalyticalModuleDetail
} // namespace NSKernel
} // namespace NSApplication
