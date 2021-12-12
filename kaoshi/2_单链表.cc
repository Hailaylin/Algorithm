/*
 * @Description: 单链表创建、插入编写
 * @Author: HailayLin
 * @Date: 2021-12-06 16:26:20
 * @LastEditTime: 2021-12-12 15:25:42
 * @FilePath: \Algorithm\kaoshi\2_单链表.cc
 */

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct LNode{
    // 数据域
    ElemType data;
    // 指针域
    LNode *next;
}LNode, *LinkList;

Status InitList(LinkList &L)
{
    L = new LNode;
    L->data = 0;
    L->next = NULL;
    return OK;
}

// 前插法建立单链表
Status CreateList_H(LinkList &L, int n)
{
    char str;
    for (int i=0; i<n; i++)
    {
        // 赋值
        cin >> str;
        LNode *p = new LNode;
        if(!p) return ERROR;
        p->data = str;

        // 前插
        p->next = L->next;
        L->next = p;
    }
    return OK;
}


Status Show(LinkList L)
{
    LNode *p = L->next;
    while(p)
    {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
    return OK;
}

int main()
{
    LinkList L;
    InitList(L);
    CreateList_H(L, 5);
    Show(L);
}