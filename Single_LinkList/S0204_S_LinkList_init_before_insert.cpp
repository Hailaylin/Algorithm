/**
 * @file S0204_S_LinkList_init_before_insert.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-08-11
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * 题号：S0204        题目:单链表的初始化、前插法、遍历        得分：0  
  
作业提交截止时间：2022/1/20 0:00:00	 
 	
题目内容：
练习单链表的初始化、前插法创建单链表、单链表遍历。
其中部分代码如图所示。
例（只有第2行为输入）：
empty!
wang li zhang du gao
1:gao
2:du
3:zhang
4:li
5:wang

 请注意，main()函数必须按如下所示编写：
int main()
{
    LinkList Lname;
    InitList(Lname); //初始化单链表 
    showList(Lname); //单链表遍历 
    CreateList_H(Lname,5); //前插法创建单链表 
    showList(Lname); //单链表遍历 
    return 0;
} 

 */

#include<iostream>
#include<string>
using namespace std;

#define OK 1
#define ERROR 0

typedef string ElemType;
typedef int Status;

//单链表
typedef struct tarLNode
{
    /* data */
    ElemType data;
    /* 下一节点指针 */
    tarLNode *next;
}LNode, *LinkList;

//初始化
Status InitList(LinkList &L)
{
    //1.生成空节点(头结点)
    L = new LNode;
    //2.空指针,返回值
    L->next = NULL;
    return OK;
} 

//遍历
Status showList(LinkList &L)
{
    //循环输出
    LNode *p = L;
    int i = 1;
    //空链表
    if (L->next == NULL)
    {
        printf("empty!\n");
        return ERROR;
    }
    //非空链表输出
    p = L->next;    //给首元结点
    while( p != NULL )
    {
        cout << i << ":" << p->data << endl;
        i++;
        p = p->next;
    }
    return OK;
}

//单链表插入
Status CreateList_H(LinkList &L, int num)
{
    //生成空链表
    L = new LNode;
    L->next = NULL;
    //依序插入
    for (int i=1; i<=num; i++)
    {
        LNode *p = new LNode;
        string name;
        cin >> name;
        p->data = name;
        //插入到头结点后
        //不能将 "LNode *" 类型的值分配到 "LNote *" 类型的实体
        //解决:struct LNode *next; 这一行不要struct
        //参考 https://blog.csdn.net/a838771230/article/details/80839716
        p->next = L->next;      //精华下两行,把L->next的NULL给了元素next指针
        L->next = p;            //把元素地址给链表头结点的next指针
    }
    return OK;
}

int main()
{
    LinkList Lname;
    InitList(Lname); //初始化单链表 
    showList(Lname); //单链表遍历 
    CreateList_H(Lname,5); //前插法创建单链表 
    showList(Lname); //单链表遍历 
    return 0;
} 

/*
提交报错,杜哥的编译器太老了,把nullptr ctrl+h换成NULL就行
D:\ExamOnLine\student\datastructure\s202030701\S0204\S0204.cpp: In function 'Status InitList(tarLNode*&)':
D:\ExamOnLine\student\datastructure\s202030701\S0204\S0204.cpp:26:15: error: 'nullptr' was not declared in this scope
     L->next = nullptr;
               ^
D:\ExamOnLine\student\datastructure\s202030701\S0204\S0204.cpp: In function 'Status showList(tarLNode*&)':
D:\ExamOnLine\student\datastructure\s202030701\S0204\S0204.cpp:37:20: error: 'nullptr' was not declared in this scope
     if (L->next == nullptr)
                    ^
D:\ExamOnLine\student\datastructure\s202030701\S0204\S0204.cpp:44:17: error: 'nullptr' was not declared in this scope
     while( p != nullptr )
                 ^
D:\ExamOnLine\student\datastructure\s202030701\S0204\S0204.cpp: In function 'Status CreateList_H(tarLNode*&, int)':
D:\ExamOnLine\student\datastructure\s202030701\S0204\S0204.cpp:58:15: error: 'nullptr' was not declared in this scope
     L->next = nullptr;
               ^

*/