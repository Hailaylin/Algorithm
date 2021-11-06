/*
 * @Description: Sequence in threaded binary tree
 * @Author: HailayLin
 * @Date: 2021-11-01 11:32:15
 * @LastEditTime: 2021-11-01 21:19:14
 * @FilePath: \Algorithm\BiTree\S0503_SequenceThreadedBinaryTree.cc
 */
/**
 * 题号：S0503        题目:中序线索二叉树        得分：0  
  
作业提交截止时间：2022/1/20 0:00:00	 
 	
题目内容：
在S0502的基础修改程序，中序线索化二叉树并遍历。

例（第1行为输入）：
ABC##D##G##
CBDAG

 请注意，main()函数必须按如下所示编写：
int main()
{
    BiThrTree T;
    CreateBiThrTree(T);//先序遍历顺序建立二叉链表 
    InThreading(T); //不带头结点的中序线索化 
    InOrderTraverse_Thr(T); //遍历中序线索二叉树 
        
    return 0;
}
*/

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0 
typedef char TElemType;
// 创建节点
typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    unsigned char LTag, RTag;
}BiThrNode, *BiThrTree;

//先序遍历顺序建立二叉链表
void CreateBiThrTree(BiThrTree &T)
{
    char ch;
    cin >> ch;
    if (ch=='#') T = NULL;
    else {
        T = new BiThrNode;
        T->data = ch;
        CreateBiThrTree(T->lchild);
        CreateBiThrTree(T->rchild);
    }
}

BiThrTree pre = NULL;
//不带头结点的中序线索化 
void InThreading(BiThrTree &T)
{
    if(T)
    {
        InThreading(T->lchild);
        if(T->lchild == NULL)
        {
            T->LTag = 1;
            T->lchild = pre;
        }
        if(pre->rchild == NULL)
        {
            pre->RTag = 1;
            pre->rchild = T;
        }
        pre = T;
        InThreading(T->rchild);
    }
}

//遍历中序线索二叉树 
void InOrderTraverse_Thr(BiThrTree &T)
{
    
}

int main()
{
    BiThrTree T;
    CreateBiThrTree(T);//先序遍历顺序建立二叉链表 
    InThreading(T); //不带头结点的中序线索化 
    InOrderTraverse_Thr(T); //遍历中序线索二叉树 
        
    return 0;
}