//
// Created by XPIPI on 24-10-27.
// 参考:https://blog.csdn.net/qq_40953393/article/details/78935522
//
#include <iostream>
#include "myQueue_int.h"
using namespace std;

// 遍历队列
bool LinkQueueTraverse(LinkQueue Q, bool (*Visit)(QElemType)) {
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
void RearrangeQueues(LinkQueue &A, LinkQueue &B, LinkQueue &C) {
    QueuePtr p = A.front->next;
    while (p) {
        if (p->data % 2 == 0) {
            EnLinkQueue(B, p->data);
        } else {
            EnLinkQueue(C, p->data);
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
    LinkQueue A, B, C;
    int choice, elem;
    bool initialized = false;

    while (true) {
        Menu();
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
                    if (IsLinkQueueEmpty(A))
                        cout << "队列为空！" << endl;
                    else
                        cout << "队列不为空！" << endl;
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
                if (initialized){
                    cout << "请输入要插入的元素：";
                    cin >> elem;
                    EnLinkQueue(A, elem);
                    cout << "元素插入成功！" << endl;
                }else {
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
                    LinkQueueTraverse(A, PrintElem);
                    cout << endl;
                } else {
                    cout << "请先初始化队列！" << endl;
                }
                break;
            case 10:
                if (initialized) {
                    InitLinkQueue(B);
                    InitLinkQueue(C);
                    RearrangeQueues(A, B, C);
                    cout << "队列B（女生）元素：";
                    LinkQueueTraverse(B, PrintElem);
                    cout << endl << "队列C（男生）元素：";
                    LinkQueueTraverse(C, PrintElem);
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
