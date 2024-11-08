//
// Created by XPIPI on 24-11-8.
//

#ifndef MYSTACK_H
#define MYSTACK_H

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef int SElementType;

typedef struct
{
    SElementType *base;
    SElementType *top;
    int stack_size;
}SqStack1;

#include "myBiTree.h"
typedef BiTree SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stack_size;
}SqStack2;

#endif //MYSTACK_H
