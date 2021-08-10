/**
 * @file S0203_Sequent_List_del.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-08-10
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * 题号：S0203        题目:线性表删除        得分：0  
  
作业提交截止时间：2022/1/20 0:00:00	 
 	
题目内容：
在S0202的基础上，添加线性表删除的功能。
例1（前2行为输入）：
88 99 75
2
delete success!
88
75

例2（前2行为输入）：
88 99 67
6
Error!
88
99
67
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
    
    int loc;
    cin>>loc; //输入要删除的位置
    if(ListDelete(Lscore,loc)==OK) cout<<"delete success!"<<endl;
    else cout<<"Error!"<<endl;
    
    for(i=1; i<=Lscore.length;i++) //遍历线性表 
    {
        int ele;
        GetElem(Lscore,i,ele);
        cout<<ele<<endl;
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

/**
 * 顺序表插入元素
 * @param L 顺序表
 * @param i 插入元素的元素序号
 * @param e 要插入元素的值
 * @return Status 0 地址非法or列表已满; 1 成功插入
 */
Status ListInsert(Sqlist &L, int i, ElemType e)
{
    //1.判断元素地址i是否非法
    if ( (i<1) || (i>L.length+1) ) return ERROR;
    //2.判断列表是否已满
    if ( L.length == MAXSIZE) return ERROR;
    //3.元素序号i后的元素向后移1个元素
    for (int j=L.length-1; j>=i-1; j--)         //j=数组下标,注意和ListDelete()中
    {                                           //的j为元素序号区分,或许j=数组下标,更好区分
        L.elem[j+1] = L.elem[j];                //从后往前移
    }
    //4.向元素序号i放入元素
    L.elem[i-1] = e;
    //5.顺序表长度+1
    ++L.length;
    return OK;
}


/**
 * 顺序表按元素序号取值
 * @param L 顺序表名
 * @param i 顺序表元素序号
 * @param e 按元素序号取得的元素值
 * @return Status 0 地址非法; 1 找到
 */
Status GetElem(Sqlist &L, int i, ElemType &e)
{
    //1.判断地址非法
    if ( (i<1) || (i>L.length) ) return ERROR;
    //2.获取值
    e = L.elem[i-1];
    return OK;
}


/**
 * 查找元素返回元素序号
 * @param L 顺序表 
 * @param e 需要查找的元素
 * @return int >0 找到的序号; 0 没有找到
 */
int LocateElem(Sqlist &L, ElemType e)
{
    for (int i = 1; i <= L.length; i++)  //i=元素序号,从前往后找
    {
        if (e == L.elem[i-1]) return i;
    }
    return ERROR;
}

/**
 * 顺序表删除元素
 * @param L 顺序表
 * @param i 要删除的元素的元素序号
 * @return Status 0 元素序号非法; 1 成功删除
 */
Status ListDelete(Sqlist &L, int i)
{
    //1.判断地址非法
    if ( (i<1) || (i>L.length+1) ) return ERROR;
    //2.被删除元素后的元素前移,若删的是最后就不用了.处理到倒数第二个元素
    for (int j = i; j <= L.length-1; j++)   //j=元素序号
    {
        L.elem[j-1] = L.elem[j];            //前一个元素=后一个元素
    }
    //3.顺序表长度-1,返回状态
    --L.length;
    return OK;
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
    
    int loc;
    cin>>loc; //输入要删除的位置
    if(ListDelete(Lscore,loc)==OK) cout<<"delete success!"<<endl;
    else cout<<"Error!"<<endl;
    
    for(i=1; i<=Lscore.length;i++) //遍历线性表 
    {
        int ele;
        GetElem(Lscore,i,ele);
        cout<<ele<<endl;
    } 

    return 0;
}