/*
 * @Description: 题号：S0301        题目:入栈与出栈 
 * @Author: HailayLin
 * @Date: 2021-10-16 14:59:44
 * @LastEditTime: 2021-10-16 15:21:54
 * @FilePath: \Algorithm\stack\S0301_入栈出栈.cpp
 */
/**
 * 	
题目内容：
练习顺序栈的入栈与出栈，部分代码如图所示。
例（第1行为输入 ）：
1 2 3 4
4
3
2
1


 请注意，main()函数必须按如下所示编写：
int main()
{
    SqStack sint;
    InitStack(sint);
    
    int s;
    for(int i=0; i<4;i++)
    {
        cin>>s;
        Push(sint,s);
    }
    
    for(int i=0; i<4;i++)
    {
        int e=GetTop(sint);
        Pop(sint);
        cout<<e<<endl;
    }
    return 0;
} 
*/

#include<iostream>
using namespace std;

// 状态量
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;

/**
 * @brief 定义顺序栈，给出指向栈顶和栈底的指针
 * 
 */
typedef struct
{
    SElemType *base;    // 栈基地址
    SElemType *top;     // 栈顶，比最后的元素的还要后一个元素
    int Stacksize;      // 保存栈可保存的元素大小
}SqStack;

/**
 * @brief 初始化顺序栈
 * 
 * @param S 顺序栈名称
 * @return Status 
 */
Status InitStack(SqStack &S)
{
    // 1. 分配数组
    S.base = new SElemType[MAXSIZE];
    if (S.base == NULL) exit(OVERFLOW);
    // 2. 栈底和栈顶指针初始化
    S.top = S.base;
    S.Stacksize = MAXSIZE;
    return OK;
}

Status Push(SqStack &S, SElemType &e)
{
    // 存入元素，向后移一位即可
    *S.top++ = e;
    return OK;
}

/**
 * @brief Get the Top object
 * 
 * @param S no use &S because i want`n have chance to change SqStack
 * @return SElemType 
 */
SElemType GetTop(SqStack S)
{
    return *(S.top-1);  // 获取栈顶的前一个元素
}

Status Pop(SqStack &S)
{
    // 栈顶下移，元素置零
    *S.top-- = 0;
    return OK;
}

int main()
{
    SqStack sint;
    InitStack(sint);
    
    int s;
    for(int i=0; i<4;i++)
    {
        cin>>s;
        Push(sint,s);
    }
    
    for(int i=0; i<4;i++)
    {
        int e=GetTop(sint);
        Pop(sint);
        cout<<e<<endl;
    }
    return 0;
}

