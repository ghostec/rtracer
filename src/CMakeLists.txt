add_library(RCanvas math/vec3.cpp)

target_include_directories(
  RCanvas
  PUBLIC
    $<INSTALL_INTERFACE:include>    
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_compile_features(RCanvas PRIVATE cxx_std_17)
