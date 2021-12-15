/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-15 14:02:47
 * @LastEditTime: 2021-12-15 14:07:48
 * @FilePath: \Algorithm\6_grath\S0609_Floyd.cpp
 */
/**
 * 题号：S0609        题目:弗洛伊德算法（最短路径）        得分：100  
  
作业提交截止时间：2041/7/25 0:00:00	 
 	
题目内容：
利用邻接矩阵表示有向图，利用弗洛伊德算法求解从各顶点到达其他顶点的最短路径及路径长度。
例（前10行为输入）：
4 8
ABCD
AB 1
BC 2
DA 3
AC 4
DB 5
CD 6
DC 8
BD 9
Start:A
AA:0
AB:1
ABC:3
ABCD:9
Start:B
BCDA:11
BB:0
BC:2
BCD:8
Start:C
CDA:9
CDAB:10
CC:0
CD:6
Start:D
DA:3
DAB:4
DABC:6
DD:0

 请注意，main()函数必须按如下所示编写：
int main()
{
    int vnum,anum; //顶点数与边数
    cin>>vnum>>anum;
    AMGraph G;
    CreateUDN(G,vnum,anum);  //创建无向图的邻接矩阵(至少两个顶点) 
    ShortestPath_Floyd(G);
    
    return 0;
}
*/

#include<iostream>
using namespace std;

/** 网的相关信息、限制 **/
#define MaxInt 32767    // 等价无穷大值
#define MVNum 100   // 最大顶点数
typedef char VertexTpye;    // 顶点用char存，可能是ABCD字符
typedef int ArcTpye;    // 边的权值

/* 返回状态标识 */
typedef int Status; // 返回状态
#define OK 1
#define ERROR 0

/* 用邻接矩阵存储网的结构体定义 */
typedef struct AMGraph{
    // 顶点集
    VertexTpye vexs[MVNum];
    // 邻接矩阵
    ArcTpye arcs[MVNum][MVNum];
    // 网当前节点数
    int vexnum;
    // 网当前弧数
    int arcnum;
}AMGraph;

/**
 * @brief 获取顶点数组下标
 *
 * @param G
 * @param v 要寻找的顶点
 * @return int 顶点下标，从0开始
 */
int LocateVex(AMGraph &G, VertexTpye &v)
{
    for (int i=0; i<G.vexnum; i++)
    {
        if(v == G.vexs[i]) return i;
    }
    return ERROR;
}

/* 邻接矩阵表示创建无向网G */
Status CreateUDN(AMGraph &G, int vnum, int anum)
{
    //cout << "// 0.输入节点数边数" << endl;
    G.vexnum = vnum;
    G.arcnum = anum;
    //cin >> G.vexnum >> G.arcnum;

    //cout << "// 1.存顶点信息到顶点表" << endl;
    for (int i=0; i<G.vexnum; i++)
        cin >> G.vexs[i];

    //cout << "// 2.初始化邻接矩阵" << endl;
    for(int i=0; i<G.vexnum; i++)
        for(int j=0; j<G.vexnum; j++)
        {
            G.arcs[i][j]=MaxInt;
        }

   // cout << "// 3.构建邻接矩阵"<< endl;
    VertexTpye v1, v2;
    ArcTpye weight;
    for(int k=0; k<G.arcnum; k++)
    {
        //cout << "// 3.1 输入一条边依附的顶点v1 v2 w权值:";
        cin >> v1 >> v2 >> weight;
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        //G.arcs[j][i] =    // 要求有向图 
        G.arcs[i][j] = weight;
    }

    return 0;
}

/**
 * @brief 输出矩阵图
 */
Status ShowUDN(AMGraph &G)
{
    for(int i=0; i<G.vexnum; i++) {
        for(int j=0; j<G.vexnum; j++)
            if (G.arcs[i][j] == MaxInt) {
                cout << "∞\t";
            }
            else {
                cout << G.arcs[i][j] << "\t";
            }
        cout << endl;
    }
    return OK;
}

void ShortestPath_Floyd(AMGraph &G) {
    
}


int main()
{
    int vnum,anum; //顶点数与边数
    cin>>vnum>>anum;
    AMGraph G;
    CreateUDN(G,vnum,anum);  //创建无向图的邻接矩阵(至少两个顶点) 
    ShortestPath_Floyd(G);
    
    return 0;
}