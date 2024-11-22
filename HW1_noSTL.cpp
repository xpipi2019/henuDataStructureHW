//
// Created by XPIPI on 24-11-22.
//

#include <iostream>
using namespace std;

#define MAX_SIZE 100

// �Զ���Set
struct Set {
    int elements[MAX_SIZE];
    // ��ǰ��С
    int size;
};

void initSet(Set& s) {
    s.size = 0;
}

//����
bool isDuplicate(const Set& s, int element) {
    for (int i = 0; i < s.size; i++) {
        if (s.elements[i] == element) return true;
    }
    return false;
}

void inputSet(Set& s, const string& setName) {
    initSet(s);
    int n, element;
    cout << "������" << setName << "��Ԫ�ظ���: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "������" << setName << "�ĵ� " << i + 1 << " ��Ԫ��: ";
        cin >> element;
        while (isDuplicate(s, element)) {
            cout << "Ԫ���ظ�������������: ";
            cin >> element;
        }
        s.elements[s.size++] = element;
    }
}

// �󽻼�
Set setsInter(const Set& A, const Set& B) {
    Set result;
    initSet(result);
    for (int i = 0; i < A.size; i++) {
        for (int j = 0; j < B.size; j++) {
            if (A.elements[i] == B.elements[j]) {
                result.elements[result.size++] = A.elements[i];
                break;
            }
        }
    }
    return result;
}

// �󲢼�
Set setsUnion(const Set& A, const Set& B) {
    Set result;
    initSet(result);
    for (int i = 0; i < A.size; i++) {
        result.elements[result.size++] = A.elements[i];
    }
    for (int j = 0; j < B.size; j++) {
        if (!isDuplicate(A, B.elements[j])) {
            result.elements[result.size++] = B.elements[j];
        }
    }
    return result;
}

// ��A-B
Set setsOppoComp(const Set& A, const Set& B) {
    Set result;
    initSet(result);
    for (int i = 0; i < A.size; i++) {
        if (!isDuplicate(B, A.elements[i])) {
            result.elements[result.size++] = A.elements[i];
        }
    }
    return result;
}

// �ж� A �Ƿ��� B ���Ӽ�
bool isSubsetAB(const Set& A, const Set& B) {
    for (int i = 0; i < A.size; i++) {
        if (!isDuplicate(B, A.elements[i])) return false;
    }
    return true;
}

void printSet(const Set& s, const string& setName) {
    cout << setName << " = { ";
    for (int i = 0; i < s.size; i++) {
        cout << s.elements[i];
        if (i < s.size - 1) cout << ", ";
    }
    cout << " }" << endl;
}

int HW1() {
    Set A{}, B{};
    int choice;

    do {
        cout << "�˵�:" << endl;
        cout << "1 --- ���뼯��A��B" << endl;
        cout << "2 --- �󼯺�A��B" << endl;
        cout << "3 --- �󼯺�A��B" << endl;
        cout << "4 --- �󼯺�A-B" << endl;
        cout << "5 --- �ж�A�Ƿ���B���Ӽ�" << endl;
        cout << "�˳��������븺����" << endl;
        cout << "����������ѡ��: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputSet(A, "����A");
                inputSet(B, "����B");
                break;
            case 2: {
                Set result = setsInter(A, B);
                printSet(result, "A��B");
                break;
            }
            case 3: {
                Set result = setsUnion(A, B);
                printSet(result, "A��B");
                break;
            }
            case 4: {
                Set result = setsOppoComp(A, B);
                printSet(result, "A-B");
                break;
            }
            case 5:
                if (isSubsetAB(A, B)) {
                    cout << "A��B���Ӽ�" << endl;
                } else {
                    cout << "A����B���Ӽ�" << endl;
                }
                break;
            default:
                if (choice >= 0) {
                    cout << "��Чѡ�����������룡" << endl;
                }
                break;
        }
    } while (choice >= 0);

    cout << "�������˳���" << endl;
    return 0;
}

