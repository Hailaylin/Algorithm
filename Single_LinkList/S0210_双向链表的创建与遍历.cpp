/*
 * @Description: 双向链表的创建与遍历
 * @Author: HailayLin
 * @Date: 2021-10-04 19:17:19
 * @LastEditTime: 2021-10-04 20:11:37
 * @FilePath: \Algorithm\Single_LinkList\S0210_双向链表的创建与遍历.cpp
 */

/**
 * @brief 题目内容：
使用前插法创建双向链表并进行遍历，部分代码如图所示。
例1（第1行为输入）：
99 78 88 33
1:33
2:88
3:78
4:99



 请注意，main()函数必须按如下所示编写：
int main()
{
    DuLinkList L;
    InitDuLNode(L); //初始化双向链表 
    CreateDuL_H(L,4); //前插法创建双向链表 
    show(L); //遍历双向链表 
    return 0;
}
 * 
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
    L->data = n;
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