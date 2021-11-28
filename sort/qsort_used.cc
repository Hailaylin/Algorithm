/*
 * @Description: 练习使用qsort
 * @Author: HailayLin
 * @Date: 2021-11-28 16:28:51
 * @LastEditTime: 2021-11-28 16:40:30
 * @FilePath: \Algorithm\sort\qsort_used.cc
 */

#include<iostream>
using namespace std;

/* 虽然能改变数据类型，但是不同的数据类型得单独判断
参考
https://blog.csdn.net/zhao888789/article/details/79186619
*/
typedef int ElemType;

ElemType score[] = { 100, 88, 99, 10, 25, 61, 60};

/**
 * @brief 快速排序比较函数(升序)
 * 
 * @param a 
 * @param b 
 */
int cmpfunc(const void *_a, const void *_b)
{
    ElemType *a = (int *)_a;
    ElemType *b = (int *)_b;
    return *a - *b;
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