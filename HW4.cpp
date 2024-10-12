//
// Created by XPIPI on 24-10-12.
// �����ܲο������ݽṹ��C���԰棩�����廪��ѧ������
// ����ת���ο���https://blog.csdn.net/2301_79397030/article/details/134702374
//
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
typedef int SElementType;

typedef struct
{
    SElementType *base;
    SElementType *top;
    int stack_size;
}SqStack;

string temp;

bool InitStack(SqStack &S);
bool DestroyStack(SqStack &S);
void ClearStack(SqStack &S);
bool StackEmpty(SqStack S);
int StackLength(SqStack S);
bool GetTop(SqStack S, SElementType &e);
bool Push(SqStack &S, SElementType e);
bool Pop(SqStack &S, SElementType &e);
bool StackTraverse(SqStack S, bool (*visit)(SElementType &e));

void StackConvert(SqStack S, int originBase, int targetBase);
string conversion(int number, int originBase, int targetBase);
char ToHax(int index);

bool InitStack(SqStack &S) {
    S.base = (SElementType *)malloc(STACK_INIT_SIZE * sizeof(SElementType));
    if (!S.base) return false;
    S.top = S.base;
    S.stack_size = STACK_INIT_SIZE;
    return true;
}//InitStack

bool DestroyStack(SqStack &S) {
    if (S.base) {
        free(S.base);
        S.top = nullptr;
        S.base = nullptr;
        S.stack_size = 0;
        return true;
    }
    return false;
}

void ClearStack(SqStack &S) {
    S.top = S.base;
}

bool StackEmpty(SqStack S) {
    return S.top == S.base;
}

int StackLength(SqStack S) {
    return S.top - S.base;
}

bool GetTop(SqStack S, SElementType &e) {
    if (S.top == S.base) return false;
    e = *(S.top - 1);
    return true;
}// GetTop

bool Push(SqStack &S, SElementType e) {
    if (StackLength(S) >= S.stack_size){
        S.base = (SElementType * ) realloc(S.base, (S.stack_size + 1) * sizeof(SElementType));
        if (!S.base) return false;
        S.top = S.base + S.stack_size;
        S.stack_size += STACK_INCREMENT;
    }
    *S.top++ = e;
    return true;
}// Push

bool Pop(SqStack &S, SElementType &e) {
    if (S.top == S.base) return false;
    e = *(--S.top);
    return true;
}// Pop

bool StackTraverse(SqStack S, bool (*visit)(SElementType &e)) {
    SElementType *p = S.base;
    while (p != S.top) {
        if (!visit(*p++)) return false;
    }
    return true;
}

bool visit(SElementType &e) {
    cout << e << " ";
    return true;
}

void StackConvert(SqStack S, int originBase, int targetBase) {
    SElementType *p = S.base;
    while (p != S.top) {
        temp += (" " + conversion(*p++, originBase, targetBase));
    }
}

string conversion(int number, int originBase, int targetBase) {
    int decimal = 0;
    int power = 0;

    while (number > 0) {
        decimal += (number % 10) * pow(originBase, power);
        number /= 10;
        power++;
    }

    string result;
    while (decimal > 0) {
        int remainder = decimal % targetBase;
        if (remainder >= 10) {
            result = ToHax(remainder) + result;
        } else {
            result = to_string(remainder) + result;
        }
        decimal /= targetBase;
    }

    return result;
}

char ToHax(int index) {
    return "0123456789ABCDEF"[index];
}

int HW4() {
    SqStack stack;
    SElementType element;
    int choice;
    bool initialized = false;

    while (true) {
        cout << "\n��ѡ��һ������:\n";
        cout << "1. ��ʼ��ջ\n";
        cout << "2. ����ջ\n";
        cout << "3. ���ջ\n";
        cout << "4. �ж�ջ�Ƿ�Ϊ��\n";
        cout << "5. ��ջ����\n";
        cout << "6. ��ȡջ��Ԫ��\n";
        cout << "7. ����һ��Ԫ��\n";
        cout << "8. ɾ��һ��Ԫ��\n";
        cout << "9. �������Ԫ��\n";
        cout << "10. ����ת��\n";
        cout << "0. �˳�\n";
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
                    StackTraverse(stack,visit);
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
                    StackConvert(stack, originBase, targetBase);
                    cout << originBase << " ���� --> " << targetBase << " ���ƣ�"<<endl;
                    cout << temp;
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