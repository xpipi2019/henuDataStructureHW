//
// Created by XPIPI on 24-10-27.
// �ο�:https://blog.csdn.net/qq_40953393/article/details/78935522
//
#include <iostream>
#include "myQueue.h"
using namespace std;

// ��ʼ��������һ���ն���Q
bool InitLQueue(LQueue &Q) {
    Q.front = Q.rear = new QNode;
    if (!Q.front) return false;
    Q.front->next = nullptr;
    return true;
}

// ���٣�����һ������Q
bool DestroyLQueue(LQueue &Q) {
    while (Q.front) {
        QueuePtr p = Q.front;
        Q.front = Q.front->next;
        delete p;
    }
    Q.front = Q.rear = nullptr;
    return true;
}

// ��գ����һ������Q
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

// �ж��Ƿ�Ϊ�ն���
bool IsLQueueEmpty(LQueue Q) {
    return Q.front == Q.rear;
}

// ���г��ȣ����ض���Ԫ��Q�ĸ���
int LQueueLength(LQueue Q) {
    int length = 0;
    QueuePtr p = Q.front->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// ��ȡ��ͷԪ��
bool GetFrontElem(LQueue Q, QElemType &e) {
    if (Q.front == Q.rear) return false;
    e = Q.front->next->data;
    return true;
}

// ��ӣ�����Ԫ��eΪ���еĶ�βԪ��
bool EnLQueue(LQueue &Q, QElemType e) {
    QueuePtr newNode = new QNode;
    if (!newNode) return false;
    newNode->data = e;
    newNode->next = nullptr;
    Q.rear->next = newNode;
    Q.rear = newNode;
    return true;
}

// ���ӣ�ɾ����ͷԪ��
bool DeLQueue(LQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) return false;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    delete p;
    return true;
}

// ��������
bool LQueueTraverse(LQueue Q, bool (*Visit)(QElemType)) {
    QueuePtr p = Q.front->next;
    while (p) {
        if (!Visit(p->data)) return false;
        p = p->next;
    }
    return true;
}

// ���Ԫ�صĺ���
bool PrintElem(QElemType e) {
    cout << e << " ";
    return true;
}

// �����Ŷ�
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
    cout << "�˵���" << endl;
    cout << "1. ��ʼ������" << endl;
    cout << "2. ���ٶ���" << endl;
    cout << "3. ��ն���" << endl;
    cout << "4. �����п�" << endl;
    cout << "5. ����г���" << endl;
    cout << "6. ��ȡ��ͷԪ��" << endl;
    cout << "7. ����һ��Ԫ��" << endl;
    cout << "8. ɾ��һ��Ԫ��" << endl;
    cout << "9. �������Ԫ��" << endl;
    cout << "10. �����Ŷ�" << endl;
    cout << "0. �˳�" << endl;
}

int HW5() {
    LQueue A, B, C;
    int choice, elem;
    bool initialized = false;

    while (true) {
        Menu();
        cout << "��ѡ�������";
        cin >> choice;

        switch (choice) {
            case 1:
                if (InitLQueue(A)) {
                    initialized = true;
                    cout << "���г�ʼ���ɹ���" << endl;
                } else {
                    cout << "���г�ʼ��ʧ�ܣ�" << endl;
                }
                break;
            case 2:
                if (initialized && DestroyLQueue(A)) {
                    initialized = false;
                    cout << "�������ٳɹ���" << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;
            case 3:
                if (initialized && ClearLQueue(A)) {
                    cout << "������ճɹ���" << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;
            case 4:
                if (initialized) {
                    if (IsLQueueEmpty(A))
                        cout << "����Ϊ�գ�" << endl;
                    else
                        cout << "���в�Ϊ�գ�" << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;
            case 5:
                if (initialized) {
                    cout << "���г���Ϊ��" << LQueueLength(A) << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;
            case 6:
                if (initialized && GetFrontElem(A, elem)) {
                    cout << "��ͷԪ��Ϊ��" << elem << endl;
                } else {
                    cout << "��ȡ��ͷԪ��ʧ�ܣ����п���δ��ʼ����Ϊ�գ�" << endl;
                }
                break;
            case 7:
                if (initialized) {
                    cout << "������Ҫ�����Ԫ�أ�";
                    cin >> elem;
                    if (EnLQueue(A, elem))
                        cout << "Ԫ�ز���ɹ���" << endl;
                    else
                        cout << "Ԫ�ز���ʧ�ܣ�" << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;
            case 8:
                if (initialized && DeLQueue(A, elem)) {
                    cout << "ɾ���Ķ�ͷԪ��Ϊ��" << elem << endl;
                } else {
                    cout << "ɾ����ͷԪ��ʧ�ܣ����п���δ��ʼ����Ϊ�գ�" << endl;
                }
                break;
            case 9:
                if (initialized) {
                    cout << "����Ԫ�أ�";
                    LQueueTraverse(A, PrintElem);
                    cout << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;
            case 10:
                if (initialized) {
                    InitLQueue(B);
                    InitLQueue(C);
                    RearrangeQueues(A, B, C);
                    cout << "����B��Ů����Ԫ�أ�";
                    LQueueTraverse(B, PrintElem);
                    cout << endl << "����C��������Ԫ�أ�";
                    LQueueTraverse(C, PrintElem);
                    cout << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;
            case 0:
                return 0;
            default:
                cout << "��Чѡ��������ѡ��" << endl;
                break;
        }
    }
}
