/*
 * @Description: 非递减线性有序表的合并
 * @Author: HailayLin
 * @Date: 2021-10-08 23:08:09
 * @LastEditTime: 2021-10-08 23:46:12
 * @FilePath: \Algorithm\Single_LinkList\S0214_非递减线性有序表合并.cpp
 */

/**
 * @brief 题目内容：
在S0213的基础上修改程序，完成两个非递减线性有序表的合并。
例1（第1、6行为输入）：
5 2 35
Show La:
2
5
35
676 1 324 64
Show Lb:
1
64
324
676
After Merging:
1
2
5
35
64
324
676
 请注意，main()函数必须按如下所示编写：
int main()
{
    //线性表的的初始化、插入、取值
    Sqlist La,Lb,Lc; //用来存储学生《数据结构》成绩
    InitList(La),InitList(Lb),InitList(Lc); //初始化线性表 
    CreateList_Up(La,3); //创建非递减链表 
    cout<<"Show La:"<<endl;
    Show(La); //遍历线性表 
    CreateList_Up(Lb,4);
    cout<<"Show Lb:"<<endl;
    Show(Lb);
    MergeList_Sq(La,Lb,Lc); //将两个线性表元素合并到Lc(非递减)
    cout<<"After Merging:"<<endl;
    Show(Lc); 
  
    return 0;
}

 * 
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
 * @brief 顺序表插入元素，从1开始插入
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
 * @brief 顺序表按元素序号取值
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

/**
 * @brief Create a List object
 * 
 * @param L Sqlist 顺序表
 * @param n 创建链表元素个数
 * @return Status 
 */
Status CreateList(Sqlist &L, int n)
{
    int in = 0;
    for (int i = 1; i <= n; i++ )
    {
        cin >> in;
        ListInsert(L, i, in);
    }
    return OK;
}

/**
 * @brief show a Sqlist
 * 数组从0开始输出，而元素是1开始
 * @param L 要输出的列表名称
 * @return Status 
 */
Status Show(Sqlist &L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.elem[i] << endl;
    }
    return OK;
}

/**
 * @brief La, Lb 无序表合并到 La
 * 
 * @param La 合并后的表和需要合并的表1
 * @param Lb 需要合并的表2
 * @return Status 
 */
Status MergeList(Sqlist &La, Sqlist &Lb)
{
    //1. 获取线性表长度La=m, Lb=n
    int m = La.length;
    int n = Lb.length;
    //2. 如果Lb[i]在La中没有找到，就加在La后面加上此元素
    ElemType e;
    for (int i = 1; i <= n; i++)
    {
        GetElem(Lb, i, e);
        if (!LocateElem(La, e)){
            ListInsert(La, ++m, e);
        }
    }
    return OK;
}

/**
 * @brief qsort用的比较函数，不太懂用法
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int compfunc(const void *a, const void *b)
{
    return ( *(int *)a - *(int *)b );
}

/**
 * @brief 创建非递减顺序表，输入无序，创建后有序
 * 
 * @param L 顺序表名称
 * @param n 顺序表元素个数
 * @return Status 
 */
Status CreateList_Up(Sqlist &L, int n)
{
    //1. 输入元素
    CreateList(L, n);
    //2. 表排序
    qsort(L.elem, L.length, sizeof(int), compfunc);
    return OK;
}


/**
 * @brief 合并非递减顺序表La，Lb到Lc
 * 
 * @param La 
 * @param Lb 
 * @param Lc 合并后顺序表
 * @return Status 
 */
Status MergeList_Sq(Sqlist &La, Sqlist &Lb, Sqlist &Lc)
{
    //0. Lc长度变化
    Lc.length = La.length + Lb.length;
    //1. pa, pb, pc 分别指向 La, Lb, Lc 第一个元素
    ElemType *pa = La.elem;
    ElemType *pb = Lb.elem;
    ElemType *pc = Lc.elem; 
    //2. pa, pb 未到队尾时依次比较 pa pb 所指元素值，从La或Lb中摘取较小元素到Lc最后
    ElemType *pa_last = La.elem+La.length-1;
    ElemType *pb_last = Lb.elem+Lb.length-1;
    while ( (pa <= pa_last) && (pb <= pb_last) )
    {
        if ( *pa <= *pb ) *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    //3. 将剩下元素全部插入到Lc
    while (pa <= pa_last) *pc++ = *pa++;
    while (pb <= pb_last) *pc++ = *pb++;
    return OK;
}

int main()
{
    //线性表的的初始化、插入、取值
    Sqlist La,Lb,Lc; //用来存储学生《数据结构》成绩
    InitList(La),InitList(Lb),InitList(Lc); //初始化线性表 
    CreateList_Up(La,3); //创建非递减链表 
    cout<<"Show La:"<<endl;
    Show(La); //遍历线性表 
    CreateList_Up(Lb,4);
    cout<<"Show Lb:"<<endl;
    Show(Lb);
    MergeList_Sq(La,Lb,Lc); //将两个线性表元素合并到Lc(非递减)
    cout<<"After Merging:"<<endl;
    Show(Lc); 
  
    return 0;
}