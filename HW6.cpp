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

struct TSMatrix {
    // ѹ������data[0] δʹ��
    Triple data[MAXSIZE + 1];
    // ���� ���� ����Ԫ����
    int mu, nu, tu;
};

int CreateSMatrix(TSMatrix &M, int mu, int nu, int tu, Triple elements[], int count) {
    if (tu > mu * nu) return 0;
    M.mu = mu;
    M.nu = nu;
    M.tu = tu;

    for (int k = 1; k <= count; k++) {
        M.data[k] = elements[k - 1];
    }
    return 1;
}

int DestroySMatrix(TSMatrix &M) {
    M.mu = M.nu = M.tu = 0;
    return 1;
}

void PrintSMatrix(TSMatrix M) {
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

int TransposeSMatrix(TSMatrix M, TSMatrix &T) {
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

int FastTransposeSMatrix(TSMatrix M, TSMatrix &T) {
    int num[MAXSIZE] = {0}, cpot[MAXSIZE] = {0};
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;

    if (T.tu) {
        for (int t = 1; t <= M.tu; t++) {
            num[M.data[t].j]++;
        }
        cpot[1] = 1;
        for (int col = 2; col <= M.nu; col++) {
            cpot[col] = cpot[col - 1] + num[col - 1];
        }
        for (int p = 1; p <= M.tu; p++) {
            int col = M.data[p].j;
            int q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            cpot[col]++;
        }
    }
    return 1;
}

int HW6() {
    TSMatrix M, T;
    int choice;

    while (true) {
        cout << "-----ѹ�������ת������-----" << endl;
        cout << "1. ��������" << endl;
        cout << "2. ���پ���" << endl;
        cout << "3. �������" << endl;
        cout << "4. ת�þ���" << endl;
        cout << "5. ����ת�þ���" << endl;
        cout << "0. �˳�" << endl;
        cout << "��ѡ�������";
        cin >> choice;

        if (choice == 1) {
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

            if (CreateSMatrix(M, mu, nu, tu, elements, tu)) {
                cout << "���󴴽��ɹ���" << endl;
            }

        } else if (choice == 2) {
            DestroySMatrix(M);
            cout << "���������١�" << endl;

        } else if (choice == 3) {
            cout << "��������Ϊ��" << endl;
            PrintSMatrix(M);

        } else if (choice == 4) {
            TransposeSMatrix(M, T);
            cout << "ת�ú�ľ���Ϊ��" << endl;
            PrintSMatrix(T);

        } else if (choice == 5) {
            FastTransposeSMatrix(M, T);
            cout << "����ת�ú�ľ���Ϊ��" << endl;
            PrintSMatrix(T);

        } else {
            break;
        }
    }

    return 0;
}
