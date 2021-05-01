/**
 * @file 01_easy_bucket_sort.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-05-01
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * 
 */

//好玩的简易桶排序，自己理解实现超快乐
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    //实现5个数的简易桶排序,数字范围0-10
    int array[11]={0};  //①这样初始化也行，默认初始化为0
    int tmp=0;
    //②遍历初始化数组
    for (int i=0; i<11; i++) {
        array[i]=0;
    }
    //③调库初始化数组
    memset(array, 0, sizeof(array));
    //输入并把数放入捅中
    for (int i=0; i<5; i++){
        cin >> tmp;
        array[tmp]++;
    }
    //从大到小输出
    for (int i=11; i>=0; i--){ //i,从数字0-11遍历
        for (int j=array[i]; j>0; j--)       //标记每个数字输出多少次
            cout << i << " " ;
    }
}