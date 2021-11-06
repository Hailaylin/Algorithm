/*
 * @Description: 二叉树创建
 * @Author: HailayLin
 * @Date: 2021-10-29 14:38:53
 * @LastEditTime: 2021-10-29 15:17:38
 * @FilePath: \Python\tree\S0501_先序遍历创建二叉链.cpp
 */
/*
题目内容：
用先序遍历顺序创建二叉链表，并先序、中序、后序遍历二叉链表。
部分代码如图所示。

例1（第1 行为输入）：
ABC##DE#G##F###
ABCDEGF
CBEGDFA
CGEFDBA


 请注意，main()函数必须按如下所示编写：
int main()
{
    BiTree T;
    CreateBiTree(T);//先序遍历顺序建立二叉链表 
    PreOrderTraverse(T); cout<<endl;//先序遍历 
    InOrderTraverse(T); cout<<endl;//中序遍历 
    PostOrderTraverse(T); cout<<endl;//后序遍历
    
    return 0;
}
*/
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0 
typedef int Status;
typedef char TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch=='#') T = NULL;
    else {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

// 前序遍历
Status PreOrderTraverse(BiTree &T)
{
    if (T){
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// 中序遍历
Status InOrderTraverse(BiTree &T)
{
    if (T){
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

// 后序遍历
Status PostOrderTraverse(BiTree &T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}

int main()
{
    BiTree T;
    CreateBiTree(T);//先序遍历顺序建立二叉链表 
    PreOrderTraverse(T); cout<<endl;//先序遍历 
    InOrderTraverse(T); cout<<endl;//中序遍历 
    PostOrderTraverse(T); cout<<endl;//后序遍历
    
    return 0;
}