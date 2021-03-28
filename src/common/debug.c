#include "debug.h"
#include <time.h>

void printf_encap(char *file, const char *func, uint32 line, const char *fmt, ...)
{
    time_t cur_time;
    struct tm *tm_time;
    time(&cur_time);
    tm_time = gmtime(&cur_time);
    va_list args;
    va_start(args, fmt);
    printf("\r\n[%4d-%02d-%02d %02d:%02d:%02d][%s:%s][line:%d]",
           tm_time->tm_year + 1900, tm_time->tm_mon + 1, tm_time->tm_mday,
           tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec,
           file, func, line);
    printf(fmt, args);
    printf("\n");
    va_end(args);
}


/* 变长参数表函数实现方法 */
uint32 snprintf_s(char *fmt, ...)
{
    va_list ap;
    
}
