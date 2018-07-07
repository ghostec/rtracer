find_package(Pistache REQUIRED)

add_library(RCanvas http/server.cpp)

target_include_directories(
  RCanvas
  PUBLIC
    $<INSTALL_INTERFACE:include>    
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(RCanvas PUBLIC pistache)
target_compile_features(RCanvas PRIVATE cxx_std_17)
