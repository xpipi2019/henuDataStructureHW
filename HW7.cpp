//
// Created by XPIPI on 24-11-8.
// 存储结构参考：https://blog.csdn.net/qq_24654501/article/details/109963669
//
#include <iostream>
#include <cstdlib>

#include "myBiTree.h"
#include "myQueue.h"
#include "myStack.h"

using namespace std;

#define endl '\n'

// 自定义栈

void InitStack(SqStack2& S) {
    S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(-1);
    S.top = S.base;
    S.stack_size = STACK_INIT_SIZE;
}

void Push(SqStack2& S, SElemType e) {
    if (S.top - S.base >= S.stack_size) {
        // 栈还是动态更好
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

// 自定义队列

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

// 二叉树操作函数
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
        cout << "\n1. 创建二叉树" << endl;
        cout << "2. 先序遍历二叉树（递归）" << endl;
        cout << "3. 中序遍历二叉树（非递归1）" << endl;
        cout << "4. 中序遍历二叉树（非递归2）" << endl;
        cout << "5. 后序遍历二叉树（递归）" << endl;
        cout << "6. 层序遍历二叉树" << endl;
        cout << "7. 求二叉树的深度" << endl;
        cout << "8. 求二叉树中非叶子结点的个数" << endl;
        cout << "9. 退出" << endl;
        cout << "请输入选择: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "请输入二叉树的节点（空用$表示）: ";
                CreateBiTree(T);
                break;
            case 2:
                cout << "先序遍历结果: ";
                PreOrderTraverse(T);
                break;
            case 3:
                cout << "中序遍历结果（非递归1）: ";
                InOrderTraverseNonRecursive1(T);
                break;
            case 4:
                cout << "中序遍历结果（非递归2）: ";
                InOrderTraverseNonRecursive2(T);
                break;
            case 5:
                cout << "后序遍历结果: ";
                PostOrderTraverse(T);
                break;
            case 6:
                cout << "层序遍历结果: ";
                LevelOrderTraverse(T);
                break;
            case 7:
                cout << "二叉树深度为: " << TreeDepth(T) << endl;
                break;
            case 8:
                cout << "非叶子节点个数为: " << CountNonLeafNodes(T) << endl;
                break;
            case 9:
                cout << "程序结束！" << endl;
                break;
            default:
                cout << "无效选择，请重试！" << endl;
        }
    } while (choice != 9);

    return 0;
}
