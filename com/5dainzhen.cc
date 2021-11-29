/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-11-28 21:04:27
 * @LastEditTime: 2021-11-28 21:51:28
 * @FilePath: \com\5dainzhen.cc
 */

#include<bits/stdc++.h>
using namespace std;

char **str={0};

char str_num[5][41] = {
    "XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX",
    "X.X...X...X...X.X.X.X...X.....X.X.X.X.X",
    "X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX",
    "X.X...X.X.....X...X...X.X.X...X.X.X...X",
    "XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX"
    };

int locate(int n)
{
    return n*3;
}

/**
 * @brief 
 * 
 * @param str 
 * @param pos 1-10 第几个字符插入 
 */
void p0(char *str[], int pos)
{
    for(int i = 0; i<5; i++)
    {
       strncpy(&str[i][pos], &str_num[i][locate(0)], 3);
       printf("%s\n",&str[i][pos]);
    }
}

int main()
{
    char a[4] = "aaa";
    char b[4][4] = {"bbb","a"};
    strcpy(b[1], a);
    cout << a << endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            putchar(b[i][j]);
        }
        cout << "\n";
    }
    p0(str, 0);
}