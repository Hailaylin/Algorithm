/*
 * @Description: S0304_汉诺塔
 * @Author: HailayLin
 * @Date: 2021-10-17 15:36:02
 * @LastEditTime: 2021-10-17 15:57:01
 * @FilePath: \Algorithm\stack\S0304_汉诺塔.cpp
 */
/**
 * 题目内容：
输入需移动圆盘的个数，将圆盘从A移动到C，输出移动的过程与次数。
例1（第1行为输入）：
3
A-->C
A-->B
C-->B
A-->C
B-->A
B-->C
A-->C
7
*/

#include<iostream>
using namespace std;

int total = 0;
/**
 * @brief 编号为n的盘从A移动到C（一次只能移动1个）
 * 
 * @param A 从A
 * @param n 移动n个盘
 * @param C 到C
 */
void move(const char *A, int n, const char *C)
{
    cout << A << "-->" << C << endl;
    ++total;
}

/**
 * @brief 递归解决汉诺塔问题
 * 
 * @param n 要移动的汉诺塔层数
 * @param a 要从a
 * @param b 通过b
 * @param c 移动到c
 * @return int 
 */
void hanoi(int n, const char *A, const char *B, const char *C)
{
    if(n == 1)
        move(A, 1, C);
    else
    {
        hanoi(n-1, A, C, B);  // 将A上编号1至n-1的圆盘移到B, C做辅助塔
        move(A, n, C);          // 把A上最底下的圆盘移动到C
        hanoi(n-1, B, A, C);  // 把B上剩下圆盘通过A移动到C
    }
}

int main()
{
    int n = 0;
    cin >> n;
    hanoi(n,"A","B","C");
    cout << total << endl;
}