/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-10-04 20:14:07
 * @LastEditTime: 2021-10-04 20:28:04
 * @FilePath: \Algorithm\Single_LinkList\S0211_双向链表插入.cpp
 */

/**
 * @brief 题目内容：
在S0210的基础上修改程序，在第i个位置之前插入元素。
例1（1、7行为输入）：
4 3 2 1
1:1
2:2
3:3
4:4
Please input the location and number you want to insert:
2 9
Insert success!
1:1
2:9
3:2
4:3
5:4

例2（1、7行为输入）：
4 3 2 1
1:1
2:2
3:3
4:4
Please input the location and number you want to insert:
5 8
Insert Error!
1:1
2:2
3:3
4:4

 请注意，main()函数必须按如下所示编写：
int main()
{
    DuLinkList L;
    InitDuLNode(L); //初始化双向链表 
    CreateDuL_H(L,4); //后插法创建双向链表 
    show(L); //遍历双向链表 
    int i,s;
    cout<<"Please input the location and number you want to insert:"<<endl;
    cin>>i>>s;
    if(ListInsert_DuL(L,i,s)==OK)
        cout<<"Insert success!"<<endl;
    else 
        cout<<"Insert Error!"<<endl;
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

int main()
{
    DuLinkList L;
    InitDuLNode(L); //初始化双向链表 
    CreateDuL_H(L,4); //后插法创建双向链表 
    show(L); //遍历双向链表 
    int i,s;
    cout<<"Please input the location and number you want to insert:"<<endl;
    cin>>i>>s;
    if(ListInsert_DuL(L,i,s)==OK)
        cout<<"Insert success!"<<endl;
    else 
        cout<<"Insert Error!"<<endl;
    show(L);
    return 0;
}