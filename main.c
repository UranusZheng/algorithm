#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
#include <time.h>
#include "max_subsequence_sum.h"

uint32 main()
{
    LOG_DEBUG("hello, welcome to zheng's space");
    _sleep(1000);
    LOG_DEBUG("goodbye");

    uint32 arr[] = {4, -3, 5, -2, -1, 2, 6, -2};
    uint32 ret = max_subsequence_sum(arr, 8);
    LOG_DEBUG("ret = %u", ret);

    system("pause");
    return 0;
}