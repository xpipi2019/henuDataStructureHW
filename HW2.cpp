//
// Created by XPIPI on 24-10-6.
// �ο�1�����ݽṹ��C���԰棩�����廪��ѧ������
// �ο�2��https://blog.csdn.net/Real_Fool_/article/details/113463997
//
#include <iostream>
#include <algorithm>
#include <cstdlib>  // ���� malloc �� free

using namespace std;

const int LIST_INIT_SIZE = 100;
const int LISTINCREMENT = 10;

struct LinearList {
    int *elem;    // �洢�ռ��ַ
    int length;   // ��ǰ����
    int listsize; // ��ǰ����Ĵ洢����
};

// ��ʼ�����Ա�
bool initList(LinearList &L) {
    L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));  // ����洢�ռ�
    if (!L.elem) return false;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    cout << "���Ա��ʼ���ɹ���" << endl;
    return true;
}

// �������Ա�
bool destroyList(LinearList &L) {
    if (L.elem) {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        L.listsize = 0;
        cout << "���Ա������٣�" << endl;
        return true;
    }
    cout << "���Ա����ڣ�" << endl;
    return false;
}

// ������Ա�
bool clearList(LinearList &L) {
    if (L.length == 0) {
        cout << "���Ա���Ϊ�գ�" << endl;
        return false;
    }
    L.length = 0;
    cout << "���Ա�����գ�" << endl;
    return true;
}

// �ж����Ա��Ƿ�Ϊ��
bool isEmpty(LinearList &L) {
    return L.length == 0;
}

// ��ȡ���Ա���
int getLength(LinearList &L) {
    return L.length;
}

// ��ȡָ��λ��Ԫ��
bool getElem(LinearList &L, int pos, int &value) {
    if (pos < 1 || pos > L.length) {
        cout << "λ�ò��Ϸ���" << endl;
        return false;
    }
    value = L.elem[pos - 1];
    return true;
}

// ��ȡԪ�ص�λ��
int locateElem(LinearList &L, int value) {
    for (int i = 0; i < L.length; ++i) {
        if (L.elem[i] == value) return i + 1;
    }
    return 0;
}

// ��ǰ��
bool getPredecessor(LinearList &L, int value, int &pre) {
    int pos = locateElem(L, value);
    if (pos == 0) {
        cout << "Ԫ�ز����ڣ�" << endl;
        return false;
    }
    if (pos == 1) {
        cout << "��һ��Ԫ��û��ǰ����" << endl;
        return false;
    }
    pre = L.elem[pos - 2];
    return true;
}

// ����
bool getSuccessor(LinearList &L, int value, int &suc) {
    int pos = locateElem(L, value);
    if (pos == 0) {
        cout << "Ԫ�ز����ڣ�" << endl;
        return false;
    }
    if (pos == L.length) {
        cout << "���һ��Ԫ��û�к�̣�" << endl;
        return false;
    }
    suc = L.elem[pos];
    return true;
}

// ����Ԫ��
bool insertElem(LinearList &L, int pos, int value) {
    if (pos < 1 || pos > L.length + 1) {
        cout << "����λ�ò��Ϸ���" << endl;
        return false;
    }
    if (L.length >= L.listsize) {  // �ռ䲻��ʱ����
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
    cout << "Ԫ�ز���ɹ���" << endl;
    return true;
}

// ɾ��ָ��λ��Ԫ��
bool deleteElem(LinearList &L, int pos) {
    if (pos < 1 || pos > L.length) {
        cout << "ɾ��λ�ò��Ϸ���" << endl;
        return false;
    }
    for (int i = pos - 1; i < L.length - 1; ++i) {
        L.elem[i] = L.elem[i + 1];
    }
    L.length--;
    cout << "Ԫ��ɾ���ɹ���" << endl;
    return true;
}

// ɾ��ָ��ֵ��Ԫ��
bool deleteByValue(LinearList &L, int value) {
    int pos = locateElem(L, value);
    if (pos == 0) {
        cout << "Ԫ�ز����ڣ��޷�ɾ����" << endl;
        return false;
    }
    deleteElem(L, pos);
    return true;
}

// �����Ա��������
void sortList(LinearList &L) {
    for (int i = 0; i < L.length - 1; ++i) {
        for (int j = 0; j < L.length - i - 1; ++j) {
            if (L.elem[j] > L.elem[j + 1]) {
                swap(L.elem[j], L.elem[j + 1]);
            }
        }
    }
    cout << "���Ա�������" << endl;
}

// ��ʾ���Ա�
void displayList(LinearList &L) {
    if (L.length == 0) {
        cout << "���Ա�Ϊ�գ�" << endl;
        return;
    }
    cout << "���Ա�Ԫ�أ�";
    for (int i = 0; i < L.length; ++i) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

// �ϲ������������Ա�ȥ��
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
    cout << "���Ա�ϲ��ɹ���" << endl;
}

int HW2() {
    LinearList L;
    bool initialized = false;
    int choice, pos, value;

    while (true) {
        cout << "1----��ʼ��һ�����Ա�\n"
                << "2----�������Ա�\n"
                << "3----������Ա�\n"
                << "4----�ж����Ա��Ƿ�Ϊ��\n"
                << "5----�����Ա���\n"
                << "6----��ȡ���Ա�ָ��λ��Ԫ��\n"
                << "7----��ȡ���Ա���Ԫ�ص�λ��\n"
                << "8----��ǰ��\n"
                << "9----����\n"
                << "10---�����Ա�ָ��λ�ò���Ԫ��\n"
                << "11---ɾ�����Ա�ָ��λ�õ�Ԫ��\n"
                << "12---����Ԫ��ֵ��ɾ�����Ա��е�Ԫ��\n"
                << "13---�����Ա��������\n"
                << "14---��ʾ���Ա�\n"
                << "15---�ϲ������ǵݼ���������Ա�\n"
                << "�˳�������һ������\n"
                << "�����������: ";
        cin >> choice;
        if (choice < 0) break;
        if (choice != 1 && !initialized) {
            cout << "���ȳ�ʼ�����Ա�" << endl;
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
                cout << (isEmpty(L) ? "���Ա�Ϊ�գ�" : "���Ա�Ϊ�գ�") << endl;
                break;
            case 5:
                cout << "���Ա���Ϊ: " << getLength(L) << endl;
                break;
            case 6:
                cout << "�������ȡԪ�ص�λ��: ";
                cin >> pos;
                if (getElem(L, pos, value)) cout << "λ�� " << pos << " ����Ԫ��Ϊ: " << value << endl;
                break;
            case 7:
                cout << "������Ҫ���ҵ�λ��Ԫ��ֵ: ";
                cin >> value;
                pos = locateElem(L, value);
                if (pos) cout << "Ԫ�� " << value << " ��λ��: " << pos << endl;
                else cout << "δ�ҵ���Ԫ�أ�" << endl;
                break;
            case 8:
                cout << "������Ҫ��ǰ����Ԫ��: ";
                cin >> value;
                if (getPredecessor(L, value, pos)) cout << "Ԫ�� " << value << " ��ǰ����: " << pos << endl;
                break;
            case 9:
                cout << "������Ҫ���̵�Ԫ��: ";
                cin >> value;
                if (getSuccessor(L, value, pos)) cout << "Ԫ�� " << value << " �ĺ����: " << pos << endl;
                break;
            case 10:
                cout << "���������Ԫ�ص�λ��: ";
                cin >> pos;
                cout << "���������Ԫ�ص�ֵ: ";
                cin >> value;
                insertElem(L, pos, value);
                break;
            case 11:
                cout << "������ɾ��Ԫ�ص�λ��: ";
                cin >> pos;
                deleteElem(L, pos);
                break;
            case 12:
                cout << "������Ҫɾ����Ԫ��ֵ: ";
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
                cout << "������ڶ������Ա��Ԫ������: ";
                cin >> pos;
                for (int i = 1; i <= pos; ++i) {
                    cout << "������� " << i << " ��Ԫ��: ";
                    cin >> value;
                    insertElem(L2, i, value);
                }
                sortList(L);
                sortList(L2); // ��֤�������Ա��Ƿǵݼ������
                mergeLists(L, L2, L3);
                displayList(L3);
                destroyList(L2);
                destroyList(L3);
                break;
            }
            default:
                cout << "��Ч�Ĳ����룡" << endl;
        }
    }
    if (initialized) destroyList(L);
    return 0;
}
