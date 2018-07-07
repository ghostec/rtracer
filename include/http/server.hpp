#pragma once

#include <pistache/endpoint.h>

namespace rcanvas::http {

using namespace Pistache;

class HelloHandler : public Http::Handler {
  HTTP_PROTOTYPE(HelloHandler)

  void onRequest(const Http::Request & /* request */,
                 Http::ResponseWriter writer);
};
} // namespace rcanvas::http
