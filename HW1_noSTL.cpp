//
// Created by XPIPI on 24-11-22.
//

#include <iostream>
using namespace std;

#define MAX_SIZE 100

// 自定义Set
struct Set {
    int elements[MAX_SIZE];
    // 当前大小
    int size;
};

void initSet(Set& s) {
    s.size = 0;
}

//查重
bool isDuplicate(const Set& s, int element) {
    for (int i = 0; i < s.size; i++) {
        if (s.elements[i] == element) return true;
    }
    return false;
}

void inputSet(Set& s, const string& setName) {
    initSet(s);
    int n, element;
    cout << "请输入" << setName << "的元素个数: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "请输入" << setName << "的第 " << i + 1 << " 个元素: ";
        cin >> element;
        while (isDuplicate(s, element)) {
            cout << "元素重复！请重新输入: ";
            cin >> element;
        }
        s.elements[s.size++] = element;
    }
}

// 求交集
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

// 求并集
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

// 求A-B
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

// 判断 A 是否是 B 的子集
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
        cout << "菜单:" << endl;
        cout << "1 --- 输入集合A和B" << endl;
        cout << "2 --- 求集合A交B" << endl;
        cout << "3 --- 求集合A并B" << endl;
        cout << "4 --- 求集合A-B" << endl;
        cout << "5 --- 判断A是否是B的子集" << endl;
        cout << "退出，请输入负数！" << endl;
        cout << "请输入您的选择: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputSet(A, "集合A");
                inputSet(B, "集合B");
                break;
            case 2: {
                Set result = setsInter(A, B);
                printSet(result, "A交B");
                break;
            }
            case 3: {
                Set result = setsUnion(A, B);
                printSet(result, "A并B");
                break;
            }
            case 4: {
                Set result = setsOppoComp(A, B);
                printSet(result, "A-B");
                break;
            }
            case 5:
                if (isSubsetAB(A, B)) {
                    cout << "A是B的子集" << endl;
                } else {
                    cout << "A不是B的子集" << endl;
                }
                break;
            default:
                if (choice >= 0) {
                    cout << "无效选择，请重新输入！" << endl;
                }
                break;
        }
    } while (choice >= 0);

    cout << "程序已退出！" << endl;
    return 0;
}

