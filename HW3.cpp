//
// Created by XPIPI on 24-10-7.
// �ο�1�����ݽṹ��C���԰棩�����廪��ѧ������
// �ο�2��https://blog.csdn.net/daocaoren_/article/details/96433693
// �ο�3��https://blog.csdn.net/qq_54210270/article/details/122868516
// �ο�4��https://blog.csdn.net/Gentle722/article/details/106173472
//
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef int ElemType;

// ������洢�ṹ
typedef struct Lnode {
    ElemType data;
    struct Lnode* next;
} Lnode, *LinkList;

LinkList L;
Lnode *p, *s;

// ��ʼ������Ϊ������
void initList(LinkList &L) {
    L = (LinkList)malloc(sizeof(Lnode));
    L->next = nullptr;
}

// ��������
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

// �������
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

// ��������
int listLength(LinkList L) {
    int length = 0;
    p = L->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// ��ȡָ��λ��Ԫ��
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

// ����Ԫ�ص�λ��
int locateElem(LinkList L, ElemType e) {
    p = L->next;
    int j = 1;
    while (p && p->data != e) {
        p = p->next;
        j++;
    }
    return (p) ? j : 0;
}

// ������Ԫ�ص�ǰ��
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

// ������Ԫ�صĺ��
bool getNextElem(LinkList L, ElemType e, ElemType &next) {
    p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    if (!p || !p->next) return false;
    next = p->next->data;
    return true;
}

//�ڵ�i��λ�ò���Ԫ��
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

// ɾ����i��Ԫ��
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

// �����������Ԫ��
void printList(LinkList L) {
    p = L->next;
    if (!p) return;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// ��ͷ�巨��ʼ������
void headInsert(LinkList &L, int n) {
    for (int i = 0; i < n; i++) {
        s = (Lnode *)malloc(sizeof(Lnode));
        cin >> s->data;
        s->next = L->next;
        L->next = s;
    }
}

// ��������
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

// ��������
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

// �˵�
void menu() {
    cout << "1. ��ʼ������������\n";
    cout << "2. ��������\n";
    cout << "3. �������\n";
    cout << "4. ������\n";
    cout << "5. ָ��λ�õ�Ԫ��ֵ\n";
    cout << "6. ����������ĳԪ�ص�λ��\n";
    cout << "7. ����ĳԪ�ص�ǰ��\n";
    cout << "8. ����ĳԪ�صĺ��\n";
    cout << "9. �ڵ�i��λ�ò���Ԫ��\n";
    cout << "10. ɾ����i��Ԫ��\n";
    cout << "11. �����������Ԫ��\n";
    cout << "12. ͷ�巨��ʼ������\n";
    cout << "13. ����������\n";
    cout << "14. ��������\n";
    cout << "����һ��������������\n";
}

// ������
int HW3() {
    int choice, pos, len;
    ElemType elem, e;

    do {
        menu();
        cout << "��ѡ�������";
        cin >> choice;

        if (choice < 0) {
            break;
        }

        if(choice == 12){
            if(L == nullptr){
                cout << "������Ԫ�ظ�����";
                cin >> len;
                headInsert(L, len);
                cout << "����ͷ�巨��ʼ���ɹ���\n";
            }
            else{
                cout << "��������ɳ�ʼ����������ʹ��ͷ�巨��ʼ����\n";
            }
        }

        if (choice > 1 && choice <= 14 && L == nullptr) {
            cout << "����δ��ʼ�������ȳ�ʼ������\n";
            continue;
        }

        switch (choice) {
            case 1:
                initList(L);
                cout << "�����ʼ���ɹ���\n";
                break;
            case 2:
                destroyList(L);
                cout << "�������ٳɹ���\n";
                break;
            case 3:
                clearList(L);
                cout << "������ճɹ���\n";
                break;
            case 4:
                len = listLength(L);
                cout << "������Ϊ��" << len << endl;
                break;
            case 5:
                cout << "������λ�ã�";
                cin >> pos;
                if (getElem(L, pos, e))
                    cout << "�� " << pos << " ��Ԫ��Ϊ��" << e << endl;
                else
                    cout << "λ����Ч��\n";
                break;
            case 6:
                cout << "������Ҫ���ҵ�Ԫ�أ�";
                cin >> elem;
                pos = locateElem(L, elem);
                if (pos)
                    cout << elem << " ��λ��Ϊ��" << pos << endl;
                else
                    cout << "δ�ҵ���Ԫ�أ�\n";
                break;
            case 7:
                cout << "������Ҫ����ǰ����Ԫ�أ�";
                cin >> elem;
                if (getPriorElem(L, elem, e))
                    cout << elem << " ��ǰ��Ϊ��" << e << endl;
                else
                    cout << "��Ԫ��û��ǰ���򲻴��ڣ�\n";
                break;
            case 8:
                cout << "������Ҫ���Һ�̵�Ԫ�أ�";
                cin >> elem;
                if (getNextElem(L, elem, e))
                    cout << elem << " �ĺ��Ϊ��" << e << endl;
                else
                    cout << "��Ԫ��û�к�̻򲻴��ڣ�\n";
                break;
            case 9:
                cout << "������λ�ú�Ԫ�أ�";
                cin >> pos >> elem;
                if (listInsert(L, pos, elem))
                    cout << "Ԫ�ز���ɹ���\n";
                else
                    cout << "����ʧ�ܣ�λ�û�Ԫ�ؿ��ܲ��Ϸ���\n";
                break;
            case 10:
                cout << "������Ҫɾ����Ԫ��λ�ã�";
                cin >> pos;
                if (listDelete(L, pos, e))
                    cout << "ɾ��Ԫ�� " << e << " �ɹ���\n";
                else
                    cout << "ɾ��ʧ�ܣ�\n";
                break;
            case 11:
                cout << "�����е�Ԫ��Ϊ��";
                printList(L);
                break;
            //case 12:
            case 13:
                reverseList(L);
                cout << "���������ųɹ���\n";
                break;
            case 14:
                sortList(L);
                cout << "��������ɹ���\n";
                break;
            default:
                cout << "��Ч���������������룡\n";
                break;
        }
    } while (choice != 0);

    destroyList(L);
    return 0;
}
