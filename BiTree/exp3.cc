/*
 * @Description: 实验3 先序遍历创建二叉树
 * @Author: HailayLin
 * @Date: 2021-11-01 10:27:52
 * @LastEditTime: 2021-11-01 11:16:43
 * @FilePath: \Algorithm\exp3.cc
 */
/**
 * 测试用例
 * 1. ABC##DE#G##F###，节点7，深度5，叶子节点3
 * 2. AB#CD##E##F#GH###，节点数8，深度4，叶子结点3
 * */

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

// 先序遍历创建二叉树
void CreateBiTree(BiTree &T)
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

// 获取树深度
int Depth(BiTree &T)
{
    int m=0, n=0;
    if(T == NULL) return 0;
    else {
        m = Depth(T->lchild);   // 左子树深度
        n = Depth(T->rchild);   // 右子树深度
        if(m>n) return (m+1);   // 选择最深的那一边+1
        else return(n+1);
    }
}

// 二叉树节点个数
int NodeCount(BiTree &T)
{
    if(T == NULL) return 0;
    else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;    // 左子树个数+右子树+1
}

// 叶子结点个数
int LeafNode(BiTree &T)
{
    if(T == NULL) return 0; // 树空返回0
    if(T->lchild == NULL && T->rchild == NULL) return 1; // 是叶子结点就+1
    else return LeafNode(T->lchild)+LeafNode(T->rchild);
}

// 选择输出菜单
void SwitchShow(BiTree &T)
{
    int n;
    do {
    cout << "0退出，1先序遍历，2中序遍历，3后序遍历:";
    cin >> n;
        switch (n)
        {
        case 1:
            cout << "前序遍历输出:" << endl; 
            PreOrderTraverse(T); cout<<endl;//先序遍历
            break;
        case 2:
            cout << "中序遍历输出:" << endl; 
            InOrderTraverse(T); cout<<endl;//中序遍历
            break;
        case 3:
            cout << "后序遍历输出:" << endl; 
            PostOrderTraverse(T); cout<<endl;//后序遍历
            break;
        case 0:
            break;
        default:
            cout << "您的输入有误，请重新输入." << endl;
            break;
        }
    }while(n!=0);
}

int main()
{
    BiTree T;
    CreateBiTree(T); //先序遍历顺序创建二叉树 
    cout<<LeafNode(T)<<endl; //统计二叉树的叶结点个数
    return 0;
}