#include <catch2/catch_test_macros.hpp>
#include "stdx/format.h"
#include "stdx/__detail/platform.h"

using namespace stdx;
TEST_CASE("conqueue: smoketest") {
  println("{:08}: Hello {}", stdx::__detail::platform::get_current_thread_id(), "world");
  REQUIRE(true);
}
