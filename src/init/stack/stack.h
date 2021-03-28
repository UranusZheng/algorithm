#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stdio.h>
#include "typedef.h"
#include "errorcode.h"

#define STACK_INIT_SIZE    100

typedef double ElemType;

typedef struct {
    ElemType *base;
    ElemType *top;
    int stackSize;
} sqStack;

uint32 initStack(sqStack *s);

uint32 push(sqStack *s, ElemType e);

bool isEmpty(sqStack *stack);

uint32 pop(sqStack *s, ElemType *e);

void clearStsck(sqStack *stack);

void destroyStack(sqStack *stack);

uint32 getStackSize(sqStack *stack);


#endif /* _STACK_H_ */