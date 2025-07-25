#define LOG_TAG "moduleA"
#include <elog.h>
#include <unistd.h>
#include "module_a.h"

void* module_a_thread(void* arg) {
    for(int i=0;i<5;i++) {
        log_i("A loop %d", i);
        usleep(200000);
    }
    return NULL;
}
