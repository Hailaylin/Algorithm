/*
 * @Description: 

 * @Author: HailayLin
 * @Date: 2021-12-14 17:13:09
 * @LastEditTime: 2021-12-14 17:15:14
 * @FilePath: \Algorithm\01.cpp
 */
/*
������������ͳ��Ҷ��������
��1����1��Ϊ���룩��
A#B##
1
��2����1��Ϊ���룩��
ABC##D###
2
��ע�⣬main()�����������ñ��밴������ʾ��д��
int main()
{
BiTree T;
CreateBiTree(T); //�������˳�򴴽�������
cout<<LeafNode(T)<<endl; //ͳ�ƶ�������Ҷ������
return 0;
}

A#B##
1

ABC##D##
2
*/


#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

typedef int Status;
#define OK 1
#define ERROE 0

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

// int LeafNode(BiTree T) {
// 	if (T->lchild->data == '#' && T->rchild->data == '#') {
// 		return 1;
// 	}
// 	else if (T == NULL) return 0;
// 	else {
// 		return (LeafNode(T->lchild) + LeafNode(T->rchild));
// 	}
// }

// Ҷ�ӽ�����
int LeafNode(BiTree &T)
{
    if(T == NULL) return 0; // ���շ���0
    if(T->lchild == NULL && T->rchild == NULL) return 1; // ��Ҷ�ӽ���+1
    else return LeafNode(T->lchild)+LeafNode(T->rchild);
}

int main()
{
	BiTree T;
	CreateBiTree(T); //�������˳�򴴽������� 
	//Show(T);
	cout<<LeafNode(T)<<endl; //ͳ�ƶ�������Ҷ������
	return 0;
}
