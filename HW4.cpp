//
// Created by XPIPI on 24-10-12.
// �����ܲο������ݽṹ��C���԰棩�����廪��ѧ������
// ����ת���ο���https://blog.csdn.net/2301_79397030/article/details/134702374
//
#include <iostream>
#include <cmath>
#include <string>
#include "myStack_int.h"

using namespace std;

string temp;
string conversion(int number, int originBase, int targetBase);
char toHex(int index);

bool stackTraverse(SqStack S, bool (*visit)(SElementType& e)) {
    SElementType* p = S.base;
    while (p != S.top) {
        if (!visit(*p++)) return false;
    }
    return true;
}

bool visit(SElementType& e) {
    cout << e << " ";
    return true;
}

void stackConvert(SqStack S, int originBase, int targetBase) {
    SElementType* p = S.base;
    while (p != S.top) {
        temp += " " + conversion(*p++, originBase, targetBase);
    }
}

string conversion(int number, int originBase, int targetBase) {
    int decimal = 0;
    int power = 0;

    // ԭ������ת��Ϊʮ����
    while (number > 0) {
        decimal += (number % 10) * pow(originBase, power);
        number /= 10;
        power++;
    }

    string result;
    // ʮ������ת��ΪĿ�����
    while (decimal > 0) {
        int remainder = decimal % targetBase;
        if (remainder >= 10) {
            result = toHex(remainder) + result;
        } else {
            result = to_string(remainder) + result;
        }
        decimal /= targetBase;
    }

    return result.empty() ? "0" : result;
}

// ʮ�������ַ�ת��
char toHex(int index) {
    return "0123456789ABCDEF"[index];
}

int HW4() {
    SqStack stack;
    SElementType element;
    int choice;
    bool initialized = false;

    while (true) {
        cout << "1. ��ʼ��ջ" << endl;
        cout << "2. ����ջ" << endl;
        cout << "3. ���ջ" << endl;
        cout << "4. �ж�ջ�Ƿ�Ϊ��" << endl;
        cout << "5. ��ջ����" << endl;
        cout << "6. ��ȡջ��Ԫ��" << endl;
        cout << "7. ����һ��Ԫ��" << endl;
        cout << "8. ɾ��һ��Ԫ��" << endl;
        cout << "9. �������Ԫ��" << endl;
        cout << "10. ����ת��" << endl;
        cout << "0. �˳�" << endl;
        cout << "��ѡ��һ������: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                if (InitStack(stack)) {
                    initialized = true;
                    cout << "ջ�ѳ�ʼ��" << endl;
                }
                break;
            case 2:
                if (initialized && DestroyStack(stack)) {
                    initialized = false;
                    cout << "ջ������" << endl;
                } else {
                    cout << "ջδ��ʼ����" << endl;
                }
                break;
            case 3:
                if (initialized) {
                    ClearStack(stack);
                    cout << "ջ�����" << endl;
                } else {
                    cout << "ջδ��ʼ����" << endl;
                }
                break;
            case 4:
                if (initialized) {
                    cout << (StackEmpty(stack) ? "ջΪ��" : "ջ��Ϊ��") << endl;
                } else {
                    cout << "ջδ��ʼ����" << endl;
                }
                break;
            case 5:
                if (initialized) {
                    cout << "ջ����Ϊ: " << StackLength(stack) << endl;
                } else {
                    cout << "ջδ��ʼ����" << endl;
                }
                break;
            case 6:
                if (initialized && GetTop(stack, element)) {
                    cout << "ջ��Ԫ��Ϊ: " << element << endl;
                } else {
                    cout << "ջδ��ʼ����Ϊ�գ�" << endl;
                }
                break;
            case 7:
                if (initialized) {
                    cout << "������Ҫ���������: ";
                    int input;
                    cin >> input;
                    if (Push(stack, input)) {
                        cout << "Ԫ������ջ" << endl;
                    }
                } else {
                    cout << "ջδ��ʼ����" << endl;
                }
                break;
            case 8:
                if (initialized && Pop(stack, element)) {
                    cout << "��ջԪ��Ϊ: " << element << endl;
                } else {
                    cout << "ջδ��ʼ����Ϊ��" << endl;
                }
                break;
            case 9:
                if (initialized && !StackEmpty(stack)) {
                    cout << "ջ��Ԫ��Ϊ: ";
                    stackTraverse(stack, visit);
                    cout << endl;
                } else {
                    cout << "ջδ��ʼ����Ϊ�գ�" << endl;
                }
                break;
            case 10:
                if (initialized && !StackEmpty(stack)) {
                    int originBase, targetBase;
                    cout << "�����뵱ǰ����: ";
                    cin >> originBase;
                    cout << "������Ŀ�����: ";
                    cin >> targetBase;
                    stackConvert(stack, originBase, targetBase);
                    cout << originBase << " ���� --> " << targetBase << " ���ƣ�" << endl;
                    cout << temp << endl;
                    temp.clear();
                } else {
                    cout << "ջδ��ʼ����Ϊ�գ�" << endl;
                }
                break;
            default:
                cout << "��Чѡ��" << endl;
                break;
        }
    }

    return 0;
}
