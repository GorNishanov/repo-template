#include "stdx/__detail/platform.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

unsigned stdx::__detail::platform::get_current_thread_id() {
  return GetCurrentThreadId();
}
