/*
 * @Description: 用类的方式，领接矩阵存储无向图
 * @Author: HailayLin
 * @Date: 2021-11-15 10:33:47
 * @LastEditTime: 2021-11-15 10:33:47
 * @FilePath: \Algorithm\6_grath\Class_UDN.cc
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

/* 用邻接表存储网的结构体定义 */
typedef struct AMGraph{
    // 顶点集
    VertexTpye vexs[MVNum];
    // 邻接矩阵
    ArcTpye arcs[MVNum][MVNum];
    // 网当前节点数
    int vexNum;
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
    for (int i=0; i<G.vexNum; i++)
    {
        if(v == G.vexs[i]) return i;
    }
    return ERROR;
}

/* 邻接矩阵表示创建无向网G */
Status CreateUDN(AMGraph &G)
{
    cout << "// 0.输入节点数边数" << endl;
    cin >> G.vexNum >> G.arcNum;

    cout << "// 1.存顶点信息到顶点表" << endl;
    for (int i=0; i<G.vexNum; i++)
        cin >> G.vexs[i];

    cout << "// 2.初始化邻接矩阵" << endl;
    for(int i=0; i<G.vexNum; i++)
        for(int j=0; j<G.vexNum; j++)
        {
            G.arcs[i][j]=MaxInt;
        }

    cout << "// 3.构建邻接矩阵"<< endl;
    VertexTpye v1, v2;
    ArcTpye weight;
    for(int k=0; k<G.arcNum; k++)
    {
        cout << "// 3.1 输入一条边依附的顶点v1 v2 w权值:";
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
    for(int i=0; i<G.vexNum; i++)
    {
        for(int j=0; j<G.vexNum; j++)
            cout << G.arcs[i][j] << "\t";
        cout << endl;
    }
    return OK;
}