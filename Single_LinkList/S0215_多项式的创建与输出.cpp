/*
 * @Description: S0215_多项式的创建与输出
 * @Author: HailayLin
 * @Date: 2021-10-17 15:59:39
 * @LastEditTime: 2021-10-17 16:35:54
 * @FilePath: \Algorithm\Single_LinkList\S0215_多项式的创建与输出.cpp
 */
/**
 * 	题号：S0215        题目:多项式创建与输出        得分：0  
  
作业提交截止时间：2022/1/20 0:00:00	 
 	
题目内容：
用链表实现多项式的创建与输出，基本数据类型如下所示：
typedef struct PNode
{
    float coef;//系数
    int expn; //指数
    struct PNode *next; //指针域
}PNode,*Polynomial;

注：此题只考虑系数大于0、指数大于或者等于0的情况。
考虑：如果系数与指数都可为负时，程序应该如何修改？

例（第2、4行为输入）：
Empty!
2.2 3 5.5 1 9.98 0
f(x)=9.98+5.5*x+2.2*x^3
6.66 9 8.87 1 7.78 2 3.44 12
f(x)=8.87*x+7.78*x^2+6.66*x^9+3.44*x^12

 请注意，main()函数必须按如下所示编写：
int main()
{
    Polynomial pa=NULL,pb=NULL;
    show(pa);
    CreatePolyn(pa,3);
    show(pa);
    CreatePolyn(pb,4);
    show(pb);
    return 0;
}
*/


#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
typedef int Status;

// 每一项的节点
typedef struct PNode
{
    float coef;//系数
    int expn; //指数
    struct PNode *next; //指针域
}PNode,*Polynomial;

Status CreatePolyn(Polynomial &P, int n)
{
    // 0. 初始化
    P = new PNode;
    P->next = NULL;
    Polynomial q, pre;
    for(int i=0; i<n; i++)
    {
        // 1. 输入项的系数和指数
        float coef = 0.0;
        int expn = 0;
        cin >> coef >> expn;
        Polynomial s = new PNode;
        s->coef = coef;
        s->expn = expn;

        // 2. 找到该项的合适位置插入，考虑空、最后插入的情况
        q = P->next;    // 初始化指向首元结点，用它来找
        pre = P;        // 前一个节点
        while(q && )
    }
    

}

int main()
{
    Polynomial pa=NULL,pb=NULL;
    show(pa);
    CreatePolyn(pa,3);
    show(pa);
    CreatePolyn(pb,4);
    show(pb);
    return 0;
}