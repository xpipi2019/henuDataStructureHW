//
// Created by XPIPI on 24-10-27.
// �ο�:https://blog.csdn.net/qq_40953393/article/details/78935522
//
#include <iostream>
#include "myQueue_int.h"

using namespace std;

// ��������
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

// �����Ŷ�
void rearrangeQueues(LinkQueue& A, LinkQueue& B, LinkQueue& C) {
    QueuePtr p = A.front->next;
    while (p) {
        if (p->data % 2 == 0) { // ż�����B
            EnLinkQueue(B, p->data);
        } else { // �������C
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
        cout << "1. ��ʼ������" << endl;
        cout << "2. ���ٶ���" << endl;
        cout << "3. ��ն���" << endl;
        cout << "4. �ж϶����Ƿ�Ϊ��" << endl;
        cout << "5. ����г���" << endl;
        cout << "6. ��ȡ��ͷԪ��" << endl;
        cout << "7. ����һ��Ԫ��" << endl;
        cout << "8. ɾ��һ��Ԫ��" << endl;
        cout << "9. �������Ԫ��" << endl;
        cout << "10. �����Ŷ�" << endl;
        cout << "0. �˳�" << endl;
        cout << "��ѡ�������";
        cin >> choice;

        switch (choice) {
            case 1:
                InitLinkQueue(A);
                initialized = true;
                cout << "���г�ʼ���ɹ���" << endl;
                break;

            case 2:
                if (initialized && DestroyLinkQueue(A)) {
                    initialized = false;
                    cout << "�������ٳɹ���" << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;

            case 3:
                if (initialized) {
                    ClearLinkQueue(A);
                    cout << "������ճɹ���" << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;

            case 4:
                if (initialized) {
                    cout << (IsLinkQueueEmpty(A) ? "����Ϊ�գ�" : "���в�Ϊ�գ�") << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;

            case 5:
                if (initialized) {
                    cout << "���г���Ϊ��" << LinkQueueLength(A) << endl;
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
                    EnLinkQueue(A, elem);
                    cout << "Ԫ�ز���ɹ���" << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;

            case 8:
                if (initialized && DeLinkQueue(A, elem)) {
                    cout << "ɾ���Ķ�ͷԪ��Ϊ��" << elem << endl;
                } else {
                    cout << "ɾ����ͷԪ��ʧ�ܣ����п���δ��ʼ����Ϊ�գ�" << endl;
                }
                break;

            case 9:
                if (initialized) {
                    cout << "����Ԫ�أ�";
                    linkQueueTraverse(A, printElem);
                    cout << endl;
                } else {
                    cout << "���ȳ�ʼ�����У�" << endl;
                }
                break;

            case 10:
                if (initialized) {
                    // ��ʼ������BC
                    InitLinkQueue(B);
                    InitLinkQueue(C);
                    rearrangeQueues(A, B, C);
                    cout << "����B��ż����Ԫ�أ�";
                    linkQueueTraverse(B, printElem);
                    cout << endl << "����C��������Ԫ�أ�";
                    linkQueueTraverse(C, printElem);
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

