/*
 * @Description: 实验3 先序遍历创建二叉树
 * @Author: HailayLin
 * @Date: 2021-11-01 10:27:52
 * @LastEditTime: 2021-11-01 10:41:45
 * @FilePath: \Algorithm\exp3.cc
 */

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0 
typedef int Status;
typedef char TElemType;
// 创建节点
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 二叉树节点个数
int node_num = 0;

// 先序遍历创建二叉树
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch=='#') T = NULL;
    else {
        T = new BiTNode;
        T->data = ch;
        node_num++;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

// 前序遍历
void PreOrderTraverse(BiTree &T)
{
    if (T){
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// 中序遍历
void InOrderTraverse(BiTree &T)
{
    if (T){
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

// 后序遍历
void PostOrderTraverse(BiTree &T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}

int Depth(BiTree &T)
{
    int m=0, n=0;
    if(T == NULL) return 0;
    else {
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        if(m>n) return (m+1);
        else return(n+1);
    }
}

int main()
{
    BiTree T;
    CreateBiTree(T);//先序遍历顺序建立二叉链表
    cout << "前序遍历输出:" << endl; 
    PreOrderTraverse(T); cout<<endl;//先序遍历
    cout << "中序遍历输出:" << endl; 
    InOrderTraverse(T); cout<<endl;//中序遍历
    cout << "后序遍历输出:" << endl; 
    PostOrderTraverse(T); cout<<endl;//后序遍历
    cout << "二叉树节点个数:" << node_num << endl;
    cout << "二叉树深度个数:" << Depth(T) << endl;
    
    return 0;
}