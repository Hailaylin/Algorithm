/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-11-29 09:43:48
 * @LastEditTime: 2021-12-06 16:17:30
 * @FilePath: \Algorithm\kaoshi\1erChaLianBiao.cc
 */
#include<iostream>
using namespace std;

typedef struct BiNode{
    char data;
    BiNode * lchild, * rchild;
}BiNode, *BiTree;

void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if(ch=='#') T = NULL;
    else {
        // 赋值
        T = new BiNode;
        T->data = ch;
        // 遍历创建
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T)
{
    if(T)
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