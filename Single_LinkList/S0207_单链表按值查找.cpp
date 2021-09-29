/*
 * @Description: 题目:单链表按值查找
 * @Author: HailayLin
 * @Date: 2021-09-29 18:10:58
 * @LastEditTime: 2021-09-29 18:21:42
 * @FilePath: \Algorithm\Single_LinkList\S0207_单链表按值查找.cpp
 */
/**
 * 题号：S0207        题目:单链表按值查找        得分：0  
  
作业提交截止时间：2022/1/20 0:00:00	 
 	
题目内容：
在S0206的基础上修改程序，完成单链表按值查找的功能。
例1（第1、5行为输入）：
wang li zhao
1:wang
2:li
3:zhao
zhao
Found!

例2（第1、5行为输入）：
gao li zhang
1:gao
2:li
3:zhang
wang
Not found!
 请注意，main()函数必须按如下所示编写：
int main()
{
    LinkList Lname;
    InitList(Lname); //初始化单链表 
    CreateList_R(Lname,3); //后插法创建单链表 
    showList(Lname); //单链表遍历 
    string s;
    cin>>s;
    if(LocateElem(Lname,s)!=NULL) cout<<"Found!"<<endl;
    else cout<<"Not found!"<<endl;
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
Status GetElem(LinkList &L, int i, ElemType &e)
{ 
    LNode *p = L;
    int j = 0;
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

int main()
{
    LinkList Lname;
    InitList(Lname); //初始化单链表 
    CreateList_R(Lname,3); //后插法创建单链表 
    showList(Lname); //单链表遍历 
    string s;
    cin>>s;
    if(LocateElem(Lname,s)!=NULL) cout<<"Found!"<<endl;
    else cout<<"Not found!"<<endl;
    return 0;
} 