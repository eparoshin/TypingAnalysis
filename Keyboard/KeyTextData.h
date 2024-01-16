#ifndef NSAPPLICATION_NSKEYBOARD_CKEYTEXTDATA_H
#define NSAPPLICATION_NSKEYBOARD_CKEYTEXTDATA_H

#include "FlatBuffers/seance_generated.h"

#include <QChar>
#include <boost/serialization/access.hpp>

namespace boost {
namespace serialization {

template<class Archive>
void serialize(Archive& arch, QChar& ch, const unsigned int) {
  arch& ch.unicode();
}

} // namespace serialization
} // namespace boost

namespace NSApplication {
namespace NSKeyboard {

using NFbsSession::SLabelData;

struct CLabelData {
  QChar LowSymbol;
  QChar HighSymbol;
  unsigned char Size;

  static std::unique_ptr<SLabelData> createFbs(const CLabelData& from);

private:
  friend boost::serialization::access;
  template<class TArchive>
  void serialize(TArchive& arch, const unsigned int) {
    arch& LowSymbol;
    arch& HighSymbol;
    arch& Size;
  }
};

using NFbsSession::SKeyTextData;

struct CKeyTextData {
  static constexpr size_t SymbolSize = 2;
  QChar Symbol[SymbolSize];
  unsigned char Size;

  static std::unique_ptr<SKeyTextData> createFbs(const CKeyTextData& from);

private:
  friend boost::serialization::access;
  template<class TArchive>
  void serialize(TArchive& arch, const unsigned int) {
    arch& Symbol;
    arch& Size;
  }
};

} // namespace NSKeyboard
} // namespace NSApplication

#endif // NSAPPLICATION_NSKEYBOARD_CKEYTEXTDATA_H
