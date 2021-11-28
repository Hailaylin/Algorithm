/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-11-28 19:43:55
 * @LastEditTime: 2021-11-28 19:58:53
 * @FilePath: \com\2yinshu.cc
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int k=sqrt(n);
    bool find = 0;
    // 找因数
    int i=0;
    for (i = k; i>1 && find == 0; --i)
    {
        if (n%i == 0){
            find = 1;
            break;
        }
    }

    int yin1 = n/i;
    int yin2 = n/(n/i);
    cout << max(yin1, yin2) << endl;
}