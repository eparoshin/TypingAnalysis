#include "Seance.h"

#include <algorithm>

namespace NSApplication {
namespace NSKernel {
  std::unique_ptr<TSeanceT> CSeance::createFbs(const CSeance& from) {
    TSeanceT seance;
    seance.sessions.reserve(from.size());
   std::transform(from.cbegin(), from.cend(), std::back_inserter(seance.sessions), CSession::createFbs);
   return std::make_unique<TSeanceT>(std::move(seance));
  }

} // namespace NSKernel
} // namespace NSApplication
