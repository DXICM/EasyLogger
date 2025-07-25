#define LOG_TAG "moduleB"
#include <elog.h>
#include <unistd.h>
#include "module_b.h"

void* module_b_thread(void* arg) {
    for(int i=0;i<5;i++) {
        log_w("B loop %d", i);
        usleep(250000);
    }
    return NULL;
}
