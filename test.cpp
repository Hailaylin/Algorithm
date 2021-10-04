/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-09-29 18:44:24
 * @LastEditTime: 2021-10-04 20:09:10
 * @FilePath: \Algorithm\test.cpp
 */
#include<iostream>
#include<string>
using namespace std;

#define OK 1
#define ERROR 0

typedef string ElemType;
typedef int Status;

/**
 * @brief 双向链表
 * 沿用以前单链表名字
 */
typedef struct tarLNode
{
    ElemType data;       //数据域
    tarLNode *prior;     //直接前驱
    tarLNode *next;      //直接后继
}DuLNode, *DuLinkList;

//初始化双向链表
Status InitDuLNode(DuLinkList &L)
{
    //生成空节点
    L = new DuLNode;
    //直接前驱和后继为空
    L->prior = NULL;
    L->next = NULL;
    //返回ok
    return OK;
}

//前插法创建双向链表
Status CreateDuL_H(DuLinkList &L, int n)
{
    DuLinkList p = L;
    for (int i=0; i<n; i++)
    {
        DuLinkList q = new DuLNode;
        cin >> q->data;
        q->next = p->next;
        p->next = q;
        q->prior = p;
        if (q->next) q->next->prior = q;
    }
    return OK;
}

//遍历双向链表
Status show(DuLinkList &L)
{
    DuLinkList p = L->next;
    int i = 1;
    while (p)
    {
        cout << i << ":" << p->data << endl;
        ++i;
        p = p->next;
    }
    return OK;
}


int main()
{
    DuLinkList L;
    InitDuLNode(L); //初始化双向链表 
    CreateDuL_H(L,4); //前插法创建双向链表 
    show(L); //遍历双向链表 
    return 0;
}