#include "http/server.hpp"
#include <iostream>

int main() {
  Pistache::Http::listenAndServe<rcanvas::http::HelloHandler>("*:9080");
  return 0;
}
