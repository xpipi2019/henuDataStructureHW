//
// Created by XPIPI on 24-11-22.
//

#ifndef MYSTACK_BITREE_H
#define MYSTACK_BITREE_H

#include "myBiTree.h"
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

// 自定义Stack
typedef BiTree SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stack_size;
}SqStack;

// Stack函数
inline void InitStack(SqStack& S) {
    S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(-1);
    S.top = S.base;
    S.stack_size = STACK_INIT_SIZE;
}

inline void Push(SqStack& S, SElemType e) {
    if (S.top - S.base >= S.stack_size) {
        // 栈还是动态更好
        S.base = (SElemType*)realloc(S.base, (S.stack_size + STACK_INCREMENT) * sizeof(SElemType));
        if (!S.base) exit(-1);
        S.top = S.base + S.stack_size;
        S.stack_size += STACK_INCREMENT;
    }
    *(S.top++) = e;
}

inline bool StackEmpty(SqStack S) {
    return S.top == S.base;
}

inline SElemType Pop(SqStack& S) {
    if (S.base == NULL) return NULL;
    return *(--S.top);
}


#endif //MYSTACK_BITREE_H
