/*
 * @Description: 练习使用qsort
 * @Author: HailayLin
 * @Date: 2021-11-28 16:28:51
 * @LastEditTime: 2021-11-28 16:37:45
 * @FilePath: \Algorithm\sort\qsort_used.cc
 */

#include<iostream>
using namespace std;

typedef int ElemType;

ElemType score[] = { 100, 88, 99, 10, 25, 61, 60};

/**
 * @brief 快速排序比较函数(升序)
 * 
 * @param a 
 * @param b 
 */
int cmpfunc(const void *a, const void *b)
{
    return ( *(ElemType *)a - *(ElemType *)b);
}

// 输出数组元素
void printArray(ElemType arr[], int num)
{
    for (int i=0; i<num; i++)
    {
        printf("%d ", score[i]);
    }
}

int main()
{
    int n = 7;
    
    printArray(score, n);
    qsort(score, n, sizeof(ElemType), cmpfunc);
    printf("\n");
    printArray(score, n);

    return 0;
}