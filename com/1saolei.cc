/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-11-28 19:14:53
 * @LastEditTime: 2021-11-28 21:46:53
 * @FilePath: \com\1saolei.cc
 */

/**
3 3
*??
???
?*?
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    char lei[n][m]={0};
    int lei_num[n+1][m+1]={0};
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<m+1; j++)
        {
            lei_num[i][j]=0;
        }
    }

    getchar();
    // 获取雷区
    for(int i=0; i<n; i++) // 行
    {
        for(int j=0; j<m; j++) //列
        {
            
            lei[i][j] = getchar();   // 一开始是lei[n][m]…… 不能用cin
        }
        getchar();
    }

    // 扫描空数量
    for(int i=0; i<n; i++) // 行
    {
        for(int j=0; j<m; j++) //列
        {
            if (lei[i][j] == '*')
            {
                // 给雷数量矩阵+1
                if (i-1>=0)  lei_num[i-1][j]+=1; // 判断上
                if (j-1>=0) lei_num[i][j-1]+=1;//判断左
                if (i-1>=0 && j-1>=0) lei_num[i-1][j-1]+=1;//左上角
                //左下角
                if(i+1<n && j-1>=0) lei_num[i+1][j-1]+=1;
                
                if (i+1<n) lei_num[i+1][j]+=1;// 下边
                if (j+1<m) lei_num[i][j+1]+=1;// 右边
                if (i+1<n && j+1<m) lei_num[i+1][j+1]+=1;//右下角

                //右上角
                if (i-1>=0 && j+1<m) lei_num[i-1][j+1]+=1;

            }
        }
    }

    // 输出雷数量矩阵
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(lei[i][j]=='*') printf("*");
            else cout << lei_num[i][j];
        }
        printf("\n");
    }
    return 0;
}