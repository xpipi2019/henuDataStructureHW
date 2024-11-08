//
// Created by XPIPI on 24-11-8.
//

#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "myBiTree.h"

typedef int QElemType;

// 定义链队列结点
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

// 队列结构定义
typedef struct LQueue {
    QueuePtr front, rear;
} LQueue;

typedef BiTree QElemType2;
typedef struct QNode2 {
    QElemType2 data;
    struct QNode2* next;
} *QueuePtr2;

typedef struct {
    QueuePtr2 front, rear;
} LinkQueue;

#endif //MYQUEUE_H
