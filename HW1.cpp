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
    if (s.empty()) cout << "为空！";
    else {
        for (set<int>::const_iterator it = s.begin(); it != s.end(); ++it) {
            cout << *it << " ";
        }
    }
    cout << endl;
}

void printMenu() {
    cout << "1---输入集合A和B\n2---求集合A交B\n3---求集合A并B\n4---求集合A-B\n5---判断A是否是B的子集\n退出，输入一个负数！" << endl;
}

void inputSet(set<int>& s, const string& input) {
    cout << input;
    int number;
    while (cin >> number && number >= 0) {
        if (s.count(number) == 0) {
            s.insert(number);
        } else {
            cout << "输入不合法或元素重复出现！" << endl;
        }
    }
    printSet(s, "");
}

void setInput() {
    inputSet(A, "请逐个输入集合A元素 输入负数退出: ");
    inputSet(B, "请逐个输入集合B元素 输入负数退出: ");
}

void setsInter() {
    res.clear();
    for (set<int>::iterator it = A.begin(); it != A.end(); ++it) {
        if (B.count(*it)) {
            res.insert(*it);
        }
    }
    printSet(res, "A交B：");
}

void setsUnion() {
    res.clear();
    for (set<int>::iterator it = A.begin(); it != A.end(); ++it) {
        res.insert(*it);
    }
    for (set<int>::iterator it = B.begin(); it != B.end(); ++it) {
        res.insert(*it);
    }
    printSet(res, "A并B：");
}

void setsOppoComp() {
    res.clear();
    for (set<int>::iterator it = A.begin(); it != A.end(); ++it) {
        if (B.count(*it) == 0) {
            res.insert(*it);
        }
    }
    printSet(res, "A-B：");
}

void isSubsetAB() {
    bool isSubset = true;
    for (set<int>::iterator it = A.begin(); it != A.end(); ++it) {
        if (B.count(*it) == 0) {
            isSubset = false;
            break;
        }
    }
    cout << (isSubset ? "A是B的子集" : "A不是B的子集") << endl;
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