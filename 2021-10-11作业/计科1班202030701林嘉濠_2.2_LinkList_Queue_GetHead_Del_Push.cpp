/*
 * @Description: S0306 链队
 * @Author: HailayLin
 * @Date: 2021-10-11 15:42:53
 * @LastEditTime: 2021-10-11 19:56:42
 * @FilePath: \Algorithm\2021-10-11作业\计科1班202030701林嘉濠_2.2_LinkList_Queue_GetHead_Del_Push.cpp
 */

/**
 * @brief 题目内容：
练习链队的程序。
例（第1行为输入）：
2.2 3.3 4.4 5.5 6.6
2.2
Dequeue:2.2
Dequeue:3.3
Dequeue:4.4
Dequeue:5.5
Dequeue:6.6
Queue empty!

 请注意，main()函数必须按如下所示编写：
int main()
{
    LinkQueue lq;
    InitQueue(lq); //初始化链队 
    QElemType s;
    int i;
    for(i=0; i<5; i++)
    {
        cin>>s;
        EnQueue(lq,s); //入队 
    }
    cout<<GetHead(lq)<<endl; //取队头元素 
    DeQueue(lq,s); //出队 
    cout<<"Dequeue:"<<s<<endl;
    for(i=0;i<5;i++)
    {
        if(DeQueue(lq,s)) cout<<"Dequeue:"<<s<<endl;
        else cout<<"Queue empty!"<<endl;
    }
        
    return 0;
}
 * 
 */

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
typedef int Status;
typedef double QElemType;

/**
 * @brief 链队节点，就是一个普通的单链表
 * 
 */
typedef struct QNode
{
    // 数据域
    QElemType data;
    // 指针域
    struct QNode * next; 
}QNode, *QueuePtr;

/**
 * @brief 链队指针
 * 
 */
typedef struct 
{
    QueuePtr front; //队头指针，始终指向头结点（空节点）
    QueuePtr rear;  //队尾指针
}LinkQueue;

/**
 * @brief 初始化链队：一个头结点的空队
 * 
 * @param Q 链队名
 * @return Status 
 */
Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
    return OK;
}

/**
 * @brief 链队入队
 * 
 * @param Q 链队名
 * @param e 入队元素
 * @return Status 
 */
Status EnQueue(LinkQueue &Q, QElemType &e)
{
    //1. 创建链队节点，节点数据域赋值
    QueuePtr p = new QNode;
    p->data = e;

    //2. 在末尾插入链队节点，rear尾指针移动到新增的节点上
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

/**
 * @brief Get the Head object
 * 
 * @param Q 链队名
 * @return QElemType 
 */
QElemType GetHead(LinkQueue &Q)
{
    return Q.front->next->data;
}

/**
 * @brief delete the Queue head element (头元素出队)
 * 
 * @param Q 链队名
 * @param s 返回出队的头元素值
 * @return Status 为了和课本一致，返回状态而不返回值
 */
Status DeQueue(LinkQueue &Q, QElemType &s)
{
    //0. 判断链队是否为空
    if (Q.front == Q.rear) return ERROR;
    //1. p指针指向首元结点(head node)
    QueuePtr p = Q.front->next;
    //2. front 空节点连上被删除节点的下一个
    Q.front->next = p->next;
    //3. [重点！] 如果最后一个元素被删，则rear指向front
    if (Q.rear == p) Q.rear = Q.front;
    //4. 获取head的data值, 释放p
    s = p->data;
    delete p;
    return OK;
}

int main()
{
    LinkQueue lq;
    InitQueue(lq); //初始化链队 
    QElemType s;
    int i;
    int n;
    cout << "输入n个元素入队:" << endl;
    cin >> n;
    cout << "请输入" << n << "个元素:" << endl;
    for(i=0; i<n; i++)
    {
        cin>>s;
        EnQueue(lq,s); //入队 
    }
    cout << "获取头元素:" <<GetHead(lq)<<endl; //取队头元素 
    cout << "先出队一个:" << endl;
    DeQueue(lq,s); //出队 
    cout<<"Dequeue:"<<s<<endl;
    cout << "剩下的出队:" << endl;
    for(i=0;i<n;i++)
    {
        if(DeQueue(lq,s)) cout<<"Dequeue:"<<s<<endl;
        else cout<<"Queue empty!"<<endl;
    }
        
    return 0;
}