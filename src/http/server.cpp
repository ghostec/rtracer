#include "canvas/canvas.hpp"
#include "http/server.hpp"
#include <sstream>

namespace rcanvas::http {

using namespace Pistache;

void HelloHandler::onRequest(const Http::Request & /* request */,
                             Http::ResponseWriter writer) {
  rcanvas::Canvas c(10, 20);
  std::ostringstream stream;
  stream << c;
  std::string str = stream.str();
  writer.headers().add<Http::Header::AccessControlAllowOrigin>("*");
  writer.send(Http::Code::Ok, str);
}

} // namespace rcanvas::http
