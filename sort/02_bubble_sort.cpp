/**
 * @file 02_bubble_sort.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-05-01
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * 
 */

//重写冒泡排序：以前冒泡排序的实现

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;   //输入要排序的数个数
    
    double *arr = new double(n); //动态创建数组
    //输入待排序数字
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    //排序,从大到小，小的在后面，不满足就调换
    for (int i=0; i<n-1; i++) { //n个数只要排n-1趟，最后一个就自己归位了
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]<arr[j+1]){
                double tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    //输出
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}