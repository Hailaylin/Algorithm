/**
 * @file 02_bubble_sort.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-05-01
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * 
 */

//重写冒泡排序：书上的实现，for循环循环的次数更加清晰，但是arr[0]不能用到，要多开一位，属于小瑕疵

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;   //输入要排序的数个数
    
    double *arr = new double(n+1); //动态创建数组
    //输入待排序数字
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    //排序,从大到小，小的在后面，不满足就调换
    for (int i=1; i<=n-1; i++) { //n个数只要排n-1趟，最后一个就自己归位了
        for (int j=1; j<=n-i; j++) {
            if (arr[j]<arr[j+1]){
                double tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    //输出
    for (int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
}