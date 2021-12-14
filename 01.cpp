/*
 * @Description: 

 * @Author: HailayLin
 * @Date: 2021-12-14 17:13:09
 * @LastEditTime: 2021-12-14 20:07:33
 * @FilePath: \Algorithm\01.cpp
 */
/*
创建二叉树，统计叶结点个数。
例1（第1行为输入）：
A#B##
1
例2（第1行为输入）：
ABC##D###
2
请注意，main()函数或函数调用必须按如下所示编写：
int main()
{
BiTree T;
CreateBiTree(T); //先序遍历顺序创建二叉树
cout<<LeafNode(T)<<endl; //统计二叉树的叶结点个数
return 0;
}

A#B##
1

ABC##D##
2
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct BiNode {
	char data;
	BiNode *lchild;
	BiNode *rchild;
}BiNode, *BiTree;

void CreateBiTree(BiTree &T) {
	char ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
		return ;
	}
	T = new BiNode;
	T->data = ch;
	CreateBiTree(T->lchild);
	CreateBiTree(T->rchild);
	return ;
}


void Show(BiTree T) {
	while(T!=NULL) {
		cout << T->data;
	}
	cout << endl;
}

// // 自己考试的时候写的
// int LeafNode(BiTree &T) {
// 	if (T->lchild->data == '#' && T->rchild->data == '#') {
// 		return 1;	// BUG 对树空的判断有误，要用空指针判断；
// 	}				// BUG 递归理解不深；生成的树理解不深
// 	else if (T == NULL) return 0;
// 	else {
// 		return (LeafNode(T->lchild) + LeafNode(T->rchild));
// 	}
// }

// 叶子结点个数
int LeafNode(BiTree &T)
{
    if(T == NULL) return 0; // 树空返回0
    if(T->lchild == NULL && T->rchild == NULL) return 1; // 是叶子结点就+1
    else return LeafNode(T->lchild)+LeafNode(T->rchild);
}

int main()
{
	BiTree T;
	CreateBiTree(T); //先序遍历顺序创建二叉树 
	//Show(T);
	cout<<LeafNode(T)<<endl; //统计二叉树的叶结点个数
	return 0;
}
