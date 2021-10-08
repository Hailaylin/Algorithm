/*
 * @Description: 双向链表的删除
 * @Author: HailayLin
 * @Date: 2021-10-08 21:06:04
 * @LastEditTime: 2021-10-08 22:14:29
 * @FilePath: \Algorithm\Single_LinkList\S02212_双向链表的删除.cpp
 */

/**
 * @brief 题目内容：
在S0210的基础上修改程序，完成双向链表的删除。
注意删除最后一个结点时的操作。
例1（第1、7行为输入）：
9 8 7 4
1:4
2:7
3:8
4:9
Please input the location you want to delete:
1
Delete success!
1:7
2:8
3:9

例2（第1、7行为输入）：
9 8 7 6
1:6
2:7
3:8
4:9
Please input the location you want to delete:
5
Delete Error!
1:6
2:7
3:8
4:9

 请注意，main()函数必须按如下所示编写：
int main()
{
    DuLinkList L;
    InitDuLNode(L); //初始化双向链表 
    CreateDuL_H(L,4); //后插法创建双向链表 
    show(L); //遍历双向链表 
    int i;
    cout<<"Please input the location you want to delete:"<<endl;
    cin>>i;
    if(ListDelete_DuL(L,i)==OK)
        cout<<"Delete success!"<<endl;
    else 
        cout<<"Delete Error!"<<endl;
    show(L);
    return 0;
}
 * 
 */

#include<iostream>
#include<string>
using namespace std;

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

/**
 * @brief 双向链表
 * 沿用以前单链表名字
 */
typedef struct DuLNode
{
    DuLNode *prior;     //直接前驱
    ElemType data;       //数据域
    DuLNode *next;      //直接后继
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

//双向链表插入
Status ListInsert_DuL(DuLinkList &L, int i, ElemType &e)
{
    DuLinkList p = L->next;
    int j = 1;
    //移动p指向要插入元素的后一个元素
    while (p && j<i)
    {
        p=p->next;
        ++j;
    }
    if (!p || j>i) return ERROR;
    //插入操作
    DuLinkList s = new DuLNode;
    s->data = e;
    s->prior = p->prior;
    s->next = p;
    p->prior->next = s;
    p->prior = s;
    return OK;
}

//双向链表删除节点
Status ListDelete_DuL(DuLinkList &L, int i)
{
    int j=1;
    DuLinkList p=L->next;
    //查找节点
    while( p && j < i )
    {
        p = p->next;
        j++;
    }
    if ( NULL == p || j>i ) return ERROR;
    //删除节点操作注意尾结点
    if (p->next != NULL)
    {
        p->prior->next = p->next;
        p->next->prior = p->prior;
    }
    else p->prior->next = NULL;
    delete p;
    return OK;
}

int main()
{
    DuLinkList L;
    InitDuLNode(L); //初始化双向链表 
    CreateDuL_H(L,4); //后插法创建双向链表 
    show(L); //遍历双向链表 
    int i;
    cout<<"Please input the location you want to delete:"<<endl;
    cin>>i;
    if(ListDelete_DuL(L,i)==OK)
        cout<<"Delete success!"<<endl;
    else 
        cout<<"Delete Error!"<<endl;
    show(L);
    return 0;
}