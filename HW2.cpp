//
// Created by XPIPI on 24-10-6.
// 参考1：数据结构（C语言版）——清华大学出版社
// 参考2：https://blog.csdn.net/Real_Fool_/article/details/113463997
//
#include <iostream>
#include <cstdlib>
using namespace std;

const int LIST_INIT_SIZE = 100;
const int LISTINCREMENT = 10;

struct LinearList {
    int* elem;
    int length;
    int listsize;
};

// 初始化线性表
bool initList(LinearList& L) {
    L.elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
    if (!L.elem) return false;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return true;
}

// 销毁线性表
bool destroyList(LinearList& L) {
    if (L.elem) {
        free(L.elem);
        L.elem = nullptr;
        L.length = 0;
        L.listsize = 0;
        return true;
    }
    return false;
}

// 清空线性表
bool clearList(LinearList& L) {
    if (L.length == 0) return false;
    L.length = 0;
    return true;
}

// 判断线性表是否为空
bool isEmpty(const LinearList& L) {
    return L.length == 0;
}

// 获取线性表长度
int getLength(const LinearList& L) {
    return L.length;
}

// 获取指定位置元素
bool getElem(const LinearList& L, int pos, int& value) {
    if (pos < 1 || pos > L.length) return false;
    value = L.elem[pos - 1];
    return true;
}

// 获取元素的位置
int locateElem(const LinearList& L, int value) {
    for (int i = 0; i < L.length; ++i) {
        if (L.elem[i] == value) return i + 1;
    }
    return 0;
}

// 求前驱
bool getPredecessor(const LinearList& L, int value, int& pre) {
    int pos = locateElem(L, value);
    if (pos == 0 || pos == 1) return false;
    pre = L.elem[pos - 2];
    return true;
}

// 求后继
bool getSuccessor(const LinearList& L, int value, int& suc) {
    int pos = locateElem(L, value);
    if (pos == 0 || pos == L.length) return false;
    suc = L.elem[pos];
    return true;
}

// 插入元素
bool insertElem(LinearList& L, int pos, int value) {
    if (pos < 1 || pos > L.length + 1) return false;
    if (L.length >= L.listsize) {
        int* newbase = (int*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int));
        if (!newbase) return false;
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    for (int i = L.length - 1; i >= pos - 1; --i) {
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[pos - 1] = value;
    L.length++;
    return true;
}

// 删除指定位置元素
bool deleteElem(LinearList& L, int pos) {
    if (pos < 1 || pos > L.length) return false;
    for (int i = pos - 1; i < L.length - 1; ++i) {
        L.elem[i] = L.elem[i + 1];
    }
    L.length--;
    return true;
}

// 删除指定值的元素
bool deleteByValue(LinearList& L, int value) {
    int pos = locateElem(L, value);
    if (pos == 0) return false;
    deleteElem(L, pos);
    return true;
}

// 对线性表进行排序
void sortList(LinearList& L) {
    for (int i = 0; i < L.length - 1; ++i) {
        for (int j = 0; j < L.length - i - 1; ++j) {
            if (L.elem[j] > L.elem[j + 1]) {
                swap(L.elem[j], L.elem[j + 1]);
            }
        }
    }
}

// 显示线性表
void displayList(const LinearList& L) {
    if (L.length == 0) {
        cout << "线性表为空！" << endl;
        return;
    }
    cout << "线性表元素: ";
    for (int i = 0; i < L.length; ++i) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

// 合并两个有序线性表并去重
void mergeLists(const LinearList& L1, const LinearList& L2, LinearList& L3) {
    int i = 0, j = 0, k = 0;
    L3.elem = (int*)malloc((L1.length + L2.length) * sizeof(int));
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
}

int HW2() {
    LinearList L;
    bool initialized = false;
    int choice, pos, value;

    while (true) {
        cout << "1----初始化线性表" << endl;
        cout << "2----销毁线性表" << endl;
        cout << "3----清空线性表" << endl;
        cout << "4----判断线性表是否为空" << endl;
        cout << "5----求线性表长度" << endl;
        cout << "6----获取指定位置元素" << endl;
        cout << "7----获取元素位置" << endl;
        cout << "8----求前驱" << endl;
        cout << "9----求后继" << endl;
        cout << "10---插入元素" << endl;
        cout << "11---删除指定位置的元素" << endl;
        cout << "12---根据元素值删除元素" << endl;
        cout << "13---排序" << endl;
        cout << "14---显示" << endl;
        cout << "15---合并两个线性表" << endl;
        cout << "退出，输入一个负数" << endl;
        cout << "请输入操作码: ";
        cin >> choice;

        if (choice < 0) break;
        if (choice != 1 && !initialized) {
            cout << "请先初始化线性表！" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                if (initList(L)) {
                    initialized = true;
                    cout << "线性表初始化成功！" << endl;
                }
                break;
            case 2:
                if (destroyList(L)) {
                    initialized = false;
                    cout << "线性表销毁成功！" << endl;
                }
                break;
            case 3:
                if (clearList(L)) cout << "线性表已清空！" << endl;
                else cout << "线性表已为空！" << endl;
                break;
            case 4:
                cout << (isEmpty(L) ? "线性表为空！" : "线性表不为空！") << endl;
                break;
            case 5:
                cout << "线性表长度为: " << getLength(L) << endl;
                break;
            case 6:
                cout << "请输入位置: ";
                cin >> pos;
                if (getElem(L, pos, value)) cout << "位置 " << pos << " 的元素是: " << value << endl;
                else cout << "位置无效！" << endl;
                break;
            case 7:
                cout << "请输入元素值: ";
                cin >> value;
                pos = locateElem(L, value);
                if (pos) cout << "元素在位置: " << pos << endl;
                else cout << "未找到元素！" << endl;
                break;
            case 8:
                cout << "请输入元素值: ";
                cin >> value;
                if(locateElem(L, value) == 0){
                    cout << "未找到元素！" << endl;
                }else if (getPredecessor(L, value, pos)) cout << "前驱是: " << pos << endl;
                else cout << "无前驱！" << endl;
                break;
            case 9:
                cout << "请输入元素值: ";
                cin >> value;
                if(locateElem(L, value) == 0){
                cout << "未找到元素！" << endl;
                }else if (getSuccessor(L, value, pos)) cout << "后继是: " << pos << endl;
                else cout << "无后继！" << endl;
                break;
            case 10:
                cout << "请输入插入位置和元素值: ";
                cin >> pos >> value;
                if (insertElem(L, pos, value)) cout << "插入成功！" << endl;
                else cout << "插入失败！" << endl;
                break;
            case 11:
                cout << "请输入删除位置: ";
                cin >> pos;
                if (deleteElem(L, pos)) cout << "删除成功！" << endl;
                else cout << "删除失败！" << endl;
                break;
            case 12:
                cout << "请输入要删除的元素值: ";
                cin >> value;
                if (deleteByValue(L, value)) cout << "删除成功！" << endl;
                else cout << "删除失败！" << endl;
                break;
            case 13:
                sortList(L);
                cout << "排序完成！" << endl;
                break;
            case 14:
                displayList(L);
                break;
            case 15: {
                LinearList L2, L3;
                initList(L2);
                cout << "请输入第二个线性表元素数量: ";
                cin >> pos;
                for (int i = 1; i <= pos; ++i) {
                    cout << "请输入第 " << i << " 个元素: ";
                    cin >> value;
                    insertElem(L2, i, value);
                }
                sortList(L);
                sortList(L2);
                mergeLists(L, L2, L3);
                cout << "合并后的线性表: ";
                displayList(L3);
                destroyList(L2);
                destroyList(L3);
                break;
            }
            default:
                cout << "无效选择！" << endl;
        }
    }
    if (initialized) destroyList(L);
    return 0;
}
