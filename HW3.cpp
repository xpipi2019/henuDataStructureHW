//
// Created by XPIPI on 24-10-7.
// 参考1：数据结构（C语言版）——清华大学出版社
// 参考2：https://blog.csdn.net/daocaoren_/article/details/96433693
// 参考3：https://blog.csdn.net/qq_54210270/article/details/122868516
// 参考4：https://blog.csdn.net/Gentle722/article/details/106173472
//
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef int ElemType;

struct Lnode {
    ElemType data;
    Lnode* next = nullptr;
};

using LinkList = Lnode*;

// 初始化链表为空
void initList(LinkList& L) {
    L = (LinkList)malloc(sizeof(Lnode));
    L->next = nullptr;
}

void destroyList(LinkList& L) {
    if (!L) return;
    Lnode* current = L->next;
    while (current) {
        Lnode* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(L);
    L = nullptr;
}

void clearList(LinkList& L) {
    if (!L) return;
    Lnode* current = L->next;
    while (current) {
        Lnode* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    L->next = nullptr;
}

// 求链表长度
int getLength(const LinkList L) {
    int length = 0;
    Lnode* p = L->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// 获取指定位置元素
bool getElem(const LinkList L, int i, ElemType& e) {
    if (i < 1) return false;
    Lnode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) return false;
    e = p->data;
    return true;
}

// 查找元素的位置
int locateElem(const LinkList L, ElemType e) {
    Lnode* p = L->next;
    int pos = 1;
    while (p && p->data != e) {
        p = p->next;
        pos++;
    }
    return p ? pos : 0;
}

// 求前驱
bool getPredecessor(const LinkList L, ElemType e, ElemType& pre) {
    Lnode* p = L->next;
    if (!p || p->data == e) return false;
    while (p->next && p->next->data != e) {
        p = p->next;
    }
    if (!p->next) return false;
    pre = p->data;
    return true;
}

// 求后继
bool getSuccessor(const LinkList L, ElemType e, ElemType& next) {
    Lnode* p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    if (!p || !p->next) return false;
    next = p->next->data;
    return true;
}

// 在第i个位置插入元素
bool insertElem(LinkList& L, int i, ElemType e) {
    if (i < 1) return false;
    Lnode* p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) return false;
    Lnode* s = (Lnode*)malloc(sizeof(Lnode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除第i个元素
bool deleteElem(LinkList& L, int i, ElemType& e) {
    if (i < 1 || i > getLength(L)) return false;
    Lnode* p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1) return false;
    Lnode* q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}

void printList(const LinkList L) {
    Lnode* p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 用头插法初始化链表
void headInsert(LinkList& L, int n) {
    for (int i = 0; i < n; i++) {
        Lnode* s = (Lnode*)malloc(sizeof(Lnode));
        cin >> s->data;
        s->next = L->next;
        L->next = s;
    }
}

// 链表逆序
void reverseList(LinkList& L) {
    if (!L || !L->next) return;
    LinkList reversedHead = (LinkList)malloc(sizeof(Lnode));
    reversedHead->next = nullptr;
    Lnode* current = L->next;
    while (current) {
        Lnode* nextNode = current->next;
        current->next = reversedHead->next;
        reversedHead->next = current;
        current = nextNode;
    }
    free(L);
    L = reversedHead;
}

// 链表排序
void sortList(LinkList& L) {
    if (!L->next || !L->next->next) return;
    Lnode* p1 = L->next;
    for (; p1->next; p1 = p1->next) {
        for (Lnode* p2 = L->next; p2->next; p2 = p2->next) {
            if (p2->data > p2->next->data) {
                swap(p2->data, p2->next->data);
            }
        }
    }
}

int HW3() {
    LinkList L = nullptr;
    int choice, pos, len;
    ElemType elem, e;

    do {
        cout << "1. 初始化或重置链表" << endl;
        cout << "2. 销毁链表" << endl;
        cout << "3. 清空链表" << endl;
        cout << "4. 链表长度" << endl;
        cout << "5. 指定位置的元素值" << endl;
        cout << "6. 链表已存在元素的位序" << endl;
        cout << "7. 求输入元素的直接前驱" << endl;
        cout << "8. 求输入元素的直接后继" << endl;
        cout << "9. 在第i个位置插入一个元素" << endl;
        cout << "10. 删除第i个元素" << endl;
        cout << "11. 输出有的链表元素" << endl;
        cout << "12. 初始化并用头插法输入元素" << endl;
        cout << "13. 链表逆序" << endl;
        cout << "14. 链表排序" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作：";
        cin >> choice;

        if (choice == 0) break;

        if(choice == 12){
            if(L == nullptr){
                cout << "请输入元素个数：";
                cin >> len;
                initList(L);
                cout << "请输入 " << len << " 个用空格隔开的元素：" << endl;
                headInsert(L, len);
                cout << "链表头插法初始化成功！" << endl;
            }
            else{
                cout << "链表已完成初始化，不可再使用头插法初始化！" << endl;
            }
        }

        if (choice > 1 && choice <= 14 && !L) {
            cout << "链表未初始化，请先初始化链表！" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                initList(L);
                cout << "链表初始化成功！" << endl;
                break;
            case 2:
                destroyList(L);
                cout << "链表销毁成功！" << endl;
                break;
            case 3:
                clearList(L);
                cout << "链表清空成功！" << endl;
                break;
            case 4:
                cout << "链表长度为：" << getLength(L) << endl;
                break;
            case 5:
                cout << "请输入位置：";
                cin >> pos;
                if (getElem(L, pos, e))
                    cout << "第 " << pos << " 个元素为：" << e << endl;
                else
                    cout << "位置无效！" << endl;
                break;
            case 6:
                cout << "请输入要查找的元素：";
                cin >> elem;
                pos = locateElem(L, elem);
                if (pos)
                    cout << elem << " 的位置为：" << pos << endl;
                else
                    cout << "未找到该元素！" << endl;
                break;
            case 7:
                cout << "请输入元素：";
                cin >> elem;
                if (getPredecessor(L, elem, e))
                    cout << elem << " 的前驱为：" << e << endl;
                else
                    cout << "该元素无前驱！" << endl;
                break;
            case 8:
                cout << "请输入元素：";
                cin >> elem;
                if (getSuccessor(L, elem, e))
                    cout << elem << " 的后继为：" << e << endl;
                else
                    cout << "该元素无后继！" << endl;
                break;
            case 9:
                cout << "请输入位置和元素：";
                cin >> pos >> elem;
                if (insertElem(L, pos, elem))
                    cout << "元素插入成功！" << endl;
                else
                    cout << "插入失败！" << endl;
                break;
            case 10:
                cout << "请输入删除位置：";
                cin >> pos;
                if (deleteElem(L, pos, e))
                    cout << "删除元素 " << e << " 成功！" << endl;
                else
                    cout << "删除失败！" << endl;
                break;
            case 11:
                cout << "链表中的元素为：";
                printList(L);
                break;
            //case 12:
            case 13:
                reverseList(L);
                cout << "链表逆序成功！" << endl;
                break;
            case 14:
                sortList(L);
                cout << "链表排序成功！" << endl;
                break;
            default:
                cout << "无效操作！" << endl;
                break;
        }
    } while (choice >= 0);

    destroyList(L);
    return 0;
}
