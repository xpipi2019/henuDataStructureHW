//
// Created by XPIPI on 24-11-5.
// 参考：https://www.codenong.com/cs109753819/
// 参考：数据结构（C语言版）——清华大学出版社
//
#include <iostream>
#include <iomanip>
using namespace std;

#define MAXSIZE 12500
typedef int ElemType;

struct Triple {
    int i, j;
    ElemType e;
};

// 稀疏矩阵的压缩存储结构
struct TSMatrix {
    Triple data[MAXSIZE + 1];
    int mu, nu;
    int tu;
};

// 创建稀疏矩阵
int createSMatrix(TSMatrix& M, int mu, int nu, int tu, Triple elements[], int count) {
    if (tu > mu * nu) return 0;
    M.mu = mu;
    M.nu = nu;
    M.tu = tu;

    for (int k = 1; k <= count; k++) {
        M.data[k] = elements[k - 1];
    }
    return 1;
}

int destroySMatrix(TSMatrix& M) {
    M.mu = M.nu = M.tu = 0;
    return 1;
}

// 打印稀疏矩阵
void printSMatrix(const TSMatrix& M) {
    int index = 1;
    for (int i = 1; i <= M.mu; i++) {
        for (int j = 1; j <= M.nu; j++) {
            if (index <= M.tu && M.data[index].i == i && M.data[index].j == j) {
                cout << setw(4) << M.data[index].e;
                index++;
            } else {
                cout << setw(4) << 0;
            }
        }
        cout << endl;
    }
}

int transposeSMatrix(const TSMatrix& M, TSMatrix& T) {
    int q = 1;
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;

    for (int col = 1; col <= M.nu; col++) {
        for (int p = 1; p <= M.tu; p++) {
            if (M.data[p].j == col) {
                T.data[q].i = M.data[p].j;
                T.data[q].j = M.data[p].i;
                T.data[q].e = M.data[p].e;
                q++;
            }
        }
    }
    return 1;
}

// 快速转置
int fastTransposeSMatrix(const TSMatrix& M, TSMatrix& T) {
    int num[MAXSIZE + 1] = {0};
    int cpot[MAXSIZE + 1] = {0};
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;

    if (T.tu > 0) {
        for (int t = 1; t <= M.tu; t++) {
            num[M.data[t].j]++;
        }

        cpot[1] = 1;
        for (int col = 2; col <= M.nu; col++) {
            cpot[col] = cpot[col - 1] + num[col - 1];
        }

        // M.tu列优先
        for (int p = 1; p <= M.tu; p++) {
            int col = M.data[p].j;
            int pos = cpot[col];
            T.data[pos].i = M.data[p].j;
            T.data[pos].j = M.data[p].i;
            T.data[pos].e = M.data[p].e;
            cpot[col]++;
        }
    }
    return 1;
}

int HW6() {
    TSMatrix M, T;
    int choice;

    while (true) {
        cout << "1. 创建矩阵" << endl;
        cout << "2. 销毁矩阵" << endl;
        cout << "3. 输出矩阵" << endl;
        cout << "4. 转置矩阵" << endl;
        cout << "5. 快速转置矩阵" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作：";
        cin >> choice;

        switch (choice) {
            case 1: {
                    int mu, nu, tu;
                    cout << "请输入矩阵的行数、列数和非零元个数：";
                    cin >> mu >> nu >> tu;

                    if (tu > mu * nu) {
                        cout << "输入错误，非零元素个数要小于等于行数乘列数，请重新输入。" << endl;
                        continue;
                    }

                    Triple elements[MAXSIZE];
                    int lastRow = 0, lastCol = 0;

                    for (int k = 0; k < tu; k++) {
                        int row, col, value;
                        cout << "请输入第 " << (k + 1) << " 个非零元素的位置和值：";
                        cin >> row >> col >> value;

                        // 检查是否重复下标
                        bool isDuplicate = false;
                        for (int m = 0; m < k; m++) {
                            if (elements[m].i == row && elements[m].j == col) {
                                isDuplicate = true;
                                break;
                            }
                        }
                        if (isDuplicate) {
                            cout << "输入错误，输入的下标重复，请重新输入！" << endl;
                            k--;
                            continue;
                        }

                        // 检查是否递增
                        if (k > 0 && (row < lastRow || (row == lastRow && col <= lastCol))) {
                            cout << "输入错误，下标输入时要递增输入，请重新输入！" << endl;
                            k--;
                            continue;
                        }

                        elements[k] = {row, col, value};
                        lastRow = row;
                        lastCol = col;
                    }

                    if (createSMatrix(M, mu, nu, tu, elements, tu)) {
                        cout << "矩阵创建成功。" << endl;
                    }
                break;
            }

            case 2:
                destroySMatrix(M);
                cout << "矩阵已销毁。" << endl;
                break;

            case 3:
                cout << "矩阵内容：" << endl;
                printSMatrix(M);
                break;

            case 4:
                transposeSMatrix(M, T);
                cout << "转置后的矩阵：" << endl;
                printSMatrix(T);
                break;

            case 5:
                fastTransposeSMatrix(M, T);
                cout << "快速转置后的矩阵：" << endl;
                printSMatrix(T);
                break;

            case 0:
                return 0;

            default:
                cout << "无效选择，请重新输入！" << endl;
        }
    }
}
