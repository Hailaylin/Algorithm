/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-11-28 18:53:39
 * @LastEditTime: 2021-11-28 19:12:58
 * @FilePath: \com\paotui.cc
 */

#include<bits\stdc++.h>
using namespace std;

int main()
{
    double x[3], y[3];
    for(int i=0; i<3; i++)
    {
        cin >> x[i] >> y[i];
    }

    double dis1, dis2, dis3;
    // 宿舍-食堂
    dis1 = sqrt( pow(x[1]-x[0], 2) + pow(y[1]-y[0], 2) );
    // 食堂-快递
    dis2 = sqrt( pow(x[2]-x[1], 2) + pow(y[2]-y[1], 2) );
    // 快递-宿舍
    dis3 = sqrt( pow(x[2]-x[0], 2) + pow(y[2]-y[0], 2) );

    printf("%.2f", dis1+dis2+dis3);
}