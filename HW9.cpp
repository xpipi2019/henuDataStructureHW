//
// Created by XPIPI on 24-11-16.
// �洢�ṹ�ο���https://blog.csdn.net/qq_24654501/article/details/110747858
//
#include <iostream>
#include <cstring>
using namespace std;

#include "myQueue_int.h"

#define MAX_VERTEX_NUM 20

typedef int VRType;       // Ȩֵ����
typedef int VertexType;   // ��������
typedef struct ArcCell {
    VRType adj; // Ȩֵ
} AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; // ��������
    AdjMatrix arcs;                  // �ڽӾ���
    int vexnum;                      // �ܶ�����
    int arcnum;                      // �ܱ���
} MyGraph;

bool visited[MAX_VERTEX_NUM];

// ��������
int LocateVex(MyGraph g, int v);
int CreateUDN(MyGraph& g);
void printAdjMatrix(MyGraph g);
void DFSTraverse(MyGraph g);
void DFS(MyGraph g, VertexType v);
// �������� VertesType
VertexType NextAdjVex(MyGraph g, VertexType v);
void BFS(MyGraph g);
void printVex(VertexType v);

int LocateVex(MyGraph g, int v) {
    for (int i = 0; i < g.vexnum; i++) {
        if (g.vexs[i] == v) return i;
    }
    return -1;
}

int CreateUDN(MyGraph& g) {
    cout << "�����붥�����ͱ���:" << endl;
    cin >> g.vexnum >> g.arcnum;

    cout << "�����붥����Ϣ:" << endl;
    for (int i = 0; i < g.vexnum; i++) {
        cin >> g.vexs[i];
    }

    memset(g.arcs, 0, sizeof(g.arcs));

    cout << "���������Ϣ(��ʽ: ����1 ����2):" << endl;
    for (int k = 0; k < g.arcnum; k++) {
        int v1, v2;
        cin >> v1 >> v2;
        int i = LocateVex(g, v1);
        int j = LocateVex(g, v2);
        if (i != -1 && j != -1) {
            g.arcs[i][j].adj = 1;
            // ����ͼ�Գ�
            g.arcs[j][i].adj = 1;
        }
    }
    return 1;
}

void printAdjMatrix(MyGraph g) {
    for (int i = 0; i < g.vexnum; i++) {
        for (int j = 0; j < g.vexnum; j++) {
            cout << g.arcs[i][j].adj << " ";
        }
        cout << endl;
    }
}

void DFSTraverse(MyGraph g) {
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < g.vexnum; i++) {
        if (!visited[i]) DFS(g, i);
    }
    cout << endl;
}

void DFS(MyGraph g, VertexType v) {
    visited[v] = true;
    printVex(g.vexs[v]);
    for (int w = 0; w < g.vexnum; w++) {
        if (g.arcs[v][w].adj && !visited[w]) DFS(g, w);
    }
}

VertexType NextAdjVex(MyGraph g, VertexType v) {
    for (int w = 0; w < g.vexnum; w++) {
        if (g.arcs[v][w].adj && !visited[w]) return w;
    }
    return -1; // ����һ���ڽӵ�
}

void BFS(MyGraph g) {
    memset(visited, false, sizeof(visited));
    LinkQueue Q;
    InitLinkQueue(Q);
    for (int i = 0; i < g.vexnum; i++) {
        if (!visited[i]) {
            visited[i] = true;
            printVex(g.vexs[i]);
            EnLinkQueue(Q, i);
            while (!IsLinkQueueEmpty(Q)) {
                int u;
                DeLinkQueue(Q,u);
                for (int w = 0; w < g.vexnum; w++) {
                    if (g.arcs[u][w].adj && !visited[w]) {
                        visited[w] = true;
                        printVex(g.vexs[w]);
                        EnLinkQueue(Q, w);
                    }
                }
            }
        }
    }
    cout << endl;
}

void printVex(VertexType v) {
    cout << v << " ";
}

int HW9() {
    MyGraph g;
    int choice;
    do {
        cout << "�˵���"<< endl;
        cout << "1. ��������ͼ"<< endl;
        cout << "2. ����ڽӾ���"<< endl;
        cout << "3. ������ȱ���"<< endl;
        cout << "4. ������ȱ���"<< endl;
        cout << "5. �˳�"<< endl;
        cin >> choice;
        switch (choice) {
            case 1:
                CreateUDN(g);
                break;
            case 2:
                cout << "�ڽӾ���:" << endl;
                printAdjMatrix(g);
                break;
            case 3:
                cout << "������ȱ������:" << endl;
                DFSTraverse(g);
                break;
            case 4:
                cout << "������ȱ������:" << endl;
                BFS(g);
                break;
            default:
                cout << "��Чѡ��������ѡ��"<< endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
