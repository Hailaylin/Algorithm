/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-11-01 11:23:44
 * @LastEditTime: 2021-11-01 11:29:53
 * @FilePath: \Algorithm\BiTree\S0502_BiTree_copy_deepth.cc
 */

/**
题目内容：
在S0501的基础上修改程序，完成复制二叉树、计算二叉树深度、计算二叉树中结点个数的功能。
例（第1行为输入）：
AB#CD##E##F#GH###
DECBHGFA
4
8
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
int LeaveNodeCount(BiTree &T)
{
    if(T == NULL) return 0; // 树空返回0
    if(T->lchild == NULL && T->rchild == NULL) return 1; // 是叶子结点就+1
    else return LeaveNodeCount(T->lchild)+LeaveNodeCount(T->rchild);
}

// 二叉树复制
void Copy(BiTree &T, BiTree &newT)
{
    if (T == NULL){
        newT = NULL;
        return;
    }
    else {
        newT = new BiTNode;
        newT->data = T->data;
        Copy(T->lchild, newT->lchild);
        Copy(T->rchild, newT->rchild);
    }
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
    BiTree T,S;
    CreateBiTree(T);//先序遍历顺序建立二叉链表 
    Copy(T,S);
    PostOrderTraverse(S); cout<<endl;//后序遍历
    cout<<Depth(S)<<endl; //计算二叉树深度
    cout<<NodeCount(S)<<endl; //计算二叉树中结点个数
        
    return 0;
}