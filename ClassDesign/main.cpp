#include<iostream>
using namespace std;

int sum(int a, int b)
{
    return a+b;
}

int main()
{
    int x = 23;
    scanf("%d", &x);    // scanf使用
    int *pointer;
    pointer = &x;
    printf("x=%d\n", x);
    printf("pointer=%p\n", pointer);
    printf("pointerVal=%d\n", *pointer);

    // 指向函数的指针
    int (*p)(int, int);
    p = &sum;
    printf("sumAddr=%p\t p=%p\n", &sum, p);
    printf("p(3,4)=%d\n", p(3,4));


}