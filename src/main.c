#include <stdio.h>
// #include <stdlib.h>
#include "debug.h"
#include <time.h>
#include "max_subsequence_sum.h"
#include "calculate.h"

void quit()
{
    printf("goodbye...\n");
}

uint32 main()
{
#if 0
    LOG_DEBUG("hello, welcome to zheng's space");
    _sleep(1000);
    LOG_DEBUG("goodbye");

    uint32 arr[] = {4, -3, 5, -2, -1, 2, 6, -2};
    uint32 ret = max_subsequence_sum(arr, 8);
    LOG_DEBUG("ret = %u", ret);


    uint32 ret;
    // 1 + 2 * 3 / 4 + 6 -3 * 2
    char exp[] = "1 2 3 * 4 / + 6 + 3 2 * -";
    uint32 len = sizeof(exp) / sizeof(exp[0]);
    printf("%d\n", sizeof(exp));
    printf("%d\n", sizeof(exp[0]));
    printf("%d\n", len);
    LOG_DEBUG("strlen is %d", len);
    double res = 0;
    ret = calculator(exp, len, &res);
#endif
    uint32 choice;
    printf("----------------welcome to URANUS system----------------\n");
    printf("choose what you want to do:\n");
    printf("    (1) calculate;\n");
    printf("        .......\n");
    printf("    (0) quit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("welcome to calculate...");
	        break;
            case 0:
                quit();
                return 0;
	    default:
	        printf("wrong choice, input again:\n");
	        break;  
        }
    }  

    //system("pause");
    return 0;
}
