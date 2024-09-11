#include <catch2/catch_test_macros.hpp>
#include "stdx/format.h"
#include <cstdio>

using namespace stdx;
TEST_CASE("conqueue: smoketest") {
  println("Hello {}", 42);
  REQUIRE(true);
}
