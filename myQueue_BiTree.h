//
// Created by XPIPI on 24-11-22.
//

#ifndef MYQUEUE_BITREE_H
#define MYQUEUE_BITREE_H
#include "myBiTree.h"

// 定义链队列结点
typedef BiTree QElemType;
typedef struct QNode {
    QElemType data;
    struct QNode* next;
} *QueuePtr;

// 队列结构定义
typedef struct {
    QueuePtr front, rear;
} LinkQueue;

// 自定义队列函数
inline void InitQueue(LinkQueue& Q) {
    Q.front = (QueuePtr)malloc(sizeof(QNode));
    Q.rear = Q.front;
    if (!Q.front) exit(-1);
    Q.front->next = nullptr;
}

inline void EnQueue(LinkQueue& Q, QElemType e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) exit(-1);
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
}

inline QElemType DeQueue(LinkQueue& Q) {
    if (Q.front == Q.rear) return NULL;
    QueuePtr p = Q.front->next;
    QElemType e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return e;
}

inline bool QueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

#endif //MYQUEUE_BITREE_H
