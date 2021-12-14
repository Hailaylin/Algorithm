/*
 * @Description: 链栈
 * @Author: HailayLin
 * @Date: 2021-10-11 11:15:28
 * @LastEditTime: 2021-10-11 15:52:02
 * @FilePath: \Algorithm\stack\S0303_链栈入栈出栈.cpp
 */

/**
 *  	
题目内容：
链栈的入栈与出栈。
部分代码如图所示。
例（前3行为输入）：
3Hebei
Tangshan fengrun
Handan wuan
Handan wuan
Tangshan fengrun
Hebei

 请注意，main()函数必须按如下所示编写：
int main()
{
    LinkStack Ls;
    InitStack(Ls); //初始化链栈 
    int n;
    string s;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        getline(cin,s);
        Push(Ls,s);     //入栈 
    }
    
    while(!StackEmpty(Ls))
    {
        cout<<GetTop(Ls)<<endl; //取栈顶元素 
        Pop(Ls);     //出栈 
    }
}
 */

#include<iostream>
#include<string>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int Status;
typedef string SElemType;

/**
 * @brief 链栈节点
 * 
 */
typedef struct StackNode
{
    //数据域
    SElemType data;
    int stacksize;          // 这个数值有啥用？假如使用，每新增一个节点都修改一次大小。或者说是一个定值？例如MAXSIZE？这样就多用了空间不划算
    //指针域：指向下一栈节点
    struct StackNode *next;
}StackNode, *LinkStack;

/**
 * @brief 链栈初始化
 * 
 * @param S
 * @return Status 
 */
Status InitStack(LinkStack &S)
{
    S = NULL;
    return OK;
}


/**
 * @brief 入栈操作
 * 
 * @param S 链栈名称
 * @param e 要压入的元素
 * @return Status 
 */
Status Push(LinkStack &S, SElemType e)
{
    //1. 生成新节点, 数据域赋值e
    LinkStack p = new StackNode;
    p->data = e;
    //2. 节点插入栈顶，修改栈顶指针为p
    p->next = S;
    S = p;
    return OK;
}


/**
 * @brief 判断栈链是否为空
 * 
 * @param S 栈链名称
 * @return Status 
 */
Status StackEmpty(LinkStack &S)
{
    if(S==NULL) return true;
    else return false;
}

/**
 * @brief Get the Stack Top object
 * 
 * @param S 链栈名称
 * @return SElemType 
 */
SElemType GetTop(LinkStack &S)
{
    return S->data;
}


SElemType Pop(LinkStack &S)
{
    //1. 判断栈非空,因为main函数进行了操作，于是不进行；
    // 如果main函数没有判断就要加上
    // if(S==NULL) return false
    //2. 指针p指向栈顶元素
    LinkStack p = S;
    //3. 移动栈指针S到下一个元素
    S = S->next;
    //4. 删除p节点，返回值
    SElemType e = p->data;
    delete p;
    return e;
}

int main()
{
    LinkStack Ls;
    InitStack(Ls); //初始化链栈 
    int n;
    string s;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        getline(cin,s);
        Push(Ls,s);     //入栈 
    }
    
    while(!StackEmpty(Ls))
    {
        cout<<GetTop(Ls)<<endl; //取栈顶元素 
        Pop(Ls);     //出栈 
    }
}