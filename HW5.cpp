//
// Created by XPIPI on 24-10-27.
// 参考:https://blog.csdn.net/qq_40953393/article/details/78935522
//
#include <iostream>
#include "myQueue_int.h"

using namespace std;

// 遍历队列
bool linkQueueTraverse(LinkQueue Q, bool (*visit)(QElemType)) {
    QueuePtr p = Q.front->next;
    while (p) {
        if (!visit(p->data)) return false;
        p = p->next;
    }
    return true;
}

bool printElem(QElemType e) {
    cout << e << " ";
    return true;
}

// 重新排队
void rearrangeQueues(LinkQueue& A, LinkQueue& B, LinkQueue& C) {
    QueuePtr p = A.front->next;
    while (p) {
        if (p->data % 2 == 0) { // 偶数入队B
            EnLinkQueue(B, p->data);
        } else { // 奇数入队C
            EnLinkQueue(C, p->data);
        }
        p = p->next;
    }
}

int HW5() {
    LinkQueue A, B, C;
    int choice, elem;
    bool initialized = false;

    while (true) {
        cout << "1. 初始化队列" << endl;
        cout << "2. 销毁队列" << endl;
        cout << "3. 清空队列" << endl;
        cout << "4. 判断队列是否为空" << endl;
        cout << "5. 求队列长度" << endl;
        cout << "6. 获取队头元素" << endl;
        cout << "7. 插入一个元素" << endl;
        cout << "8. 删除一个元素" << endl;
        cout << "9. 输出所有元素" << endl;
        cout << "10. 重新排队" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作：";
        cin >> choice;

        switch (choice) {
            case 1:
                InitLinkQueue(A);
                initialized = true;
                cout << "队列初始化成功！" << endl;
                break;

            case 2:
                if (initialized && DestroyLinkQueue(A)) {
                    initialized = false;
                    cout << "队列销毁成功！" << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;

            case 3:
                if (initialized) {
                    ClearLinkQueue(A);
                    cout << "队列清空成功！" << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;

            case 4:
                if (initialized) {
                    cout << (IsLinkQueueEmpty(A) ? "队列为空！" : "队列不为空！") << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;

            case 5:
                if (initialized) {
                    cout << "队列长度为：" << LinkQueueLength(A) << endl;
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
                    EnLinkQueue(A, elem);
                    cout << "元素插入成功！" << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;

            case 8:
                if (initialized && DeLinkQueue(A, elem)) {
                    cout << "删除的队头元素为：" << elem << endl;
                } else {
                    cout << "删除队头元素失败，队列可能未初始化或为空！" << endl;
                }
                break;

            case 9:
                if (initialized) {
                    cout << "队列元素：";
                    linkQueueTraverse(A, printElem);
                    cout << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;

            case 10:
                if (initialized) {
                    // 初始化队列BC
                    InitLinkQueue(B);
                    InitLinkQueue(C);
                    rearrangeQueues(A, B, C);
                    cout << "队列B（偶数）元素：";
                    linkQueueTraverse(B, printElem);
                    cout << endl << "队列C（奇数）元素：";
                    linkQueueTraverse(C, printElem);
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

