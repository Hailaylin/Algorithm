/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-09-29 18:44:24
 * @LastEditTime: 2021-12-13 21:10:12
 * @FilePath: \Algorithm\test.cpp
 */

#include<iostream>
using namespace std;

int main() {
    FILE *fp = fopen("233", "r");
    if (fp == NULL) cout << "null";
    else cout << "have?";

    return 0;
}