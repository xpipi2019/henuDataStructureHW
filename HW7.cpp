//
// Created by XPIPI on 24-11-8.
// �洢�ṹ�ο���https://blog.csdn.net/qq_24654501/article/details/109963669
//
#include <iostream>
#include <cstdlib>

#include "myBiTree.h"
#include "myQueue.h"
#include "myStack.h"

using namespace std;

#define endl '\n'

// �Զ���ջ

void InitStack(SqStack2& S) {
    S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(-1);
    S.top = S.base;
    S.stack_size = STACK_INIT_SIZE;
}

void Push(SqStack2& S, SElemType e) {
    if (S.top - S.base >= S.stack_size) {
        // ջ���Ƕ�̬����
        S.base = (SElemType*)realloc(S.base, (S.stack_size + STACK_INCREMENT) * sizeof(SElemType));
        if (!S.base) exit(-1);
        S.top = S.base + S.stack_size;
        S.stack_size += STACK_INCREMENT;
    }
    *(S.top++) = e;
}

bool StackEmpty(SqStack2 S) {
    return S.top == S.base;
}

SElemType Pop(SqStack2& S) {
    if (S.base == NULL) return NULL;
    return *(--S.top);
}

// �Զ������

void InitQueue(LinkQueue& Q) {
    Q.front = (QueuePtr2)malloc(sizeof(QNode2));
    Q.rear = Q.front;
    if (!Q.front) exit(-1);
    Q.front->next = nullptr;
}

void EnQueue(LinkQueue& Q, QElemType2 e) {
    QueuePtr2 p = (QueuePtr2)malloc(sizeof(QNode2));
    if (!p) exit(-1);
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
}

QElemType2 DeQueue(LinkQueue& Q) {
    if (Q.front == Q.rear) return NULL;
    QueuePtr2 p = Q.front->next;
    QElemType2 e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return e;
}

bool QueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

// ��������������
int CreateBiTree(BiTree& T) {
    char ch;
    cin >> ch;
    if (ch == '$') {
        T = NULL;
    }
    else {
        T = (BiTNode*)malloc(sizeof(BiTNode));
        if (!T) exit(-1);
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return 1;
}

void PreOrderTraverse(BiTree T) {
    if (T) {
        cout << T->data << " ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverseNonRecursive1(BiTree T) {
    SqStack2 S;
    InitStack(S);
    BiTree p = T;
    while (p || !StackEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            p = Pop(S);
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

void InOrderTraverseNonRecursive2(BiTree T) {
    SqStack2 S;
    InitStack(S);
    BiTree p = T;
    while (p || !StackEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            p = Pop(S);
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

void PostOrderTraverse(BiTree T) {
    if (T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data << " ";
    }
}

void LevelOrderTraverse(BiTree T) {
    if (!T) return;
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, T);
    while (!QueueEmpty(Q)) {
        BiTree p = DeQueue(Q);
        cout << p->data << " ";
        if (p->lchild) EnQueue(Q, p->lchild);
        if (p->rchild) EnQueue(Q, p->rchild);
    }
}

int TreeDepth(BiTree T) {
    if (!T) return 0;
    int lDepth = TreeDepth(T->lchild);
    int rDepth = TreeDepth(T->rchild);
    return (lDepth > rDepth ? lDepth : rDepth) + 1;
}

int CountNonLeafNodes(BiTree T) {
    if (!T || (!T->lchild && !T->rchild)) return 0;
    return CountNonLeafNodes(T->lchild) + CountNonLeafNodes(T->rchild) + 1;
}

int HW7() {
    BiTree T = NULL;
    int choice;
    do {
        cout << "\n1. ����������" << endl;
        cout << "2. ����������������ݹ飩" << endl;
        cout << "3. ����������������ǵݹ�1��" << endl;
        cout << "4. ����������������ǵݹ�2��" << endl;
        cout << "5. ����������������ݹ飩" << endl;
        cout << "6. �������������" << endl;
        cout << "7. ������������" << endl;
        cout << "8. ��������з�Ҷ�ӽ��ĸ���" << endl;
        cout << "9. �˳�" << endl;
        cout << "������ѡ��: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "������������Ľڵ㣨����$��ʾ��: ";
                CreateBiTree(T);
                break;
            case 2:
                cout << "����������: ";
                PreOrderTraverse(T);
                break;
            case 3:
                cout << "�������������ǵݹ�1��: ";
                InOrderTraverseNonRecursive1(T);
                break;
            case 4:
                cout << "�������������ǵݹ�2��: ";
                InOrderTraverseNonRecursive2(T);
                break;
            case 5:
                cout << "����������: ";
                PostOrderTraverse(T);
                break;
            case 6:
                cout << "����������: ";
                LevelOrderTraverse(T);
                break;
            case 7:
                cout << "���������Ϊ: " << TreeDepth(T) << endl;
                break;
            case 8:
                cout << "��Ҷ�ӽڵ����Ϊ: " << CountNonLeafNodes(T) << endl;
                break;
            case 9:
                cout << "���������" << endl;
                break;
            default:
                cout << "��Чѡ�������ԣ�" << endl;
        }
    } while (choice != 9);

    return 0;
}
