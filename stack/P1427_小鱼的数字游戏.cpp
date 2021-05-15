/**
 * @file P1427_小鱼的数字游戏.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-05-15
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * https://www.luogu.com.cn/problem/P1427
 * 题目描述
小鱼最近被要求参加一个数字游戏，要求它把看到的一串数字 
�
�
a 
i
​	
 （长度不一定，以 
0
0 结束），记住了然后反着念出来（表示结束的数字 
0
0 就不要念出来了）。这对小鱼的那点记忆力来说实在是太难了，你也不想想小鱼的整个脑袋才多大，其中一部分还是好吃的肉！所以请你帮小鱼编程解决这个问题。

输入格式
一行内输入一串整数，以 
0
0 结束，以空格间隔。

输出格式
一行内倒着输出这一串整数，以空格间隔。

输入输出样例
输入 #1复制
3 65 23 5 34 1 30 0
输出 #1复制
30 1 34 5 23 65 3
说明/提示
数据规模与约定
对于 
100
%
100% 的数据，保证 
0
≤
�
�
≤
2
31
−
1
0≤a 
i
​	
 ≤2 
31
 −1，数字个数不超过 
100
100。
 */

#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> arr;
    int a;
    do{
        cin >> a;
        arr.push(a);
    }while(a);
    //cout << arr.size() << endl;
    //干掉最后输入的0
    arr.pop();
    //出栈
    while(!arr.empty())
    {
        cout << arr.top() << " ";
        arr.pop();
    }
}