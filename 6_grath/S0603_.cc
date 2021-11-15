/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-11-15 11:10:38
 * @LastEditTime: 2021-11-15 11:46:49
 * @FilePath: \Algorithm\6_grath\S0603_.cc
 */

/**
 * @brief 题号：S0603        题目:无向图的深度优先搜索遍历（邻接表）        得分：0  
  
作业提交截止时间：2021/11/15 12:00:00	 
 	
题目内容：
在S0601的基础上修改程序，使用邻接表完成无向图的深度优先搜索遍历。
例1(只有最后2行为输出)：
3 2
ABC
AB
AC
ACB
BAC

例2（只有最后2行为输出）：
8 8
ABCDEFGH
AF
AB
BC
CG
GH
HD
DB
BE
ABEDHGCF
BEDHGCAF

 请注意，main()函数必须按如下所示编写：
int main()
{
    ALGraph G;
    CreateUDG(G); //采用邻接表创建无向图 
    DFS_AL(G,0); //深度优先搜索遍历无向图 
    cout<<endl;
    for(int i=0;i<G.vexnum;i++) visited[i]=0;
    if(G.vexnum>1) DFS_AL(G,1); 
    cout<<endl;
    return 0;
}
 * 
 */

#include<iostream>
using namespace std;

/** 网的相关信息、限制 **/
#define MaxInt 32767    // 等价无穷大值
#define MVNum 100   // 最大顶点数
typedef char VertexTYPE;    // 顶点用char存，可能是ABCD字符
typedef int ArcTYPE;    // 边的权值
typedef int OtherINFO;

/* 返回状态标识 */
typedef int Status; // 返回状态
#define OK 1
#define ERROR 0

/* 边节点 */
typedef struct ArcNode{
    int adjvex; // 该边（弧）指向的顶点vi下标i
    struct ArcNode *arcNext;    // 下一条还连在vex上的边
    OtherINFO info;
}ArcNode;

/* 顶点信息 */
typedef struct VexNode{
    VertexTYPE data;    // 节点的名字
    ArcNode *firstArc;  // 节点连接的第一条边
}VexNode, AdjList[MVNum];   // 构建表头节点表

/* 邻接表结构体 */
typedef struct ALGraph{
    AdjList vertices;   // 表头节点表
    int vexnum, arcnum; // 节点个数，边个数
}ALGraph;

bool visited[MVNum];

/**
 * @brief 定位节点在表头节点表的位置（数组下标）
 * 
 * @param G 
 * @param v 
 * @return int 
 */
int LocateVex(ALGraph G, VertexTYPE v)
{
    for (int i=0; i<G.vexnum; i++)
    {
        if (G.vertices[i].data == v) return i;
    }
    return 0;   // 这里应该抛出一个错误，但是没学cpp如何rasie……暂且留白
}

/**
 * @brief 领接表创建无向图
 * 
 * @param G 
 * @return Status 
 */
Status CreateUDG(ALGraph &G)
{
    // 1. 输入顶点个数和边条数
    cin >> G.vexnum >> G.arcnum;    
    
    // 2. 输入顶点信息
    for (int i=0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstArc = NULL;
    }

    // 3. 输入边信息
    int v1, v2; // 顶点的一条边两个点 char
    int i, j;   // 顶点一条边两个结点在表头节点表的下标
    for (int k=0; k<G.arcnum; k++)
    {
        // 3.1 输入信息并且定位数组下标位置
        cin >> v1 >> v2;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);

        // 3.2 创建节点v1-v2边并且以头插法插入到v1后
        ArcNode* p1 = new ArcNode;
        p1->adjvex = j;
        p1->arcNext = G.vertices[i].firstArc;
        G.vertices[i].firstArc = p1->arcNext;

        // 3.3 创建节点v2-v1边并且以头插法插入到v2后
        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->arcNext = G.vertices[j].firstArc;
        G.vertices[j].firstArc = p2;
    }
    return OK;
}

void DFS_AL(ALGraph G, int v)
{
    // 1. 输出当前节点信息
    cout << G.vertices[v].data;
    ArcNode *p = G.vertices[v].firstArc;

    // 2. 递归深度遍历
    int w;
    while(!p)
    {
        w = p->adjvex;
        if (!visited[w])
        {
            DFS_AL(G, w);
        }
        else p = p->arcNext;
    }
}

int main()
{
    ALGraph G;
    CreateUDG(G); //采用邻接表创建无向图 
    DFS_AL(G,0); //深度优先搜索遍历无向图 
    cout<<endl;
    for(int i=0;i<G.vexnum;i++) visited[i]=0;
    if(G.vexnum>1) DFS_AL(G,1); 
    cout<<endl;
    return 0;
}