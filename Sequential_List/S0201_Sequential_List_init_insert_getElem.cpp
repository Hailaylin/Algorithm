/**
 * @file S0201_题目_线性表的初始化,插入,取值.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-08-10
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * @题目内容：
利用线性表对学生的《数据结构》成绩进行管理。
其中的部分内容如下图所示。
例（第1行为输入）：
78 90
81
82
78
83
90
84
85
 请注意，main()函数必须按如下所示编写：
int main()
{
    //线性表的的初始化、插入、取值
    Sqlist Lscore; //用来存储学生《数据结构》成绩
    InitList(Lscore); //初始化线性表 
    int i;
    for(i=1; i<=5; i++)
    {
        ListInsert(Lscore,i,80+i); //线性表中添加数据 
    } 
    
    int s1,s2; //
    cin>>s1>>s2; //输入两个成绩 
    ListInsert(Lscore,3,s1);
    ListInsert(Lscore,5,s2);
    int len=Lscore.length;
    int s;
    for(i=1;i<=len;i++)
    {
        GetElem(Lscore,i,s); //获取线性表中数据 
        cout<<s<<endl;
    }
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

int main()
{
    //线性表的的初始化、插入、取值
    Sqlist Lscore; //用来存储学生《数据结构》成绩
    InitList(Lscore); //初始化线性表 
    int i;
    for(i=1; i<=5; i++)
    {
        ListInsert(Lscore,i,80+i); //线性表中添加数据 
    } 
    
    int s1,s2; //
    cin>>s1>>s2; //输入两个成绩 
    ListInsert(Lscore,3,s1);
    ListInsert(Lscore,5,s2);
    int len=Lscore.length;
    int s;
    for(i=1;i<=len;i++)
    {
        GetElem(Lscore,i,s); //获取线性表中数据 
        cout<<s<<endl;
    }
    return 0;
}