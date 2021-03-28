#ifndef _DEBUG_H_
#define _DEBUG_H_

#include "typedef.h"
#include <stdio.h>
#include <time.h>
#include <stdarg.h>

void printf_encap(char *file, const char *func, uint32 line, const char *fmt, ...);

#define LOG_DEBUG(...)    printf_encap(__FILE__, __func__, __LINE__, __VA_ARGS__)

// #define LOG_DEBUG(...) { \
//     time_t cur_time; \
//     struct tm *tm_time; \
//     time(&cur_time); \
//     tm_time = gmtime(&cur_time); \
//     printf("\r\n[%4d-%02d-%02d %02d:%02d:%02d][%s:%s][line:%d]", \
//            tm_time->tm_year + 1900, tm_time->tm_mon + 1, tm_time->tm_mday, \
//            tm_time->tm_hour, tm_time->tm_min, tm_time->tm_sec, \
//            __FILE__, __func__, __LINE__); \
//     printf(__VA_ARGS__);  \
// }

#endif /* _DEBUG_H_ */