/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-11-28 20:06:13
 * @LastEditTime: 2021-11-28 20:11:27
 * @FilePath: \com\9shulie.cc
 */

#include<bits/stdc++.h>
using namespace std;

long long int a(int x)
{
    if(x == 1 || x == 2 || x == 3){
        return 1;
    }
    else return a(x-1)+ a(x-3);
}

int main()
{
    int n;
    cin >> n;
    int t;
    for (int i=0; i<n; i++)
    {
        cin >> t;
        cout << a(t) % 19260817 << endl;
    }
}