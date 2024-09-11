#include "stdx/__detail/platform.h"
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

namespace stdx::__detail::platform
{
    unsigned get_current_thread_id()
    {
      return syscall(SYS_gettid);
    }
}
