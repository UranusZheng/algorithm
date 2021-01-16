#include "debug.h"
#include <time.h>

void printf_encap(char *file, const char *func, uint32 line, char *log)
{
    time_t cur_time;
    struct tm *tm_time;
    time(&cur_time);
    tm_time = gmtime(&cur_time);
    printf("[%4d-%02d-%02d %02d:%02d:%02d][%s:%s][line:%d] %s\n",
           tm_time->tm_year + 1900, tm_time->tm_mon + 1, tm_time->tm_mday,
           tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec,
           file, func, line, log);
}

