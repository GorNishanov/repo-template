#include "stdx/__detail/platform.h"
#include <pthread.h>
#include <cstdint>

unsigned stdx::__detail::platform::get_current_thread_id() {
    uint64_t tid;
    pthread_threadid_np(NULL, &tid);
    return unsigned(tid);
}
