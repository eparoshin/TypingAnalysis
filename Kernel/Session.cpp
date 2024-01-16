#include "Session.h"
#include <algorithm>

namespace NSApplication {
namespace NSKernel {
 std::unique_ptr<TSessionT> CSession::createFbs(const CSession& from) {
   TSessionT session;
   session.key_events.reserve(from.size());
   std::transform(from.cbegin(), from.cend(), std::back_inserter(session.key_events), CKeyEvent::createFbs);
   return std::make_unique<TSessionT>(std::move(session));
 }

} // namespace NSKernel
} // namespace NSApplication
