#include "stack.h"
#include "debug.h"
#include <stdlib.h>
#include <ctype.h>

#define TMP_BUF_LEN  10

uint32 calculator(char *exp, uint32 len, double *result)
{
    uint32 i;
    uint32 ret;
    char c;
    double num1;
    double num2;
    char tmp_buf[TMP_BUF_LEN] = {0};
    uint32 buf_index = 0;
    sqStack stack;

    if (exp == NULL || len == 0) {
        LOG_DEBUG("input is null...");
    }

    ret = initStack(&stack);
    if (ret != RET_OK) {
        return ret;
    }

    for (i = 0; i < len; i++) {
        c = exp[i];
        while (isdigit(c) || c == '.') {
            tmp_buf[buf_index++] = c;
            tmp_buf[buf_index] = '\0';
            if (buf_index >= 10) {
                LOG_DEBUG("the num is too long...");
                return RET_ERROR;
            }
            if (i < len - 1) {
                c = exp[++i];
            } else {
                break;
            }
            
            if (c == ' ') {
                num1 = atof(tmp_buf);
                LOG_DEBUG("tmp_buf is %f", num1);
                push(&stack, num1);
                buf_index = 0;
                break;
            }
        }
        switch (c) {
            case '+':
                pop(&stack, &num1);
                pop(&stack, &num2);
                push(&stack, num1 + num2);
                break;
            case '-':
                pop(&stack, &num1);
                pop(&stack, &num2);
                push(&stack, num2 - num1);
                break;
            case '*':
                pop(&stack, &num1);
                pop(&stack, &num2);
                push(&stack, num1 * num2);
                break;
            case '/':
                pop(&stack, &num1);
                pop(&stack, &num2);
                if (num1 == 0) {
                    LOG_DEBUG("Zero divisor...");
                    return RET_ERROR;
                }
                push(&stack, num2 / num1);
                break;
        }
    }

    pop(&stack, result);
    LOG_DEBUG("the result is %f", *result);
    return RET_OK;
}



// uint32 main()
// {
//     uint32 ret;
//     // 1 + 2 * 3 / 4 + 6 -3 * 2
//     char exp[] = "1 2 3 * 4 / + 6 + 3 2 * -";
//     uint32 len = sizeof(exp) / sizeof(exp[0]);
//     double res = 0;
//     ret = calculator(exp, len, &res);

//     return ret;

// }