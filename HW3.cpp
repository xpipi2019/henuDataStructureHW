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

// 单链表存储结构
typedef struct Lnode {
    ElemType data;
    struct Lnode* next;
} Lnode, *LinkList;

LinkList L;
Lnode *p, *s;

// 初始化链表为空链表
void initList(LinkList &L) {
    L = (LinkList)malloc(sizeof(Lnode));
    L->next = nullptr;
}

// 销毁链表
void destroyList(LinkList &L) {
    if (L == nullptr) return;
    Lnode *current = L->next;
    while (current != nullptr) {
        Lnode *nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(L);
    L = nullptr;
}

// 清空链表
void clearList(LinkList &L) {
    if (L == nullptr) return;
    Lnode *current = L->next;
    while (current != nullptr) {
        Lnode *nextNode = current->next;
        free(current);
        current = nextNode;
    }
    L->next = nullptr;
}

// 求链表长度
int listLength(LinkList L) {
    int length = 0;
    p = L->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// 获取指定位置元素
bool getElem(LinkList L, int i, ElemType &e) {
    if (i < 1) return false;
    p = L->next;
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
int locateElem(LinkList L, ElemType e) {
    p = L->next;
    int j = 1;
    while (p && p->data != e) {
        p = p->next;
        j++;
    }
    return (p) ? j : 0;
}

// 求输入元素的前驱
bool getPriorElem(LinkList L, ElemType e, ElemType &pre) {
    p = L->next;
    if (!p || p->data == e) return false;
    while (p->next && p->next->data != e) {
        p = p->next;
    }
    if (!p->next) return false;
    pre = p->data;
    return true;
}

// 求输入元素的后继
bool getNextElem(LinkList L, ElemType e, ElemType &next) {
    p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    if (!p || !p->next) return false;
    next = p->next->data;
    return true;
}

//在第i个位置插入元素
bool listInsert(LinkList &L, int i, ElemType e) {
    if (i < 1) return false;
    p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) return false;
    s = (Lnode *)malloc(sizeof(Lnode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除第i个元素
bool listDelete(LinkList &L, int i, ElemType &e) {
    if (i < 1 || i > listLength(L)) return false;
    p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1) return false;
    Lnode *q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}

// 输出链表所有元素
void printList(LinkList L) {
    p = L->next;
    if (!p) return;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 用头插法初始化链表
void headInsert(LinkList &L, int n) {
    for (int i = 0; i < n; i++) {
        s = (Lnode *)malloc(sizeof(Lnode));
        cin >> s->data;
        s->next = L->next;
        L->next = s;
    }
}

// 链表逆序
void reverseList(LinkList &L) {
    if (L == nullptr || L->next == nullptr) return;
    LinkList reversedHead = (LinkList)malloc(sizeof(Lnode));
    reversedHead->next = nullptr;
    LinkList current = L->next;
    while (current != nullptr) {
        LinkList newNode = (Lnode *)malloc(sizeof(Lnode));
        newNode->data = current->data;
        newNode->next = reversedHead->next;
        reversedHead->next = newNode;
        current = current->next;
    }
    LinkList temp = L;
    L = reversedHead;
    free(temp);
}

// 链表排序
void sortList(LinkList &L) {
    if (!L->next || !L->next->next) return;
    bool swapped;
    Lnode *p1, *p2 = nullptr;
    do {
        swapped = false;
        p1 = L->next;
        while (p1->next != p2) {
            if (p1->data > p1->next->data) {
                swap(p1->data, p1->next->data);
                swapped = true;
            }
            p1 = p1->next;
        }
        p2 = p1;
    } while (swapped);
}

// 菜单
void menu() {
    cout << "1. 初始化或重置链表\n";
    cout << "2. 销毁链表\n";
    cout << "3. 清空链表\n";
    cout << "4. 链表长度\n";
    cout << "5. 指定位置的元素值\n";
    cout << "6. 查找链表中某元素的位序\n";
    cout << "7. 查找某元素的前驱\n";
    cout << "8. 查找某元素的后继\n";
    cout << "9. 在第i个位置插入元素\n";
    cout << "10. 删除第i个元素\n";
    cout << "11. 输出链表所有元素\n";
    cout << "12. 头插法初始化链表\n";
    cout << "13. 链表逆序存放\n";
    cout << "14. 链表排序\n";
    cout << "输入一个负数结束程序\n";
}

// 主函数
int HW3() {
    int choice, pos, len;
    ElemType elem, e;

    do {
        menu();
        cout << "请选择操作：";
        cin >> choice;

        if (choice < 0) {
            break;
        }

        if(choice == 12){
            if(L == nullptr){
                cout << "请输入元素个数：";
                cin >> len;
                headInsert(L, len);
                cout << "链表头插法初始化成功！\n";
            }
            else{
                cout << "链表已完成初始化，不可再使用头插法初始化！\n";
            }
        }

        if (choice > 1 && choice <= 14 && L == nullptr) {
            cout << "链表未初始化，请先初始化链表！\n";
            continue;
        }

        switch (choice) {
            case 1:
                initList(L);
                cout << "链表初始化成功！\n";
                break;
            case 2:
                destroyList(L);
                cout << "链表销毁成功！\n";
                break;
            case 3:
                clearList(L);
                cout << "链表清空成功！\n";
                break;
            case 4:
                len = listLength(L);
                cout << "链表长度为：" << len << endl;
                break;
            case 5:
                cout << "请输入位置：";
                cin >> pos;
                if (getElem(L, pos, e))
                    cout << "第 " << pos << " 个元素为：" << e << endl;
                else
                    cout << "位置无效！\n";
                break;
            case 6:
                cout << "请输入要查找的元素：";
                cin >> elem;
                pos = locateElem(L, elem);
                if (pos)
                    cout << elem << " 的位序为：" << pos << endl;
                else
                    cout << "未找到该元素！\n";
                break;
            case 7:
                cout << "请输入要查找前驱的元素：";
                cin >> elem;
                if (getPriorElem(L, elem, e))
                    cout << elem << " 的前驱为：" << e << endl;
                else
                    cout << "该元素没有前驱或不存在！\n";
                break;
            case 8:
                cout << "请输入要查找后继的元素：";
                cin >> elem;
                if (getNextElem(L, elem, e))
                    cout << elem << " 的后继为：" << e << endl;
                else
                    cout << "该元素没有后继或不存在！\n";
                break;
            case 9:
                cout << "请输入位置和元素：";
                cin >> pos >> elem;
                if (listInsert(L, pos, elem))
                    cout << "元素插入成功！\n";
                else
                    cout << "插入失败，位置或元素可能不合法！\n";
                break;
            case 10:
                cout << "请输入要删除的元素位置：";
                cin >> pos;
                if (listDelete(L, pos, e))
                    cout << "删除元素 " << e << " 成功！\n";
                else
                    cout << "删除失败！\n";
                break;
            case 11:
                cout << "链表中的元素为：";
                printList(L);
                break;
            //case 12:
            case 13:
                reverseList(L);
                cout << "链表逆序存放成功！\n";
                break;
            case 14:
                sortList(L);
                cout << "链表排序成功！\n";
                break;
            default:
                cout << "无效操作，请重新输入！\n";
                break;
        }
    } while (choice != 0);

    destroyList(L);
    return 0;
}
