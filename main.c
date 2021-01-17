#include <stdio.h>
// #include <stdlib.h>
#include "debug.h"
#include <time.h>
#include "max_subsequence_sum.h"
#include "calculate.h"

uint32 main()
{
#if 0
    LOG_DEBUG("hello, welcome to zheng's space");
    _sleep(1000);
    LOG_DEBUG("goodbye");

    uint32 arr[] = {4, -3, 5, -2, -1, 2, 6, -2};
    uint32 ret = max_subsequence_sum(arr, 8);
    LOG_DEBUG("ret = %u", ret);
#endif

    uint32 ret;
    // 1 + 2 * 3 / 4 + 6 -3 * 2
    char exp[] = "1 2 3 * 4 / + 6 + 3 2 * -";
    uint32 len = sizeof(exp) / sizeof(exp[0]);
    LOG_DEBUG("strlen is %d", len);
    double res = 0;
    ret = calculator(exp, len, &res);

    system("pause");
    return 0;
}