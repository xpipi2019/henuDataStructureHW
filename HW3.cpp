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

struct Lnode {
    ElemType data;
    Lnode* next = nullptr;
};

using LinkList = Lnode*;

// ��ʼ������Ϊ��
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

// ��������
int getLength(const LinkList L) {
    int length = 0;
    Lnode* p = L->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// ��ȡָ��λ��Ԫ��
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

// ����Ԫ�ص�λ��
int locateElem(const LinkList L, ElemType e) {
    Lnode* p = L->next;
    int pos = 1;
    while (p && p->data != e) {
        p = p->next;
        pos++;
    }
    return p ? pos : 0;
}

// ��ǰ��
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

// ����
bool getSuccessor(const LinkList L, ElemType e, ElemType& next) {
    Lnode* p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    if (!p || !p->next) return false;
    next = p->next->data;
    return true;
}

// �ڵ�i��λ�ò���Ԫ��
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

// ɾ����i��Ԫ��
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

// ��ͷ�巨��ʼ������
void headInsert(LinkList& L, int n) {
    for (int i = 0; i < n; i++) {
        Lnode* s = (Lnode*)malloc(sizeof(Lnode));
        cin >> s->data;
        s->next = L->next;
        L->next = s;
    }
}

// ��������
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

// ��������
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
        cout << "1. ��ʼ������������" << endl;
        cout << "2. ��������" << endl;
        cout << "3. �������" << endl;
        cout << "4. ������" << endl;
        cout << "5. ָ��λ�õ�Ԫ��ֵ" << endl;
        cout << "6. �����Ѵ���Ԫ�ص�λ��" << endl;
        cout << "7. ������Ԫ�ص�ֱ��ǰ��" << endl;
        cout << "8. ������Ԫ�ص�ֱ�Ӻ��" << endl;
        cout << "9. �ڵ�i��λ�ò���һ��Ԫ��" << endl;
        cout << "10. ɾ����i��Ԫ��" << endl;
        cout << "11. ����е�����Ԫ��" << endl;
        cout << "12. ��ʼ������ͷ�巨����Ԫ��" << endl;
        cout << "13. ��������" << endl;
        cout << "14. ��������" << endl;
        cout << "0. �˳�" << endl;
        cout << "��ѡ�������";
        cin >> choice;

        if (choice == 0) break;

        if(choice == 12){
            if(L == nullptr){
                cout << "������Ԫ�ظ�����";
                cin >> len;
                initList(L);
                cout << "������ " << len << " ���ÿո������Ԫ�أ�" << endl;
                headInsert(L, len);
                cout << "����ͷ�巨��ʼ���ɹ���" << endl;
            }
            else{
                cout << "��������ɳ�ʼ����������ʹ��ͷ�巨��ʼ����" << endl;
            }
        }

        if (choice > 1 && choice <= 14 && !L) {
            cout << "����δ��ʼ�������ȳ�ʼ������" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                initList(L);
                cout << "�����ʼ���ɹ���" << endl;
                break;
            case 2:
                destroyList(L);
                cout << "�������ٳɹ���" << endl;
                break;
            case 3:
                clearList(L);
                cout << "������ճɹ���" << endl;
                break;
            case 4:
                cout << "������Ϊ��" << getLength(L) << endl;
                break;
            case 5:
                cout << "������λ�ã�";
                cin >> pos;
                if (getElem(L, pos, e))
                    cout << "�� " << pos << " ��Ԫ��Ϊ��" << e << endl;
                else
                    cout << "λ����Ч��" << endl;
                break;
            case 6:
                cout << "������Ҫ���ҵ�Ԫ�أ�";
                cin >> elem;
                pos = locateElem(L, elem);
                if (pos)
                    cout << elem << " ��λ��Ϊ��" << pos << endl;
                else
                    cout << "δ�ҵ���Ԫ�أ�" << endl;
                break;
            case 7:
                cout << "������Ԫ�أ�";
                cin >> elem;
                if (getPredecessor(L, elem, e))
                    cout << elem << " ��ǰ��Ϊ��" << e << endl;
                else
                    cout << "��Ԫ����ǰ����" << endl;
                break;
            case 8:
                cout << "������Ԫ�أ�";
                cin >> elem;
                if (getSuccessor(L, elem, e))
                    cout << elem << " �ĺ��Ϊ��" << e << endl;
                else
                    cout << "��Ԫ���޺�̣�" << endl;
                break;
            case 9:
                cout << "������λ�ú�Ԫ�أ�";
                cin >> pos >> elem;
                if (insertElem(L, pos, elem))
                    cout << "Ԫ�ز���ɹ���" << endl;
                else
                    cout << "����ʧ�ܣ�" << endl;
                break;
            case 10:
                cout << "������ɾ��λ�ã�";
                cin >> pos;
                if (deleteElem(L, pos, e))
                    cout << "ɾ��Ԫ�� " << e << " �ɹ���" << endl;
                else
                    cout << "ɾ��ʧ�ܣ�" << endl;
                break;
            case 11:
                cout << "�����е�Ԫ��Ϊ��";
                printList(L);
                break;
            //case 12:
            case 13:
                reverseList(L);
                cout << "��������ɹ���" << endl;
                break;
            case 14:
                sortList(L);
                cout << "��������ɹ���" << endl;
                break;
            default:
                cout << "��Ч������" << endl;
                break;
        }
    } while (choice >= 0);

    destroyList(L);
    return 0;
}
