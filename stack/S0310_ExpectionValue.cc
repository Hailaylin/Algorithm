/*
 * @Description: 表达式求值
 * @Author: HailayLin
 * @Date: 2021-11-12 16:47:01
 * @LastEditTime: 2021-11-12 16:49:18
 * @FilePath: \Algorithm\stack\S0310_ExpectionValue.cc
 */
/**
 * 	题号：S0310        题目:表达式的值        得分：0  
  
作业提交截止时间：2022/1/20 0:00:00	 
 	
题目内容：
在S0306的基础上修改程序，求表达式的值（表达式中的数值在[0,9]范围）。
例：
（1）输入：#3*4# 输出：12
（2）输入：#2*(5+6) 输出：22

 请注意，main()函数必须按如下所示编写：
int main()
{
    string str;
    getline(cin,str);
    cout<<EvalueateExpression(str)-'0'<<endl; //计算表达式的值 
    return 0;
}
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;



void EvalueateExpression(string str)
{

}

int main()
{
    string str;
    getline(cin,str);
    cout<<EvalueateExpression(str)-'0'<<endl; //计算表达式的值 
    return 0;
}