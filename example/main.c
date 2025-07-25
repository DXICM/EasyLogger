#include <pthread.h>
#include <stdio.h>
#include <elog.h>
#include "module_a/module_a.h"
#include "module_b/module_b.h"

int main(void) {
    setbuf(stdout, NULL);
    if (elog_init() != ELOG_NO_ERR) {
        printf("elog init failed\n");
        return -1;
    }
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_ALL); 
    elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_ALL); 
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL);
#ifdef ELOG_COLOR_ENABLE
    elog_set_text_color_enabled(true);
#endif
    elog_start();

    pthread_t t1, t2;
    pthread_create(&t1, NULL, module_a_thread, NULL);
    pthread_create(&t2, NULL, module_b_thread, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    elog_stop();
    elog_deinit();

    return 0;
}
