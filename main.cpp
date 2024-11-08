//
// Created by XPIPI on 24-10-6.
//
#include <iostream>
using namespace std;
int HW1();
int HW2();
int HW3();
int HW4();
int HW5();
int HW6();
int HW7();

int main()
{
    int choice;
    cin >> choice;
    switch (choice)
    {
        case 1:HW1();break;
        case 2:HW2();break;
        case 3:HW3();break;
        case 4:HW4();break;
        case 5:HW5();break;
        case 6:HW6();break;
        case 7:HW7();break;
        default: break;
    }
    return 0;
}
