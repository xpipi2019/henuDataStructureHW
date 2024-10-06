//
// Created by XPIPI on 24-10-6.
// 参考1：数据结构（C语言版）——清华大学出版社
// 参考2：https://blog.csdn.net/Real_Fool_/article/details/113463997
//
#include <iostream>
#include <algorithm>
#include <cstdlib>  // 包含 malloc 和 free

using namespace std;

const int LIST_INIT_SIZE = 100;
const int LISTINCREMENT = 10;

struct LinearList {
    int *elem;    // 存储空间基址
    int length;   // 当前长度
    int listsize; // 当前分配的存储容量
};

// 初始化线性表
bool initList(LinearList &L) {
    L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));  // 分配存储空间
    if (!L.elem) return false;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    cout << "线性表初始化成功！" << endl;
    return true;
}

// 销毁线性表
bool destroyList(LinearList &L) {
    if (L.elem) {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        L.listsize = 0;
        cout << "线性表已销毁！" << endl;
        return true;
    }
    cout << "线性表不存在！" << endl;
    return false;
}

// 清空线性表
bool clearList(LinearList &L) {
    if (L.length == 0) {
        cout << "线性表已为空！" << endl;
        return false;
    }
    L.length = 0;
    cout << "线性表已清空！" << endl;
    return true;
}

// 判断线性表是否为空
bool isEmpty(LinearList &L) {
    return L.length == 0;
}

// 获取线性表长度
int getLength(LinearList &L) {
    return L.length;
}

// 获取指定位置元素
bool getElem(LinearList &L, int pos, int &value) {
    if (pos < 1 || pos > L.length) {
        cout << "位置不合法！" << endl;
        return false;
    }
    value = L.elem[pos - 1];
    return true;
}

// 获取元素的位置
int locateElem(LinearList &L, int value) {
    for (int i = 0; i < L.length; ++i) {
        if (L.elem[i] == value) return i + 1;
    }
    return 0;
}

// 求前驱
bool getPredecessor(LinearList &L, int value, int &pre) {
    int pos = locateElem(L, value);
    if (pos == 0) {
        cout << "元素不存在！" << endl;
        return false;
    }
    if (pos == 1) {
        cout << "第一个元素没有前驱！" << endl;
        return false;
    }
    pre = L.elem[pos - 2];
    return true;
}

// 求后继
bool getSuccessor(LinearList &L, int value, int &suc) {
    int pos = locateElem(L, value);
    if (pos == 0) {
        cout << "元素不存在！" << endl;
        return false;
    }
    if (pos == L.length) {
        cout << "最后一个元素没有后继！" << endl;
        return false;
    }
    suc = L.elem[pos];
    return true;
}

// 插入元素
bool insertElem(LinearList &L, int pos, int value) {
    if (pos < 1 || pos > L.length + 1) {
        cout << "插入位置不合法！" << endl;
        return false;
    }
    if (L.length >= L.listsize) {  // 空间不足时扩容
        int *newbase = (int *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int));
        if (!newbase) return false;
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    for (int i = L.length - 1; i >= pos - 1; --i) {
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[pos - 1] = value;
    L.length++;
    cout << "元素插入成功！" << endl;
    return true;
}

// 删除指定位置元素
bool deleteElem(LinearList &L, int pos) {
    if (pos < 1 || pos > L.length) {
        cout << "删除位置不合法！" << endl;
        return false;
    }
    for (int i = pos - 1; i < L.length - 1; ++i) {
        L.elem[i] = L.elem[i + 1];
    }
    L.length--;
    cout << "元素删除成功！" << endl;
    return true;
}

// 删除指定值的元素
bool deleteByValue(LinearList &L, int value) {
    int pos = locateElem(L, value);
    if (pos == 0) {
        cout << "元素不存在，无法删除！" << endl;
        return false;
    }
    deleteElem(L, pos);
    return true;
}

// 对线性表进行排序
void sortList(LinearList &L) {
    for (int i = 0; i < L.length - 1; ++i) {
        for (int j = 0; j < L.length - i - 1; ++j) {
            if (L.elem[j] > L.elem[j + 1]) {
                swap(L.elem[j], L.elem[j + 1]);
            }
        }
    }
    cout << "线性表已排序！" << endl;
}

// 显示线性表
void displayList(LinearList &L) {
    if (L.length == 0) {
        cout << "线性表为空！" << endl;
        return;
    }
    cout << "线性表元素：";
    for (int i = 0; i < L.length; ++i) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

// 合并两个有序线性表并去重
void mergeLists(LinearList &L1, LinearList &L2, LinearList &L3) {
    int i = 0, j = 0, k = 0;
    L3.elem = (int *)malloc((L1.length + L2.length) * sizeof(int));
    if (!L3.elem) return;
    while (i < L1.length && j < L2.length) {
        if (L1.elem[i] < L2.elem[j]) {
            if (k == 0 || L3.elem[k - 1] != L1.elem[i]) L3.elem[k++] = L1.elem[i];
            i++;
        } else if (L1.elem[i] > L2.elem[j]) {
            if (k == 0 || L3.elem[k - 1] != L2.elem[j]) L3.elem[k++] = L2.elem[j];
            j++;
        } else {
            if (k == 0 || L3.elem[k - 1] != L1.elem[i]) L3.elem[k++] = L1.elem[i];
            i++;
            j++;
        }
    }
    while (i < L1.length) {
        if (k == 0 || L3.elem[k - 1] != L1.elem[i]) L3.elem[k++] = L1.elem[i];
        i++;
    }
    while (j < L2.length) {
        if (k == 0 || L3.elem[k - 1] != L2.elem[j]) L3.elem[k++] = L2.elem[j];
        j++;
    }
    L3.length = k;
    cout << "线性表合并成功！" << endl;
}

int HW2() {
    LinearList L;
    bool initialized = false;
    int choice, pos, value;

    while (true) {
        cout << "1----初始化一个线性表\n"
                << "2----销毁线性表\n"
                << "3----清空线性表\n"
                << "4----判断线性表是否为空\n"
                << "5----求线性表长度\n"
                << "6----获取线性表指定位置元素\n"
                << "7----获取线性表中元素的位置\n"
                << "8----求前驱\n"
                << "9----求后继\n"
                << "10---在线性表指定位置插入元素\n"
                << "11---删除线性表指定位置的元素\n"
                << "12---根据元素值，删除线性表中的元素\n"
                << "13---对线性表进行排序\n"
                << "14---显示线性表\n"
                << "15---合并两个非递减有序的线性表\n"
                << "退出，输入一个负数\n"
                << "请输入操作码: ";
        cin >> choice;
        if (choice < 0) break;
        if (choice != 1 && !initialized) {
            cout << "请先初始化线性表！" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                if (initList(L)) initialized = true;
                break;
            case 2:
                if (destroyList(L)) initialized = false;
                break;
            case 3:
                clearList(L);
                break;
            case 4:
                cout << (isEmpty(L) ? "线性表为空！" : "线性表不为空！") << endl;
                break;
            case 5:
                cout << "线性表长度为: " << getLength(L) << endl;
                break;
            case 6:
                cout << "请输入获取元素的位置: ";
                cin >> pos;
                if (getElem(L, pos, value)) cout << "位置 " << pos << " 处的元素为: " << value << endl;
                break;
            case 7:
                cout << "请输入要查找的位置元素值: ";
                cin >> value;
                pos = locateElem(L, value);
                if (pos) cout << "元素 " << value << " 在位置: " << pos << endl;
                else cout << "未找到该元素！" << endl;
                break;
            case 8:
                cout << "请输入要求前驱的元素: ";
                cin >> value;
                if (getPredecessor(L, value, pos)) cout << "元素 " << value << " 的前驱是: " << pos << endl;
                break;
            case 9:
                cout << "请输入要求后继的元素: ";
                cin >> value;
                if (getSuccessor(L, value, pos)) cout << "元素 " << value << " 的后继是: " << pos << endl;
                break;
            case 10:
                cout << "请输入插入元素的位置: ";
                cin >> pos;
                cout << "请输入插入元素的值: ";
                cin >> value;
                insertElem(L, pos, value);
                break;
            case 11:
                cout << "请输入删除元素的位置: ";
                cin >> pos;
                deleteElem(L, pos);
                break;
            case 12:
                cout << "请输入要删除的元素值: ";
                cin >> value;
                deleteByValue(L, value);
                break;
            case 13:
                sortList(L);
                break;
            case 14:
                displayList(L);
                break;
            case 15: {
                LinearList L2, L3;
                initList(L2);
                cout << "请输入第二个线性表的元素数量: ";
                cin >> pos;
                for (int i = 1; i <= pos; ++i) {
                    cout << "请输入第 " << i << " 个元素: ";
                    cin >> value;
                    insertElem(L2, i, value);
                }
                sortList(L);
                sortList(L2); // 保证两个线性表都是非递减有序的
                mergeLists(L, L2, L3);
                displayList(L3);
                destroyList(L2);
                destroyList(L3);
                break;
            }
            default:
                cout << "无效的操作码！" << endl;
        }
    }
    if (initialized) destroyList(L);
    return 0;
}
