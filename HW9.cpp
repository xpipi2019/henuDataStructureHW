//
// Created by XPIPI on 24-11-16.
// 存储结构参考：https://blog.csdn.net/qq_24654501/article/details/110747858
//
#include <iostream>
#include <cstring>
using namespace std;

#include "myQueue_int.h"

#define MAX_VERTEX_NUM 20

typedef int VRType;       // 权值类型
typedef int VertexType;   // 顶点类型
typedef struct ArcCell {
    VRType adj; // 权值
} AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; // 顶点数组
    AdjMatrix arcs;                  // 邻接矩阵
    int vexnum;                      // 总顶点数
    int arcnum;                      // 总边数
} MyGraph;

bool visited[MAX_VERTEX_NUM];

// 函数声明
int LocateVex(MyGraph g, int v);
int CreateUDN(MyGraph& g);
void printAdjMatrix(MyGraph g);
void DFSTraverse(MyGraph g);
void DFS(MyGraph g, VertexType v);
// 顶点类型 VertesType
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
    cout << "请输入顶点数和边数:" << endl;
    cin >> g.vexnum >> g.arcnum;

    cout << "请输入顶点信息:" << endl;
    for (int i = 0; i < g.vexnum; i++) {
        cin >> g.vexs[i];
    }

    memset(g.arcs, 0, sizeof(g.arcs));

    cout << "请输入边信息(格式: 顶点1 顶点2):" << endl;
    for (int k = 0; k < g.arcnum; k++) {
        int v1, v2;
        cin >> v1 >> v2;
        int i = LocateVex(g, v1);
        int j = LocateVex(g, v2);
        if (i != -1 && j != -1) {
            g.arcs[i][j].adj = 1;
            // 无向图对称
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
    return -1; // 无下一个邻接点
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
        cout << "菜单："<< endl;
        cout << "1. 构建无向图"<< endl;
        cout << "2. 输出邻接矩阵"<< endl;
        cout << "3. 深度优先遍历"<< endl;
        cout << "4. 广度优先遍历"<< endl;
        cout << "5. 退出"<< endl;
        cin >> choice;
        switch (choice) {
            case 1:
                CreateUDN(g);
                break;
            case 2:
                cout << "邻接矩阵:" << endl;
                printAdjMatrix(g);
                break;
            case 3:
                cout << "深度优先遍历结果:" << endl;
                DFSTraverse(g);
                break;
            case 4:
                cout << "广度优先遍历结果:" << endl;
                BFS(g);
                break;
            default:
                cout << "无效选择，请重新选择！"<< endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
