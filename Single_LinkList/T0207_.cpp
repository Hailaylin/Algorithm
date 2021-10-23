/*
 * @Description: 链表逆转
 * @Author: HailayLin
 * @Date: 2021-10-23 14:40:36
 * @LastEditTime: 2021-10-23 18:32:16
 * @FilePath: \Algorithm\Single_LinkList\T0207_.cpp
 */

/**
 * 题目内容：
在S0205的基础上修改程序。
设计一个算法，将链表中所有结点的链接方向 “原地” 逆转，即要求仅利用原表的存储空间，换句话说，要求算法的空间复杂度为 0(1)。
例（第2行为输入）：
empty!
1 2 3 4
1:1
2:2
3:3
4:4
After inversing:
1:4
2:3
3:2
4:1

 请注意，main()函数必须按如下所示编写：
int main()
{
    LinkList Lscore;
    InitList(Lscore); //初始化单链表 
    showList(Lscore); //单链表遍历 
    CreateList_R(Lscore,4); //后插法创建单链表 
    showList(Lscore);
    Inverse(Lscore); 
    cout<<"After inversing:"<<endl; 
    showList(Lscore); //单链表遍历
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

//单链表节点
typedef struct LNode
{
    /* data */
    ElemType data;
    /* 下一节点指针 */
    LNode *next;
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

//后插法创建列表
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
        LNode *p = new LNode;//要插入的新节点p
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

//获取元素
/**
 * @brief Get the Elem object
 * 
 * @param L 链表名称
 * @param i 第i个元素
 * @param e 成功获取的元素保存到e
 * @return Status 
 */
Status GetElem(LinkList &L, int i, ElemType &e)
{ 
    LNode *p = L->next;
    int j = 1;
    //移动游标p到i所在节点
    while(p && j<i) //直到扫描到空节点，或j=i时p指向最后一个节点
    {
        p = p->next;
        ++j;
    }
    //判断i范围是否合法：
    if (!p || j>i)  return ERROR;
    //获取元素
    e = p->data;
    return OK;
}

//定位元素
LNode *LocateElem(LinkList &L, ElemType &e)
{
    //一个一个元素判断
    LinkList p = L->next;
    while(p && p->data!=e)
        p = p->next;
    //没找到,返回现状指针NULL；找到则指向那个元素的地址
    return p;
}


//插入元素
LNode *ListInsert(LinkList &L, int i, ElemType e)
{
    //遍历到元素的前一个
    LinkList p = L;
    int j=0;
    while(p && (j++ < i-1))
        p = p->next;
    if (!p || j > i) return NULL;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return p;
}

//删除元素
LNode *ListDelete(LinkList L, int i)
{
    LinkList p=L;
    int j = 0;
    //移动节点到a(n-1)
    while( (p->next) && (j<i-1) )
    {
        p = p->next;
        ++j;
    }
    //判断删除位置是否合理
    if ( (!p->next) || (j>i-1)) return NULL;
    //进行删除操作
    LinkList q = p->next;
    p->next = q->next;
    delete q;
    return p;
}

Status Inverse(LinkList &L)
{
    LinkList head = L->next;
    LinkList p = L->next;
    LinkList p_pre = L;
    // 1. 找到最后的那个
    while(p->next)
    {
        p_pre = p_pre->next;
        p = p->next;
    }
    // 2. 逐个调到最后
    LinkList p_latest = L;
    while(head != p)
    {

        while(p->next)
        {
            p_pre = p_pre->next;
            p = p->next;
        }
    }
    return OK;
}

int main()
{
    LinkList Lscore;
    InitList(Lscore); //初始化单链表 
    showList(Lscore); //单链表遍历 
    CreateList_R(Lscore,4); //后插法创建单链表 
    showList(Lscore);
    Inverse(Lscore); 
    cout<<"After inversing:"<<endl; 
    showList(Lscore); //单链表遍历
    return 0;
} 