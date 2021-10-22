/*
 * @Description: 测试中文编码
 * @Author: HailayLin
 * @Date: 2021-09-29 18:44:24
 * @LastEditTime: 2021-10-18 16:30:11
 * @FilePath: \Algorithm\test.cpp
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string chs_test_str = "中文测试";
    cout << chs_test_str << endl;
    string chs_str_input;
    printf("输入：");
    cin >> chs_str_input;
    cout << "输出：" << chs_str_input;
}