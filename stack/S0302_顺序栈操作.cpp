/*
 * @Description:顺序栈操作
 * @Author: HailayLin
 * @Date: 2021-10-16 15:36:58
 * @LastEditTime: 2021-10-16 15:54:58
 * @FilePath: \Algorithm\stack\S0302_顺序栈操作.cpp
 */
/**
 * 题目内容：
在S0301的基础上修改程序。
例（第1行为输入）：
3 2.2 3.3 5.6
There are 3 numbers in the stack:
2.2
3.3
5.6
ClearStack()
0

 请注意，main()函数必须按如下所示编写：
int main()
{
    SqStack sint;
    InitStack(sint);
    
    int n;
    float s;
    cin>>n;
    for(int i=0; i<n;i++)
    {
        cin>>s;
        Push(sint,s);
    }
    if(!StackEmpty(sint))
    {
        cout<<"There are "<<StackLength(sint)<<" numbers in the stack:"<<endl;
        StackTraverse(sint); //从栈底到栈顶遍历 
    }
    cout<<"ClearStack()"<<endl;
    ClearStack(sint);
    cout<<StackLength(sint)<<endl;
    DestroyStack(sint);
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
typedef float SElemType;

/**
 * @brief 定义顺序栈，给出指向栈顶和栈底的指针
 * 
 */
typedef struct
{
    SElemType *base;    // 栈基地址
    SElemType *top;     // 栈顶，比最后的元素的还要后一个元素
    int Stacksize;      // 保存栈已加入的元素
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
    S.Stacksize = 0;
    return OK;
}

Status Push(SqStack &S, SElemType &e)
{
    // 存入元素，向后移一位即可
    *S.top++ = e;
    S.Stacksize++;
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
    S.Stacksize--;
    return OK;
}

bool StackEmpty(SqStack &S)
{
    if (S.base == S.top && S.Stacksize == 0) return true;
    else return false;
}

SElemType StackLength(SqStack S)
{
    return S.Stacksize;
}

Status StackTraverse(SqStack S)
{
    SElemType *p = S.base;
    while(p != S.top)
    {
        cout << *p++ << endl;
    }
    return OK;
}

Status ClearStack(SqStack &S)
{
    while(S.base != S.top)
    {
        *--S.top = 0;
        --S.Stacksize;
    }
    return OK;
}

Status DestroyStack(SqStack &S)
{
    delete S.base;
    return OK;
}

int main()
{
    SqStack sint;
    InitStack(sint);
    
    int n;
    float s;
    cin>>n;
    for(int i=0; i<n;i++)
    {
        cin>>s;
        Push(sint,s);
    }
    if(!StackEmpty(sint))
    {
        cout<<"There are "<<StackLength(sint)<<" numbers in the stack:"<<endl;
        StackTraverse(sint); //从栈底到栈顶遍历 
    }
    cout<<"ClearStack()"<<endl;
    ClearStack(sint);
    cout<<StackLength(sint)<<endl;
    DestroyStack(sint);
    return 0;
} 