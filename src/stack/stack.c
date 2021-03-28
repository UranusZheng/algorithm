
#include "stack.h"
#include "stdlib.h"
#include "debug.h"

uint32 initStack(sqStack *s)
{
    s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (s->base == NULL) {
        printf("malloc memory failed...\n");
        return RET_E_NO_MEMORY;
    }
    s->top = s->base;    /* 初始化，栈顶就是栈底 */
    s->stackSize = STACK_INIT_SIZE;
    return RET_OK;
}

uint32 push(sqStack *s, ElemType e)
{
    if (s->top - s->base >= s->stackSize) {
        s->base = (ElemType*)realloc(s->base, (s->stackSize + STACK_INIT_SIZE) * sizeof(ElemType));
        if (s->base == NULL) {
            printf("realloc memory for stack failed...\n");
            return RET_E_NO_MEMORY;
        }
        s->top = s->base + s->stackSize;    /* 设置栈顶 */
        s->stackSize = s->stackSize + STACK_INIT_SIZE;    /* 设置栈的最大容量 */
    }
    *(s->top) = e;
    s->top++;
    return RET_OK;
}

bool isEmpty(sqStack *stack)
{
    if (stack->top == stack->base) {
        return true;
    } else {
        return false;
    }
}

uint32 pop(sqStack *s, ElemType *e)
{
    if (isEmpty(s) == true) {
        printf("stack is empty...\n");
        return RET_E_EMPTY;
    }
    *e = *--(s->top);
    return RET_OK;
}

void clearStsck(sqStack *stack)
{
    stack->top = stack->base;
}

void destroyStack(sqStack *stack)
{
    uint32 len = stack->stackSize;
    for (uint32 i = 0; i < len; i++) {
        free(stack->base);
        stack->base++;
    }
    stack->base = stack->top = NULL;
    stack->stackSize = 0;
}

uint32 getStackSize(sqStack *stack)
{
    return stack->top - stack->base;
}
