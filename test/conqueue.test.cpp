#include <catch2/catch_test_macros.hpp>
#include "stdx/format.h"
#include <cstdio>

template <typename... Args>
void println(stdx::format_string<Args...> fmt, Args&&... args) {
  puts(stdx::vformat(fmt.get(), stdx::make_format_args(args...)).c_str());
}

using namespace std;
TEST_CASE("conqueue: smoketest") {
  println("Hello {}", 42);
  REQUIRE(true);
}
