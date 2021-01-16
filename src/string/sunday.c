#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "errorcode.h"
#include <string.h>

#define SHIFT_TABLE_MAX_LEN 256

uint32 get_shift_table(char *patterm, uint32 patterm_len, uint32 *shift_table)
{
    char *last_ptr = NULL;
    uint32 loop;

    for (loop = 0; loop < SHIFT_TABLE_MAX_LEN; loop++) {
        shift_table[loop] = patterm_len + 1;
    }

    for (loop = 0; loop < patterm_len; loop++) {
        last_ptr = strrchr(patterm, patterm[loop]);
        shift_table[patterm[loop]] = patterm_len - (last_ptr - patterm);
    }
    return RET_OK;
}

uint32 sunday_strcmp(char *str, uint32 strlen, char *patterm, uint32 patterm_len)
{
    uint32 ret;
    uint32 tmp;
    uint32 str_index = 0;
    uint32 patterm_index;
    uint32 shift_table[SHIFT_TABLE_MAX_LEN] = {0};

    if(str == NULL || patterm == NULL) {
        printf("str or patterm is null\n");
        return RET_E_NULL_PTR;
    }

    if (strlen < patterm_len) {
        printf("patterm is too long\n");
        return RET_ERROR;
    }

    ret = get_shift_table(patterm, patterm_len, shift_table);
    if (ret != RET_OK) {
        printf("get shift table err\n");
        return ret;
    }

    while (str_index <= strlen - patterm_len) {
        patterm_index = 0;
        while (str[str_index + patterm_index] == patterm[patterm_index]) {
            if (patterm_index == patterm_len - 1) {
                printf("match succeed...");
                return RET_OK;
            }
            patterm_index++;
        }
        str_index += shift_table[str[str_index + patterm_len]];
    }
    printf("match failed..");
    return RET_ERROR;
}