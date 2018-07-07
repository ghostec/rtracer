cmake_minimum_required(VERSION 3.11.4)
project(rcanvas VERSION 0.1.0 LANGUAGES CXX)

add_compile_options(-W -Wall -Werror)

add_subdirectory(src)

add_executable(rcanvas src/main.cpp)
target_compile_features(rcanvas PRIVATE cxx_std_17)
target_link_libraries(rcanvas RCanvas)

option(BUILD_TESTS "Determines whether to build tests." OFF)
if(BUILD_TESTS)
  enable_testing()

  add_library(Catch INTERFACE)
  target_sources(
    Catch
    INTERFACE
      $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/test/catch.hpp>
  )

  add_executable(
    rcanvas_test
    test/catch.cpp
    test/float64_test.cpp
  )
  target_link_libraries(rcanvas_test PUBLIC Catch RCanvas)
  target_include_directories(
    rcanvas_test
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    PRIVATE
      ${PROJECT_SOURCE_DIR}/test
  )
  add_test(NAME TestBase COMMAND rcanvas_test)
endif()
