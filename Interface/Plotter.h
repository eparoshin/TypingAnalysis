#ifndef NSAPPLICATION_NSINTERFACE_CPLOTTER_H
#define NSAPPLICATION_NSINTERFACE_CPLOTTER_H

#include <QObject>

#include <memory>

#include "Kernel/PlotData.h"
#include "Library/Observer/Observer.h"
#include "Library/StlExtension/MvcWrappers.h"
#include "Local/Localizer.h"

class QwtPlot;
class QwtPlotCurve;
class QwtPlotItem;

QT_BEGIN_NAMESPACE
class QSlider;
QT_END_NAMESPACE

namespace NSApplication {
namespace NSInterface {

namespace NSPlotterDetail {

class CSpeedPlotterImpl : public QObject {
  Q_OBJECT

  using CPlotData = NSKernel::CPlotData;
  using CPlotDataCRef = std::reference_wrapper<const CPlotData>;
  using CPlotDataObserver = NSLibrary::CObserver<CPlotDataCRef>;
  using CPlotDataInput = NSLibrary::CHotInput<CPlotDataCRef>;

  using CLocalizer = NSLocal::CSpeedPlotterLocalizer;
  using CLocalizerObserver = NSLibrary::CObserver<CLocalizer>;
  using CLocalizerInput = NSLibrary::CHotInput<CLocalizer>;

public:
  struct CInitData {
    QwtPlot* Plot;
    QSlider* VerticalSlider;
    QSlider* HorizontalSlider;
  };

  explicit CSpeedPlotterImpl(CInitData Data);
  ~CSpeedPlotterImpl();

  CPlotDataObserver* speedDataInput();
  CLocalizerObserver* localizerInput();

public Q_SLOTS:
  void legendChecked(const QVariant&, bool, int);

private Q_SLOTS:
  void adjustVerticalScale(int);
  void adjustHorizontalScale(int);

private:
  void adjustPlot();
  void setCurves();
  void setCurve(const QString& Name, QColor Color, bool Checked,
                QwtPlotCurve** Curve);
  void checkItem(QwtPlotItem* item, bool on);
  void adjustSliders();
  void connectSliders();

  void handlePlotData(const CPlotData& PlotData);

  void setLocale(const CLocalizer& Localizer);

  QString title() const;
  QString horizontalAxisTitle() const;
  QString density1Name() const;
  QString derivative1Name() const;
  QString density2Name() const;
  QString derivative2Name() const;
  QString density3Name() const;
  QString derivative3Name() const;

  static constexpr double YLeftMinDefault_ = 0.0;
  static constexpr double YLeftMaxDefault_ = 0.003;
  static constexpr double XBottomMinDefault_ = 0.0;
  static constexpr double XBottomMaxDefault_ = 2500.;

  static constexpr int VerticalSliderMin_ = 1;
  static constexpr int VerticalSliderMax_ = 100;
  static constexpr int VerticalSliderPosition_ = 30;
  static constexpr int HorizontalSliderMin_ = 1;
  static constexpr int HorizontalSliderMax_ = 100;
  static constexpr int HorizontalSliderPosition_ = 100;

  static constexpr double VerticalStep_ =
      YLeftMaxDefault_ / VerticalSliderPosition_;
  static constexpr double HorizontalStep_ =
      XBottomMaxDefault_ / HorizontalSliderMax_;

  QwtPlot* Plot_;
  QSlider* VerticalSlider_;
  QSlider* HorizontalSlider_;
  QwtPlotCurve* Speed0_;
  QwtPlotCurve* Speed1_;
  QwtPlotCurve* SpeedMB0_;
  QwtPlotCurve* SpeedMB1_;
  QwtPlotCurve* SpeedR0_;
  QwtPlotCurve* SpeedR1_;
  CPlotDataInput SpeedDataInput_;
  CLocalizerInput LocalizerInput_;
};

} // namespace NSPlotterDetail

class CSpeedPlotter
    : public NSLibrary::CViewWrapper<NSPlotterDetail::CSpeedPlotterImpl> {
  using CBase = NSLibrary::CViewWrapper<NSPlotterDetail::CSpeedPlotterImpl>;
  using CSpeedPlotterImpl = NSPlotterDetail::CSpeedPlotterImpl;

public:
  using CInitData = CSpeedPlotterImpl::CInitData;
  using CBase::CBase;
};

} // namespace NSInterface
} // namespace NSApplication

#endif // NSAPPLICATION_NSINTERFACE_CPLOTTER_H
