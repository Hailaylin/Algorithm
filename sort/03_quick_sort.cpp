/**
 * @file 03_quick_sort.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-05-01
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * 
 */

//练习快速排序

#include<iostream>
using namespace std;
double arr[100];
    void quicksort(int left, int right){
        int i, j;
        if (left > right) return;
        int base = arr[left];
        i=left;
        j=right;

        while(i!=j) {
            while(arr[j]>=base && i<j) {
                j--;
            }
            while(arr[i]<=base && i<j) {
                i++;
            }
            //少写了没有相遇的情况
            if (i<j) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
        //i==j，交换
        arr[left] = arr[i];
        arr[i] = base;

        //递归:base左边和右边
        quicksort(left, i-1);
        quicksort(i+i, right);
    }

int main() {
    int n;
    cin >> n;
    //double *arr = new double[n+1];
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }


    quicksort(1, n);

    for (int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }

    //delete arr;
}

