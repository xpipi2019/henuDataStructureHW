//
// Created by XPIPI on 24-10-12.
// 代码框架参考：数据结构（C语言版）——清华大学出版社
// 进制转化参考：https://blog.csdn.net/2301_79397030/article/details/134702374
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

    // 原进制数转换为十进制
    while (number > 0) {
        decimal += (number % 10) * pow(originBase, power);
        number /= 10;
        power++;
    }

    string result;
    // 十进制数转换为目标进制
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

// 十六进制字符转换
char toHex(int index) {
    return "0123456789ABCDEF"[index];
}

int HW4() {
    SqStack stack;
    SElementType element;
    int choice;
    bool initialized = false;

    while (true) {
        cout << "1. 初始化栈" << endl;
        cout << "2. 销毁栈" << endl;
        cout << "3. 清空栈" << endl;
        cout << "4. 判断栈是否为空" << endl;
        cout << "5. 求栈长度" << endl;
        cout << "6. 获取栈顶元素" << endl;
        cout << "7. 插入一个元素" << endl;
        cout << "8. 删除一个元素" << endl;
        cout << "9. 输出所有元素" << endl;
        cout << "10. 进制转换" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择一个操作: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                if (InitStack(stack)) {
                    initialized = true;
                    cout << "栈已初始化" << endl;
                }
                break;
            case 2:
                if (initialized && DestroyStack(stack)) {
                    initialized = false;
                    cout << "栈已销毁" << endl;
                } else {
                    cout << "栈未初始化！" << endl;
                }
                break;
            case 3:
                if (initialized) {
                    ClearStack(stack);
                    cout << "栈已清空" << endl;
                } else {
                    cout << "栈未初始化！" << endl;
                }
                break;
            case 4:
                if (initialized) {
                    cout << (StackEmpty(stack) ? "栈为空" : "栈不为空") << endl;
                } else {
                    cout << "栈未初始化！" << endl;
                }
                break;
            case 5:
                if (initialized) {
                    cout << "栈长度为: " << StackLength(stack) << endl;
                } else {
                    cout << "栈未初始化！" << endl;
                }
                break;
            case 6:
                if (initialized && GetTop(stack, element)) {
                    cout << "栈顶元素为: " << element << endl;
                } else {
                    cout << "栈未初始化或为空！" << endl;
                }
                break;
            case 7:
                if (initialized) {
                    cout << "请输入要插入的整数: ";
                    int input;
                    cin >> input;
                    if (Push(stack, input)) {
                        cout << "元素已入栈" << endl;
                    }
                } else {
                    cout << "栈未初始化！" << endl;
                }
                break;
            case 8:
                if (initialized && Pop(stack, element)) {
                    cout << "出栈元素为: " << element << endl;
                } else {
                    cout << "栈未初始化或为空" << endl;
                }
                break;
            case 9:
                if (initialized && !StackEmpty(stack)) {
                    cout << "栈中元素为: ";
                    stackTraverse(stack, visit);
                    cout << endl;
                } else {
                    cout << "栈未初始化或为空！" << endl;
                }
                break;
            case 10:
                if (initialized && !StackEmpty(stack)) {
                    int originBase, targetBase;
                    cout << "请输入当前进制: ";
                    cin >> originBase;
                    cout << "请输入目标进制: ";
                    cin >> targetBase;
                    stackConvert(stack, originBase, targetBase);
                    cout << originBase << " 进制 --> " << targetBase << " 进制：" << endl;
                    cout << temp << endl;
                    temp.clear();
                } else {
                    cout << "栈未初始化或为空！" << endl;
                }
                break;
            default:
                cout << "无效选择" << endl;
                break;
        }
    }

    return 0;
}
