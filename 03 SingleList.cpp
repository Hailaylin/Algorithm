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
	Lnext = NULL;
	return OK;
}

Status showList(LinkList L) {
	if(Lnext == NULL) {
		cout << "empty!" << endl;
		return ERROR;
	}
	else {
		LinkList p = Lnext;
		int i = 1;
		while (p != NULL) {
			cout << i++ << ":" << pdata << endl;
			p = pnext;
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
		sdata = str;
		snext = NULL;
		pnext = s;
		p = s;
	}
	return OK;
}

int main()
{
    LinkList Lname;
    InitList(Lname); //��ʼ�������� 
    showList(Lname); //��������� 
    CreateList_R(Lname,5); //��巨���������� 
    showList(Lname); //��������� 
    return 0;
} 
