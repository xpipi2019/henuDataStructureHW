//
// Created by XPIPI on 24-11-8.
//

#ifndef MYSTACK_H
#define MYSTACK_H

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

// 自定义Stack
typedef int SElementType;

typedef struct
{
    SElementType *base;
    SElementType *top;
    int stack_size;
}SqStack;

// Stack函数
// 初始化
inline bool InitStack(SqStack &S) {
    S.base = (SElementType *)malloc(STACK_INIT_SIZE * sizeof(SElementType));
    if (!S.base) return false;
    S.top = S.base;
    S.stack_size = STACK_INIT_SIZE;
    return true;
}

// 销毁
inline bool DestroyStack(SqStack &S) {
    if (S.base) {
        free(S.base);
        S.top = nullptr;
        S.base = nullptr;
        S.stack_size = 0;
        return true;
    }
    return false;
}

// 清除元素
inline void ClearStack(SqStack &S) {
    S.top = S.base;
}

//检查是否为空
inline bool StackEmpty(SqStack S) {
    return S.top == S.base;
}

// 栈的长度
int StackLength(SqStack S) {
    return S.top - S.base;
}

//获取栈顶
bool GetTop(SqStack S, SElementType &e) {
    if (S.top == S.base) return false;
    e = *(S.top - 1);
    return true;
}

//在栈顶添加元素
bool Push(SqStack &S, SElementType e) {
    if (StackLength(S) >= S.stack_size){
        S.base = (SElementType * ) realloc(S.base, (S.stack_size + 1) * sizeof(SElementType));
        if (!S.base) return false;
        S.top = S.base + S.stack_size;
        S.stack_size += STACK_INCREMENT;
    }
    *S.top++ = e;
    return true;
}

//弹出栈顶
bool Pop(SqStack &S, SElementType &e) {
    if (S.top == S.base) return false;
    e = *(--S.top);
    return true;
}

#endif //MYSTACK_H
