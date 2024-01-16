#include "KeyTextData.h"

namespace NSApplication {
namespace NSKeyboard {
  std::unique_ptr<SLabelData> CLabelData::createFbs(const CLabelData& from) {
    return std::make_unique<SLabelData>(
      from.LowSymbol.unicode(),
      from.HighSymbol.unicode(),
      from.Size
    );
  }

  std::unique_ptr<SKeyTextData> CKeyTextData::createFbs(const CKeyTextData& from) {
    uint16_t symbolUnicode[CKeyTextData::SymbolSize];
    for (size_t i = 0; i < CKeyTextData::SymbolSize; ++i) {
        symbolUnicode[i] = from.Symbol[i].unicode();
    }

    return std::make_unique<SKeyTextData>(
      symbolUnicode,
      from.Size
    );
  }


} // namespace NSKeyboard
} // namespace NSApplication
