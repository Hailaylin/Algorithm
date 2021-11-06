/*
 * @Description: 测试中文编码
 * @Author: HailayLin
 * @Date: 2021-09-29 18:44:24
 * @LastEditTime: 2021-11-06 14:42:11
 * @FilePath: \Algorithm\test.cpp
 */

#include<iostream>
#include<string>
using namespace std;

#define MAX 5

int main()
{
    int n,m,a[MAX][MAX];
    // 矩阵建立初始化
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
        {
            a[i][j]=0;
        }
    // 矩阵输入边
    for(int i=0; i<MAX; i++)
    {
        cin >> n >> m;
        a[n][m]=1;
        a[m][n]=1;
    }
    // 矩阵输出
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
        
}