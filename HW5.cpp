//
// Created by XPIPI on 24-10-27.
// 参考:https://blog.csdn.net/qq_40953393/article/details/78935522
//
#include <iostream>
#include "myQueue.h"
using namespace std;

// 初始化：构造一个空队列Q
bool InitLQueue(LQueue &Q) {
    Q.front = Q.rear = new QNode;
    if (!Q.front) return false;
    Q.front->next = nullptr;
    return true;
}

// 销毁：销毁一个队列Q
bool DestroyLQueue(LQueue &Q) {
    while (Q.front) {
        QueuePtr p = Q.front;
        Q.front = Q.front->next;
        delete p;
    }
    Q.front = Q.rear = nullptr;
    return true;
}

// 清空：清空一个队列Q
bool ClearLQueue(LQueue &Q) {
    QueuePtr p = Q.front->next;
    while (p) {
        QueuePtr temp = p;
        p = p->next;
        delete temp;
    }
    Q.front->next = nullptr;
    Q.rear = Q.front;
    return true;
}

// 判断是否为空队列
bool IsLQueueEmpty(LQueue Q) {
    return Q.front == Q.rear;
}

// 队列长度：返回队列元素Q的个数
int LQueueLength(LQueue Q) {
    int length = 0;
    QueuePtr p = Q.front->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// 获取队头元素
bool GetFrontElem(LQueue Q, QElemType &e) {
    if (Q.front == Q.rear) return false;
    e = Q.front->next->data;
    return true;
}

// 入队：插入元素e为队列的队尾元素
bool EnLQueue(LQueue &Q, QElemType e) {
    QueuePtr newNode = new QNode;
    if (!newNode) return false;
    newNode->data = e;
    newNode->next = nullptr;
    Q.rear->next = newNode;
    Q.rear = newNode;
    return true;
}

// 出队：删除队头元素
bool DeLQueue(LQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) return false;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    delete p;
    return true;
}

// 遍历队列
bool LQueueTraverse(LQueue Q, bool (*Visit)(QElemType)) {
    QueuePtr p = Q.front->next;
    while (p) {
        if (!Visit(p->data)) return false;
        p = p->next;
    }
    return true;
}

// 输出元素的函数
bool PrintElem(QElemType e) {
    cout << e << " ";
    return true;
}

// 重新排队
void RearrangeQueues(LQueue &A, LQueue &B, LQueue &C) {
    QueuePtr p = A.front->next;
    while (p) {
        if (p->data % 2 == 0) {
            EnLQueue(B, p->data);
        } else {
            EnLQueue(C, p->data);
        }
        p = p->next;
    }
}

void Menu() {
    cout << "菜单：" << endl;
    cout << "1. 初始化队列" << endl;
    cout << "2. 销毁队列" << endl;
    cout << "3. 清空队列" << endl;
    cout << "4. 队列判空" << endl;
    cout << "5. 求队列长度" << endl;
    cout << "6. 获取队头元素" << endl;
    cout << "7. 插入一个元素" << endl;
    cout << "8. 删除一个元素" << endl;
    cout << "9. 输出所有元素" << endl;
    cout << "10. 重新排队" << endl;
    cout << "0. 退出" << endl;
}

int HW5() {
    LQueue A, B, C;
    int choice, elem;
    bool initialized = false;

    while (true) {
        Menu();
        cout << "请选择操作：";
        cin >> choice;

        switch (choice) {
            case 1:
                if (InitLQueue(A)) {
                    initialized = true;
                    cout << "队列初始化成功！" << endl;
                } else {
                    cout << "队列初始化失败！" << endl;
                }
                break;
            case 2:
                if (initialized && DestroyLQueue(A)) {
                    initialized = false;
                    cout << "队列销毁成功！" << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;
            case 3:
                if (initialized && ClearLQueue(A)) {
                    cout << "队列清空成功！" << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;
            case 4:
                if (initialized) {
                    if (IsLQueueEmpty(A))
                        cout << "队列为空！" << endl;
                    else
                        cout << "队列不为空！" << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;
            case 5:
                if (initialized) {
                    cout << "队列长度为：" << LQueueLength(A) << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;
            case 6:
                if (initialized && GetFrontElem(A, elem)) {
                    cout << "队头元素为：" << elem << endl;
                } else {
                    cout << "获取队头元素失败，队列可能未初始化或为空！" << endl;
                }
                break;
            case 7:
                if (initialized) {
                    cout << "请输入要插入的元素：";
                    cin >> elem;
                    if (EnLQueue(A, elem))
                        cout << "元素插入成功！" << endl;
                    else
                        cout << "元素插入失败！" << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;
            case 8:
                if (initialized && DeLQueue(A, elem)) {
                    cout << "删除的队头元素为：" << elem << endl;
                } else {
                    cout << "删除队头元素失败，队列可能未初始化或为空！" << endl;
                }
                break;
            case 9:
                if (initialized) {
                    cout << "队列元素：";
                    LQueueTraverse(A, PrintElem);
                    cout << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;
            case 10:
                if (initialized) {
                    InitLQueue(B);
                    InitLQueue(C);
                    RearrangeQueues(A, B, C);
                    cout << "队列B（女生）元素：";
                    LQueueTraverse(B, PrintElem);
                    cout << endl << "队列C（男生）元素：";
                    LQueueTraverse(C, PrintElem);
                    cout << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;
            case 0:
                return 0;
            default:
                cout << "无效选择，请重新选择！" << endl;
                break;
        }
    }
}
