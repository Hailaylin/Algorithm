/*
 * @Description:
 * @Author: HailayLin
 * @Date: 2021-12-14 17:13:09
 * @LastEditTime: 2021-12-14 20:10:36
 * @FilePath: \Algorithm\03 SingleList.cpp
 */
/**
Beijing Tianjin Shanghai Chongqing Tangshan
*/

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

typedef int Status;
typedef string ElemType;
#define OK 1
#define ERROR 0

typedef struct LNode {
	ElemType data;
	LNode *next;
}LNode, *LinkList;

Status InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}

Status showList(LinkList L) {
	if(L->next == NULL) {
		cout << "empty!" << endl;
		return ERROR;
	}
	else {
		LinkList p = L->next;
		int i = 1;
		while (p != NULL) {
			cout << i++ << ":" << p->data << endl;
			p = p->next;
		}
	}
	return OK;
}


Status CreateList_R(LinkList &L, int num) {
	LinkList p = L;
	string str;
	for (int i=0; i<num; i++) {
		cin >> str;
		//cout << str << endl;
		LNode *s = new LNode;
		s->data = str;
		s->next = NULL;
		p->next = s;
		p = s;
	}
	return OK;
}

int main()
{
    LinkList Lname;
    InitList(Lname); //初始化单链表 
    showList(Lname); //单链表遍历 
    CreateList_R(Lname,5); //后插法创建单链表 
    showList(Lname); //单链表遍历 
    return 0;
} 
