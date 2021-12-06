/*
 * @Description: 指针的复习
 * @Author: HailayLin
 * @Date: 2021-12-06 09:14:02
 * @LastEditTime: 2021-12-06 13:57:10
 * @FilePath: \ClassDesign\1cPointer.cc
 */

#include<iostream>
using namespace std;

int sum(int a, int b)
{
    return a+b;
}

void DayByDay()
{
    return ;
}

int main()
{
    int x = 23;
    scanf("%d", &x);    // scanf使用
    int *pointer;
    pointer = &x;
    printf("x=%d\n", x);
    printf("pointer=%p\n", pointer);
    printf("pointerAddr=%p\n", &pointer);
    printf("pointerVal=%d\n", *pointer);

    // 指向函数的指针
    int (*p)(int, int);
    p = &sum;
    printf("sumAddr=%p\t p=%p\n", &sum, p);
    printf("p(3,4)=%d\n", p(3,4));

    // 五行代碼
    long long TimePassPy=1;
    bool 鐘意=1;
    while(TimePassPy){
        DayByDay();
        if(鐘意) continue;
        if(!鐘意) break;
    }
}
