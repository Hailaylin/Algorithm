/*
 * @Description: KMP算法学习
 * @Author: HailayLin
 * @Date: 2021-10-22 18:01:25
 * @LastEditTime: 2021-10-22 18:12:14
 * @FilePath: \Algorithm\string\KMP.cc
 * 参考 https://www.cnblogs.com/zhangtianq/p/5839909.html
 */

#include<iostream>
using namespace std;

/**
 * @brief 获取PMT-1的数组，按照书本的方法实现，开头省略next[0]，从[1]开始
 * 
 * @param P 
 * @param next 
 */
void GetNextval(char *P, int nextval[])
{
    int p_len = strlen(P);
    int i = 1;
    int j = 0;
}