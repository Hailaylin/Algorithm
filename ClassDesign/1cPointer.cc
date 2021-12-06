/*
 * @Description: 指针的复习
 * @Author: HailayLin
 * @Date: 2021-12-06 09:14:02
 * @LastEditTime: 2021-12-06 09:16:47
 * @FilePath: \ClassDesign\1cPointer.cc
 */

#include<iostream>
using namespace std;

int main()
{
    int x = 23;
    int *pointer;
    pointer = &x;
    printf("x=%d\n", x);
    printf("pointer=%p\n", pointer);
    printf("pointerVal=%d\n", *pointer);
}