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
/**
 * “冒泡排序”的原理是：每一趟只能确定将一个数归位。
 * 冒泡排序的基本思想是：每次比较两个相邻的元素，如果它们的顺序错误就把它们交换过来。
 * 既然是从大到小排序，也就是说越小的越靠后，
 * 最后我们总结一下：如果有 n 个数进行排序，只需将 n-1 个数归位，也就是说要进行
 * n-1 趟操作。而“每一趟”都需要从第 1 位开始进行相邻两个数的比较，将较小的一个数放
 * 在后面，比较完毕后向后挪一位继续比较下面两个相邻数的大小，重复此步骤，直到最后一
 * 个尚未归位的数，已经归位的数则无需再进行比较（已经归位的数你还比较个啥，浪费表情）
 */ 
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;   //输入要排序的数个数
    
    double *arr = new double[n+1]; //动态创建数组
    //输入待排序数字
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    //排序,从大到小，小的在后面，不满足就调换
    for (int i=1; i<=n-1; i++) { //n个数只要排n-1趟，最后一个就自己归位了
        for (int j=1; j<=n-i; j++) {       //why n-i?排好的i个元素有不管它了
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