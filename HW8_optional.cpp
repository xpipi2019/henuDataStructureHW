//
// Created by XPIPI on 24-11-16. End 2024/11/29
// 存储结构参考：https://blog.csdn.net/m0_54439023/article/details/124837694
//

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAX_CHAR = 27; // 26个字母 + 空格
const int MAX_NODES = 2 * MAX_CHAR - 1;
typedef char** HCode;

// 默认情况
int letter[MAX_CHAR] = {64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1, 168};
char lee[MAX_CHAR] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',' '};

struct HTNode {
    // 权值
    int w;

    int parent;
    int lchild,rchild;
};

HTNode T[MAX_NODES];
HCode HC;

void selectTwoMin(int n, int& s1, int& s2) {
    s1 = s2 = -1;
    for (int i = 0; i < n; ++i) {
        if (T[i].parent == -1) {
            if (s1 == -1 || T[i].w < T[s1].w) {
                s2 = s1;
                s1 = i;
            } else if (s2 == -1 || T[i].w < T[s2].w) {
                s2 = i;
            }
        }
    }
}

// 创建哈夫曼树
void createHuffmanTree() {
    int m = MAX_NODES;
    for (int i = 0; i < m; ++i) {
        T[i].w = T[i].parent = T[i].lchild = T[i].rchild = -1;
    }

    for (int i = 0; i < MAX_CHAR; ++i) {
        T[i].w = letter[i];
    }

    for (int i = MAX_CHAR; i < m; ++i) {
        int s1, s2;
        selectTwoMin(i, s1, s2); // HuffmanTree选择最小权值
        T[i].w = T[s1].w + T[s2].w;
        T[i].lchild = s1;
        T[i].rchild = s2;
        T[s1].parent = T[s2].parent = i;
    }
}

void createHuffmanCode() {
    HC = (char**)malloc(MAX_CHAR * sizeof(char*));
    char* code = (char*)malloc(MAX_CHAR * sizeof(char));
    code[MAX_CHAR - 1] = '\0';

    for (int i = 0; i < MAX_CHAR; ++i) {
        int start = MAX_CHAR - 1;
        int c = i;
        int f = T[i].parent;
        while (f != -1) {
            --start;
            if (T[f].lchild == c) {
                code[start] = '0';
            } else {
                code[start] = '1';
            }
            c = f;
            f = T[f].parent;
        }
        HC[i] = (char*)malloc((MAX_CHAR - start) * sizeof(char));
        strcpy(HC[i], &code[start]);
    }
    free(code);
}

void displayHuffmanCode() {
    cout << "哈夫曼编码表:" << endl;
    for (int i = 0; i < MAX_CHAR; ++i) {
        cout << lee[i] << ": " << HC[i] << endl;
    }
}

void encodeMessage() {
    cout << "请输入要编码的字符串（以%结束）: ";
    char ch;
    while ((ch = getchar()) != '%') {
        for (int i = 0; i < MAX_CHAR; ++i) {
            if (ch == lee[i]) {
                cout << HC[i];
                break;
            }
        }
    }
    cout << endl;
}

void decodeMessage() {
    cout << "请输入要解码的二进制字符串: ";
    char input[1024];
    cin >> input;
    int len = strlen(input);
    int root = MAX_NODES - 1;
    for (int i = 0; i < len; ++i) {
        if (input[i] == '0') {
            root = T[root].lchild;
        } else {
            root = T[root].rchild;
        }
        if (T[root].lchild == -1 && T[root].rchild == -1) {
            cout << lee[root];
            root = MAX_NODES - 1;
        }
    }
    cout << endl;
}

int HW8() {
    int choice;
    do {
        cout << "1 ---- 输入HuffmanTree的参数" << endl;
        cout << "2 ---- 初始化HuffmanTree参数（含有26字母及空格）" << endl;
        cout << "3 ---- 创建HuffmanTree和解码表" << endl;
        cout << "4 ---- 输出解码表" << endl;
        cout << "5 ---- 输入编码，并翻译为字符" << endl;
        cout << "6 ---- 输入字符，并实现转码" << endl;
        cout << "7 ---- 退出" << endl;
        cout << "请输入选择: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "请输入27个字符的出现频率: ";
                for (int i = 0; i < MAX_CHAR; ++i) {
                    cin >> letter[i];
                }
                break;
            case 2:
                cout << "请输入27个字符: ";
                for (int i = 0; i < MAX_CHAR; ++i) {
                    cin >> lee[i];
                }
                break;
            case 3:
                createHuffmanTree();
                createHuffmanCode();
                cout << "哈夫曼树和编码表创建成功！" << endl;
                break;
            case 4:
                displayHuffmanCode();
                break;
            case 5:
                decodeMessage();
                break;
            case 6:
                encodeMessage();
                break;
            case 7:
                cout << "程序退出。" << endl;
                break;
            default:
                cout << "无效选择！" << endl;
        }
    } while (choice != 7);

    return 0;
}
