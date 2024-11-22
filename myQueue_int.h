//
// Created by XPIPI on 24-11-8.
//

#ifndef MYQUEUE_H
#define MYQUEUE_H

typedef int QElemType;

// 定义链队列结点
typedef int QElemType;
typedef struct QNode {
    QElemType data;
    struct QNode* next;
} *QueuePtr;

// 队列结构定义
typedef struct {
    QueuePtr front, rear;
} LinkQueue;

// 自定义队列函数
// 初始化：构造一个空队列Q
inline void InitLinkQueue(LinkQueue &Q) {
    Q.front = Q.rear = new QNode;
    //if (!Q.front) return false;
    Q.front->next = nullptr;
    //return true;
}

// 销毁：销毁一个队列Q
inline bool DestroyLinkQueue(LinkQueue &Q) {
    while (Q.front) {
        QueuePtr p = Q.front;
        Q.front = Q.front->next;
        delete p;
    }
    Q.front = Q.rear = nullptr;
    return true;
}

// 清空：清空一个队列Q
inline void ClearLinkQueue(LinkQueue &Q) {
    QueuePtr p = Q.front->next;
    while (p) {
        QueuePtr temp = p;
        p = p->next;
        delete temp;
    }
    Q.front->next = nullptr;
    Q.rear = Q.front;
    //return true;
}

// 判断是否为空队列
inline bool IsLinkQueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

// 队列长度：返回队列元素Q的个数
inline int LinkQueueLength(LinkQueue Q) {
    int length = 0;
    QueuePtr p = Q.front->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// 获取队头元素
inline bool GetFrontElem(LinkQueue Q, QElemType &e) {
    if (Q.front == Q.rear) return false;
    e = Q.front->next->data;
    return true;
}

// 入队：插入元素e为队列的队尾元素
inline void EnLinkQueue(LinkQueue &Q, QElemType e) {
    QueuePtr newNode = new QNode;
    //if (!newNode) return false;
    newNode->data = e;
    newNode->next = nullptr;
    Q.rear->next = newNode;
    Q.rear = newNode;
    //return true;
}

// 出队：删除队头元素
inline bool DeLinkQueue(LinkQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) return false;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    delete p;
    return true;
}

#endif //MYQUEUE_H
