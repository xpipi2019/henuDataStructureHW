//
// Created by XPIPI on 24-11-5.
// �ο���https://www.codenong.com/cs109753819/
// �ο������ݽṹ��C���԰棩�����廪��ѧ������
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

// ϡ������ѹ���洢�ṹ
struct TSMatrix {
    Triple data[MAXSIZE + 1];
    int mu, nu;
    int tu;
};

// ����ϡ�����
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

// ��ӡϡ�����
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

// ����ת��
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

        // M.tu������
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
        cout << "1. ��������" << endl;
        cout << "2. ���پ���" << endl;
        cout << "3. �������" << endl;
        cout << "4. ת�þ���" << endl;
        cout << "5. ����ת�þ���" << endl;
        cout << "0. �˳�" << endl;
        cout << "��ѡ�������";
        cin >> choice;

        switch (choice) {
            case 1: {
                    int mu, nu, tu;
                    cout << "���������������������ͷ���Ԫ������";
                    cin >> mu >> nu >> tu;

                    if (tu > mu * nu) {
                        cout << "������󣬷���Ԫ�ظ���ҪС�ڵ������������������������롣" << endl;
                        continue;
                    }

                    Triple elements[MAXSIZE];
                    int lastRow = 0, lastCol = 0;

                    for (int k = 0; k < tu; k++) {
                        int row, col, value;
                        cout << "������� " << (k + 1) << " ������Ԫ�ص�λ�ú�ֵ��";
                        cin >> row >> col >> value;

                        // ����Ƿ��ظ��±�
                        bool isDuplicate = false;
                        for (int m = 0; m < k; m++) {
                            if (elements[m].i == row && elements[m].j == col) {
                                isDuplicate = true;
                                break;
                            }
                        }
                        if (isDuplicate) {
                            cout << "�������������±��ظ������������룡" << endl;
                            k--;
                            continue;
                        }

                        // ����Ƿ����
                        if (k > 0 && (row < lastRow || (row == lastRow && col <= lastCol))) {
                            cout << "��������±�����ʱҪ�������룬���������룡" << endl;
                            k--;
                            continue;
                        }

                        elements[k] = {row, col, value};
                        lastRow = row;
                        lastCol = col;
                    }

                    if (createSMatrix(M, mu, nu, tu, elements, tu)) {
                        cout << "���󴴽��ɹ���" << endl;
                    }
                break;
            }

            case 2:
                destroySMatrix(M);
                cout << "���������١�" << endl;
                break;

            case 3:
                cout << "�������ݣ�" << endl;
                printSMatrix(M);
                break;

            case 4:
                transposeSMatrix(M, T);
                cout << "ת�ú�ľ���" << endl;
                printSMatrix(T);
                break;

            case 5:
                fastTransposeSMatrix(M, T);
                cout << "����ת�ú�ľ���" << endl;
                printSMatrix(T);
                break;

            case 0:
                return 0;

            default:
                cout << "��Чѡ�����������룡" << endl;
        }
    }
}
