/*
 * @Description:题目:无向图的深度优先搜索遍历（邻接矩阵）
 * @Author: HailayLin
 * @Date: 2021-11-09 19:59:00
 * @LastEditTime: 2021-11-24 22:26:23
 * @FilePath: \Algorithm\6_grath\S0601_UDN_DFS_Mx.cc
 */

/**
题目内容：
采用邻接矩阵表示无向图的深度优先搜索遍历。
例1（最后1行为输出，其他为输入）：
1 0
A
A

例2（最后2行为输出，其他为输入）：
4 4
ABCD
AB 1
AC 2
AD 3
CD 5
ABCD
BACD

 请注意，main()函数必须按如下所示编写：
int main()
{
    AMGraph G;
    CreateUDN(G);  //创建无向图的邻接矩阵
    DFS_AM(G,0); //深度优先搜索遍历图
    cout<<endl;
    for(int i=0;i<G.vexnum;i++) visited[i]=0;
    if(G.vexnum>1) DFS_AM(G,1);
    cout<<endl;
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
    int arcNum;
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
Status CreateUDN(AMGraph &G)
{
    //cout << "// 0.输入节点数边数" << endl;
    cin >> G.vexnum >> G.arcNum;

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
    for(int k=0; k<G.arcNum; k++)
    {
        //cout << "// 3.1 输入一条边依附的顶点v1 v2 w权值:";
        cin >> v1 >> v2 >> weight;
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        G.arcs[j][i] = G.arcs[i][j] = weight;
    }

    return 0;
}

/**
 * @brief 输出矩阵图
 */
Status ShowUDN(AMGraph &G)
{
    for(int i=0; i<G.vexnum; i++)
    {
        for(int j=0; j<G.vexnum; j++)
            cout << G.arcs[i][j] << "\t";
        cout << endl;
    }
    return OK;
}


bool visited[MVNum];
/**
 * @brief 邻接矩阵的深度优先遍历
 *
 * @param G
 * @param v 访问元素节点下标
 */
void DFS_AM(AMGraph G, int v)
{
    // 输出访问的节点
    cout << G.vexs[v];
    visited[v]=true;
    // 递归深度遍历
    for(int w=0; w<G.vexnum; w++)
    {
        if( G.arcs[v][w]!=0 && !visited[w])
            DFS_AM(G, w);
    }
}

int main()
{
    AMGraph G;
    CreateUDN(G);  //创建无向图的邻接矩阵
    DFS_AM(G,0); //深度优先搜索遍历图
    cout<<endl;
    for(int i=0;i<G.vexnum;i++) visited[i]=0;
    if(G.vexnum>1) DFS_AM(G,1);
    cout<<endl;
    return 0;
}