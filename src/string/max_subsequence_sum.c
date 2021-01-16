#include "typedef.h"
#include "debug.h"

uint32 max_subsequence_sum(const uint32 *arr, uint32 arr_len)
{
    uint32 max_sum = 0;
    uint32 cur_sum = 0;

    for (uint32 i = 0; i < arr_len; i++) {
        cur_sum += arr[i];
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
        } else if (cur_sum < 0) {
            cur_sum = 0;
        }
    }
    return max_sum;
}



#if 0

uint32 main()
{
    uint32 arr[] = {4, -3, 5, -2, -1, 2, 6, -2};
    uint32 ret = max_subsequence_sum(arr, sizeof(arr));
    LOG_DEBUG(ret);
}

#endif