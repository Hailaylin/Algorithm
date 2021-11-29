/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-11-28 20:00:24
 * @LastEditTime: 2021-11-28 21:04:38
 * @FilePath: \com\6suanshu.cc
 */

// python大数忘记怎么用了

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    char opt;
    cin >> a >> opt >> b;
    
    switch (opt)
    {
    case '+':
        cout << a+b;
        break;
    case '*':
        cout << a*b; 
    default:
        break;
    }
}