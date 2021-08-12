/**
 * @file S0205_后插法创建单链表.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-08-12
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * 题号：S0205        题目:后插法创建单链表        得分：0  
  
作业提交截止时间：2022/1/20 0:00:00	 
 	
题目内容：
在S0204的基础上对程序进行修改，利用后插法创建单链表。
例（只有第2行为输入）：
empty!
Wang Li Gao Miao Long
1:Wang
2:Li
3:Gao
4:Miao
5:Long
 请注意，main()函数必须按如下所示编写：
int main()
{
    LinkList Lname;
    InitList(Lname); //初始化单链表 
    showList(Lname); //单链表遍历 
    CreateList_R(Lname,5); //后插法创建单链表 
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

Status CreateList_R(LinkList &L, int n)
{
    //生成空链表
    L = new LNode;
    L->next = NULL;
    // 前面先构造一个可移动的指针存前一个元素的地址
    LNode *s;
    s = L;
    //依序插入
    for (int i=1; i<=n; i++)
    {
        LNode *p = new LNode;
        string name;
        cin >> name;
        p->data = name;
        //插入到头结点后,剩下的插入到下一个节点后 （这个是自己写的，写前插的时候想的是后插写的是前插qaq😂）
        p->next = s->next;  //就改了下面三行代码 前面的nullptr当前生成的元素的后驱指针
        s->next = p;        //把当前元素的地址给前一个元素s的后驱指针
        s = p;              //把指向前一个元素的s变为指向当前元素
    }
    return OK;
}

int main()
{
    LinkList Lname;
    InitList(Lname); //初始化单链表 
    showList(Lname); //单链表遍历 
    CreateList_R(Lname,5); //后插法创建单链表 
    showList(Lname); //单链表遍历 
    return 0;
} 