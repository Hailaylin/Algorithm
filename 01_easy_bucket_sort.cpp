/**
 * @file 01_easy_bucket_sort.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-05-01
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * 
 */

#include<iostream>
using namespace std;

int main(){
    //实现5个数的简易桶排序,数字范围0-10
    int array[11]={0};  
    int tmp=0;
    //初始化数组
    for (int i=0; i<11; i++) {
        array[i]=0;
    }
    //输入并把数放入捅中
    for (int i=0; i<5; i++){
        cin >> tmp;
        array[tmp]++;
    }
    //从大到小输出
    for (int i=11; i>=0; i--){
        if (array[i]){  //实现输出，但输出会合并
            cout << i << " " ;
        }
    }
}