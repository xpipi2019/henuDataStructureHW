//
// Created by XPIPI on 24-10-6.
// Using STL set
//
#include <iostream>
#include <set>

/*
using namespace std;

#define endl '\n'

set<int> A, B, res;
int opt = -1;

void setInput();
void setsInter();
void setsUnion();
void setsOppoComp();
void isSubsetAB();

void printSet(const set<int>& s, const string& input) {
    cout << input;
    if (s.empty()) cout << "Ϊ�գ�";
    else {
        for (set<int>::const_iterator it = s.begin(); it != s.end(); ++it) {
            cout << *it << " ";
        }
    }
    cout << endl;
}

void printMenu() {
    cout << "1---���뼯��A��B\n2---�󼯺�A��B\n3---�󼯺�A��B\n4---�󼯺�A-B\n5---�ж�A�Ƿ���B���Ӽ�\n�˳�������һ��������" << endl;
}

void inputSet(set<int>& s, const string& input) {
    cout << input;
    int number;
    while (cin >> number && number >= 0) {
        if (s.count(number) == 0) {
            s.insert(number);
        } else {
            cout << "���벻�Ϸ���Ԫ���ظ����֣�" << endl;
        }
    }
    printSet(s, "");
}

void setInput() {
    inputSet(A, "��������뼯��AԪ�� ���븺���˳�: ");
    inputSet(B, "��������뼯��BԪ�� ���븺���˳�: ");
}

void setsInter() {
    res.clear();
    for (set<int>::iterator it = A.begin(); it != A.end(); ++it) {
        if (B.count(*it)) {
            res.insert(*it);
        }
    }
    printSet(res, "A��B��");
}

void setsUnion() {
    res.clear();
    for (set<int>::iterator it = A.begin(); it != A.end(); ++it) {
        res.insert(*it);
    }
    for (set<int>::iterator it = B.begin(); it != B.end(); ++it) {
        res.insert(*it);
    }
    printSet(res, "A��B��");
}

void setsOppoComp() {
    res.clear();
    for (set<int>::iterator it = A.begin(); it != A.end(); ++it) {
        if (B.count(*it) == 0) {
            res.insert(*it);
        }
    }
    printSet(res, "A-B��");
}

void isSubsetAB() {
    bool isSubset = true;
    for (set<int>::iterator it = A.begin(); it != A.end(); ++it) {
        if (B.count(*it) == 0) {
            isSubset = false;
            break;
        }
    }
    cout << (isSubset ? "A��B���Ӽ�" : "A����B���Ӽ�") << endl;
}

int HW1() {
    do {
        printMenu();
        cin >> opt;
        switch (opt) {
            case 1: setInput(); break;
            case 2: setsInter(); break;
            case 3: setsUnion(); break;
            case 4: setsOppoComp(); break;
            case 5: isSubsetAB(); break;
            default: break;
        }
    } while (opt >= 0);
    
    return 0;
}

*/