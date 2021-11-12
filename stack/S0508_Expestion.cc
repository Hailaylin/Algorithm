/*
 * @Description: 表达式求值
 * @Author: HailayLin
 * @Date: 2021-11-10 19:03:26
 * @LastEditTime: 2021-11-10 19:03:26
 * @FilePath: \Algorithm\stack\S0508_Expestion.cc
 */
/**
 * 题号：S0508        题目:表达式的值        得分：0

作业提交截止时间：2021/11/14 0:00:00

题目内容：
练习书上算法5.12、5.13，计算表达式的值。
注：由于EXPT与OPTR两个栈中的数据不一致，可使用系统提供的栈类（#include <stack>）。

例：
（1）输入：3+2# 输出：5
（2）输入：3+2*4 # 输出：11
（3）输入：3*(4+2)# 输出：18


 请注意，main()函数必须按如下所示编写：
int main()
{
    BiTree T;
    InitExpTree(T); //先序遍历顺序创建二叉树
    //PreOrderTraverse(T); cout<<endl; //先序遍历
    cout<<EvaluateExpTree(T)<<endl; //计算表达式的值
    return 0;
}
*/

#include<iostream>

int main()
{
    BiTree T;
    InitExpTree(T); //先序遍历顺序创建二叉树
    //PreOrderTraverse(T); cout<<endl; //先序遍历
    cout<<EvaluateExpTree(T)<<endl; //计算表达式的值
    return 0;
}