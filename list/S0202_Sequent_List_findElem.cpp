/**
 * @file S0202_Sequent_List_findElem.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-08-10
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * 题号：S0202        题目:线性表查找        得分：0  
  
作业提交截止时间：2022/1/20 0:00:00	 
 	
题目内容：
在S0201的基础上添加线性表中元素查找的功能。
例（前两行为输入）：
90 88 95
88
Loc:2
 请注意，main()函数必须按如下所示编写：
int main()
{
    //线性表的的初始化、插入、取值
    Sqlist Lscore; //用来存储学生《数据结构》成绩
    InitList(Lscore); //初始化线性表 
    int i,s;
    for(i=1; i<=3; i++) //输入3个学生成绩，添加到线性表中 
    {
        cin>>s;
        ListInsert(Lscore,i,s); //线性表中添加数据 
    } 
    
    int ls;
    cin>>ls; //输入要查找的成绩 
    //在线性表中查找，返回元素序号，若找不到返回0 
    int loc=LocateElem(Lscore,ls);
    if(loc==0) cout<<"Not found!"<<endl;
    else cout<<"Loc:"<<loc<<endl;
    
    return 0;
}
 */
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

#define MAXSIZE 100

/*   线性表的顺序表示(顺序表)   */
typedef struct
{
    ElemType *elem;     //元素储存空间基地址
    int length;         //元素个数
}Sqlist;

/*    初始化顺序表    */
Status InitList(Sqlist &L)
{
    L.elem = new ElemType[MAXSIZE]; //生成元素类型数组
    if(!L.elem) exit(OVERFLOW);     //判断生成成功/失败
    L.length = 0;                   //初始化线性表长度
    return OK;                      //返回生成成功
}

/*    顺序表插入元素    */
Status ListInsert(Sqlist &L, int i, ElemType e)
{
    if ( (i<1) || (i>L.length+1) ) return ERROR;//判断i地址是否非法
    if ( L.length == MAXSIZE) return ERROR;     //判断列表是否已满
    //移动,插入,表长+1
    for (int j=L.length-1; j>=i-1; j--)
    {
        L.elem[j+1] = L.elem[j];                //从后往前移
    }
    L.elem[i-1] = e;
    ++L.length;
    return OK;
}

/*    顺序表取值    */
Status GetElem(Sqlist &L, int i, ElemType &e)
{
    //1.判断地址非法
    //2.获取值
    if ( (i<1) || (i>L.length) ) return ERROR;
    e = L.elem[i-1];
    return OK;
}

/*    查找元素返回元素序号    */
int LocateElem(Sqlist &L, ElemType e)
{
    for (int i = 1; i <= L.length; i++)  //i=元素序号
    {
        if (e == L.elem[i-1]) return i;
    }
    return ERROR;
}

int main()
{
    //线性表的的初始化、插入、取值
    Sqlist Lscore; //用来存储学生《数据结构》成绩
    InitList(Lscore); //初始化线性表 
    int i,s;
    for(i=1; i<=3; i++) //输入3个学生成绩，添加到线性表中 
    {
        cin>>s;
        ListInsert(Lscore,i,s); //线性表中添加数据 
    } 
    
    int ls;
    cin>>ls; //输入要查找的成绩 
    //在线性表中查找，返回元素序号，若找不到返回0 
    int loc=LocateElem(Lscore,ls);
    if(loc==0) cout<<"Not found!"<<endl;
    else cout<<"Loc:"<<loc<<endl;
    
    return 0;
}