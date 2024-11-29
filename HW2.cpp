//
// Created by XPIPI on 24-10-6.
// �ο�1�����ݽṹ��C���԰棩�����廪��ѧ������
// �ο�2��https://blog.csdn.net/Real_Fool_/article/details/113463997
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

// ��ʼ�����Ա�
bool initList(LinearList& L) {
    L.elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
    if (!L.elem) return false;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return true;
}

// �������Ա�
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

// ������Ա�
bool clearList(LinearList& L) {
    if (L.length == 0) return false;
    L.length = 0;
    return true;
}

// �ж����Ա��Ƿ�Ϊ��
bool isEmpty(const LinearList& L) {
    return L.length == 0;
}

// ��ȡ���Ա���
int getLength(const LinearList& L) {
    return L.length;
}

// ��ȡָ��λ��Ԫ��
bool getElem(const LinearList& L, int pos, int& value) {
    if (pos < 1 || pos > L.length) return false;
    value = L.elem[pos - 1];
    return true;
}

// ��ȡԪ�ص�λ��
int locateElem(const LinearList& L, int value) {
    for (int i = 0; i < L.length; ++i) {
        if (L.elem[i] == value) return i + 1;
    }
    return 0;
}

// ��ǰ��
bool getPredecessor(const LinearList& L, int value, int& pre) {
    int pos = locateElem(L, value);
    if (pos == 0 || pos == 1) return false;
    pre = L.elem[pos - 2];
    return true;
}

// ����
bool getSuccessor(const LinearList& L, int value, int& suc) {
    int pos = locateElem(L, value);
    if (pos == 0 || pos == L.length) return false;
    suc = L.elem[pos];
    return true;
}

// ����Ԫ��
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

// ɾ��ָ��λ��Ԫ��
bool deleteElem(LinearList& L, int pos) {
    if (pos < 1 || pos > L.length) return false;
    for (int i = pos - 1; i < L.length - 1; ++i) {
        L.elem[i] = L.elem[i + 1];
    }
    L.length--;
    return true;
}

// ɾ��ָ��ֵ��Ԫ��
bool deleteByValue(LinearList& L, int value) {
    int pos = locateElem(L, value);
    if (pos == 0) return false;
    deleteElem(L, pos);
    return true;
}

// �����Ա��������
void sortList(LinearList& L) {
    for (int i = 0; i < L.length - 1; ++i) {
        for (int j = 0; j < L.length - i - 1; ++j) {
            if (L.elem[j] > L.elem[j + 1]) {
                swap(L.elem[j], L.elem[j + 1]);
            }
        }
    }
}

// ��ʾ���Ա�
void displayList(const LinearList& L) {
    if (L.length == 0) {
        cout << "���Ա�Ϊ�գ�" << endl;
        return;
    }
    cout << "���Ա�Ԫ��: ";
    for (int i = 0; i < L.length; ++i) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

// �ϲ������������Ա�ȥ��
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
        cout << "1----��ʼ�����Ա�" << endl;
        cout << "2----�������Ա�" << endl;
        cout << "3----������Ա�" << endl;
        cout << "4----�ж����Ա��Ƿ�Ϊ��" << endl;
        cout << "5----�����Ա���" << endl;
        cout << "6----��ȡָ��λ��Ԫ��" << endl;
        cout << "7----��ȡԪ��λ��" << endl;
        cout << "8----��ǰ��" << endl;
        cout << "9----����" << endl;
        cout << "10---����Ԫ��" << endl;
        cout << "11---ɾ��ָ��λ�õ�Ԫ��" << endl;
        cout << "12---����Ԫ��ֵɾ��Ԫ��" << endl;
        cout << "13---����" << endl;
        cout << "14---��ʾ" << endl;
        cout << "15---�ϲ��������Ա�" << endl;
        cout << "�˳�������һ������" << endl;
        cout << "�����������: ";
        cin >> choice;

        if (choice < 0) break;
        if (choice != 1 && !initialized) {
            cout << "���ȳ�ʼ�����Ա�" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                if (initList(L)) {
                    initialized = true;
                    cout << "���Ա��ʼ���ɹ���" << endl;
                }
                break;
            case 2:
                if (destroyList(L)) {
                    initialized = false;
                    cout << "���Ա����ٳɹ���" << endl;
                }
                break;
            case 3:
                if (clearList(L)) cout << "���Ա�����գ�" << endl;
                else cout << "���Ա���Ϊ�գ�" << endl;
                break;
            case 4:
                cout << (isEmpty(L) ? "���Ա�Ϊ�գ�" : "���Ա�Ϊ�գ�") << endl;
                break;
            case 5:
                cout << "���Ա���Ϊ: " << getLength(L) << endl;
                break;
            case 6:
                cout << "������λ��: ";
                cin >> pos;
                if (getElem(L, pos, value)) cout << "λ�� " << pos << " ��Ԫ����: " << value << endl;
                else cout << "λ����Ч��" << endl;
                break;
            case 7:
                cout << "������Ԫ��ֵ: ";
                cin >> value;
                pos = locateElem(L, value);
                if (pos) cout << "Ԫ����λ��: " << pos << endl;
                else cout << "δ�ҵ�Ԫ�أ�" << endl;
                break;
            case 8:
                cout << "������Ԫ��ֵ: ";
                cin >> value;
                if(locateElem(L, value) == 0){
                    cout << "δ�ҵ�Ԫ�أ�" << endl;
                }else if (getPredecessor(L, value, pos)) cout << "ǰ����: " << pos << endl;
                else cout << "��ǰ����" << endl;
                break;
            case 9:
                cout << "������Ԫ��ֵ: ";
                cin >> value;
                if(locateElem(L, value) == 0){
                cout << "δ�ҵ�Ԫ�أ�" << endl;
                }else if (getSuccessor(L, value, pos)) cout << "�����: " << pos << endl;
                else cout << "�޺�̣�" << endl;
                break;
            case 10:
                cout << "���������λ�ú�Ԫ��ֵ: ";
                cin >> pos >> value;
                if (insertElem(L, pos, value)) cout << "����ɹ���" << endl;
                else cout << "����ʧ�ܣ�" << endl;
                break;
            case 11:
                cout << "������ɾ��λ��: ";
                cin >> pos;
                if (deleteElem(L, pos)) cout << "ɾ���ɹ���" << endl;
                else cout << "ɾ��ʧ�ܣ�" << endl;
                break;
            case 12:
                cout << "������Ҫɾ����Ԫ��ֵ: ";
                cin >> value;
                if (deleteByValue(L, value)) cout << "ɾ���ɹ���" << endl;
                else cout << "ɾ��ʧ�ܣ�" << endl;
                break;
            case 13:
                sortList(L);
                cout << "������ɣ�" << endl;
                break;
            case 14:
                displayList(L);
                break;
            case 15: {
                LinearList L2, L3;
                initList(L2);
                cout << "������ڶ������Ա�Ԫ������: ";
                cin >> pos;
                for (int i = 1; i <= pos; ++i) {
                    cout << "������� " << i << " ��Ԫ��: ";
                    cin >> value;
                    insertElem(L2, i, value);
                }
                sortList(L);
                sortList(L2);
                mergeLists(L, L2, L3);
                cout << "�ϲ�������Ա�: ";
                displayList(L3);
                destroyList(L2);
                destroyList(L3);
                break;
            }
            default:
                cout << "��Чѡ��" << endl;
        }
    }
    if (initialized) destroyList(L);
    return 0;
}
